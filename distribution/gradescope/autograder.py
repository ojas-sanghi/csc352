import json
import argparse
import os
import shutil
from typing import NamedTuple
import pprint
from datetime import datetime

from utilities import (
    GradescopeResults,
    GradescopeMetadata,
    read_metadata,
    GradescopeTest,
)


class TestInfo(NamedTuple):
    exe: str
    args: list[str]


class SuiteInfo(NamedTuple):
    submissions: list[str]
    make: list[str]
    tests: list[TestInfo]


def main():
    args = parseargs()
    config_dir: str = args.config_dir
    submission_dir: str = args.submission_dir
    gradescope_metadata: str = args.metadata
    root = args.root_dir
    working_dir: str = args.working_dir
    output = args.output

    change_working_dir(working_dir)

    # check if submission directory exists
    if not os.path.isdir(submission_dir):
        print(f"Submission directory {submission_dir} not found")
        exit(1)

    metadata: GradescopeMetadata = get_gradescope_metadata(gradescope_metadata)
    # check if config directory exists
    config_dir: str = update_config_dir(config_dir, root, metadata)
    pprint.pprint(config_dir)
    suites: list[SuiteInfo] = get_config_data(config_dir)

    passed: bool = True
    tests: list[GradescopeTest] = []
    suite: SuiteInfo
    for suite in suites:
        ts: list[GradescopeTest]
        pss: bool
        ts, pss = do_suite(
            submission_dir, suite.submissions, suite.make, config_dir, suite.tests
        )
        passed = passed and pss
        tests.extend(ts)

    results: GradescopeResults
    score: float
    results, score = create_results(tests, passed)
    apply_extra_credit(metadata, results, score)
    emit_output(output, results)


def emit_output(output: str, results: GradescopeResults):
    if output:
        results.write_results(output)
    else:
        print(results.to_json())


def apply_extra_credit(
    metadata: GradescopeMetadata, results: GradescopeResults, score: float
):
    if metadata:
        due = metadata.assignment.due_date
        submitted = metadata.created_at
        # compute minutes between due and submitted

        format = "%Y-%m-%dT%H:%M:%S.%f%z"
        dtime = datetime.strptime(due, format)
        stime = datetime.strptime(submitted, format)
        minutes = (dtime - stime).total_seconds() / 60
        if minutes > 0:
            xtra = minutes / 1000
        else:
            xtra = minutes / 1
        xtra = min(xtra, 10)
        score += xtra
        score = min(score, 110)
        score = max(score, 0)
        results.score = score


def create_results(
    tests: list[GradescopeTest], passed: bool
) -> tuple[GradescopeResults, float]:
    results = GradescopeResults({})
    results.tests = tests
    if not passed:
        score = 0.0
    else:
        passing = sum(
            1 for test in tests if test.status == "passed" and "PASS" in test.name
        )
        failing = len([test for test in tests if test.status == "failed"])
        score = passing / (passing + failing) * 100
        results.output = f"{passing} tests passed, {failing} tests failed"

    results.score = score
    return results, score


def get_config_data(config_dir: str) -> list[SuiteInfo]:
    if not os.path.isdir(config_dir):
        print(f"Config directory {config_dir} not found")
        exit(1)
    retval = []
    # check if config file exists
    config = os.path.join(config_dir, "gradescope.json")
    if not os.path.isfile(config):
        print(f"Config file {config} not found")
        exit(1)
    with open(config) as f:
        mdata = json.load(f)
        tests = mdata["tests"]
        retval: list[SuiteInfo] = [
            SuiteInfo(
                x["submissions"],
                x["make"],
                [TestInfo(y["exe"], y["args"]) for y in x["tests"]],
            )
            for x in tests
        ]

    return retval


def update_config_dir(config_dir: str, root: str, metadata: GradescopeMetadata) -> str:
    if not config_dir:
        if not root:
            print("No config or directory specified")
            exit(1)
        if not os.path.isdir(root):
            print(f"Root directory {root} not found")
            exit(1)
        topconfig = os.path.join(root, "gradescope.json")
        if not os.path.isfile(topconfig):
            print(f"Top-level config file {topconfig} not found")
            exit(1)
        with open(topconfig) as f:
            tdata: dict[str, str] = json.load(f)
        title: str = metadata.assignment.title
        if title in tdata:
            config_dir = os.path.join(root, tdata[title])
        else:
            print(f"Config directory for '{title}' not found in {tdata}")
            exit(1)
    return config_dir


def change_working_dir(working_dir: str):
    if working_dir:
        if not os.path.isdir(working_dir):
            print(f"Working directory {working_dir} not found")
            exit(1)
        os.chdir(working_dir)


def get_gradescope_metadata(gradescope_metadata: str) -> GradescopeMetadata:
    meta: GradescopeMetadata = read_metadata(gradescope_metadata)
    return meta
    # metadata: dict[str, Any] = {}
    # if gradescope_metadata:
    #     if not os.path.isfile(gradescope_metadata):
    #         print(f"Metadata file {gradescope_metadata} not found")
    #         exit(1)
    #     with open(gradescope_metadata) as f:
    #         metadata = json.load(f)
    # return metadata


def do_suite(
    submission_dir: str,
    submissions: list[str],
    makes: list[str],
    config_dir: str,
    testscripts: list[TestInfo],
) -> tuple[list[GradescopeTest], bool]:
    tests: list[GradescopeTest] = []
    passed: bool
    passed = copy_files(submission_dir, submissions, tests)
    if passed:
        passed = make(config_dir, makes, tests)
        if passed:
            test(config_dir, testscripts, tests)
            passed = True
    return tests, passed


def test(config_dir: str, testscripts: list[TestInfo], tests: list[GradescopeTest]):
    testdict: TestInfo
    for testdict in testscripts:
        # capture stdout and stderr
        exe = testdict.exe
        if exe[0] == "$":
            testexe = os.path.join(config_dir, exe[1:])
        else:
            testexe = exe
        if not os.path.isfile(testexe):
            print(f"Test executable {testexe} not found")
            exit(1)
        args: list[str] = []
        for arg in testdict.args:
            if arg[0] == "$":
                testarg = os.path.join(config_dir, arg[1:])
                if not os.path.exists(testarg):
                    print(f"Test argument {testarg} not found")
                    exit(1)
            else:
                testarg = arg

            args.append(testarg)

        import subprocess

        stdo = subprocess.PIPE
        stde = subprocess.PIPE
        cmd: list[str] = [testexe] + args
        # print(f"Running {cmd}")
        result = subprocess.run(cmd, stdout=stdo, stderr=stde)

        results = result.stdout.decode("utf-8")

        print("--- stdout")
        print(result.stdout.decode("utf-8"))
        print("--- stderr")
        print(result.stderr.decode("utf-8"))
        print("---")

        # count "PASS" and "FAIL" in results
        lines = results.splitlines()
        for line in lines:
            if "PASS" in line:
                tests.append(GradescopeTest({"name": f"{line}", "status": "passed"}))
            elif "FAIL" in line:
                tests.append(GradescopeTest({"name": f"{line}", "status": "failed"}))


def make(config_dir: str, makes: list[str], tests: list[GradescopeTest]):
    mk: str
    for mk in makes:
        mk = mk.replace("$", config_dir + "/")
        status: int = os.system(mk)
        if status == 0:
            tests.append(GradescopeTest({"name": f"{mk}", "status": "passed"}))
        else:
            tests.append(GradescopeTest({"name": f"{mk} FAILED", "status": "failed"}))
            return False
    return True


def copy_files(
    submission_dir: str,
    submissions: list[str],
    tests: list[GradescopeTest],
):
    submission: str
    for submission in submissions:
        # check if file exists in current directory
        filename = os.path.join(submission_dir, submission)
        if os.path.isfile(filename):
            dst = os.getcwd()
            try:
                shutil.copy(filename, dst)
            except shutil.SameFileError:
                pass
            tests.append(
                GradescopeTest({"name": f"{submission} found", "status": "passed"})
            )
        else:
            tests.append(
                GradescopeTest({"name": f"{submission} not found", "status": "failed"})
            )
            return False
    return True


def parseargs():
    parser = argparse.ArgumentParser()
    parser.add_argument("--config_dir", type=str, default="")
    parser.add_argument("--root_dir", type=str, default="")
    parser.add_argument("--submission_dir", type=str, required=True)
    parser.add_argument("--working_dir", type=str)
    parser.add_argument("--output", type=str, default="")
    parser.add_argument("--metadata", type=str, default="")
    args = parser.parse_args()
    return args


if __name__ == "__main__":
    main()
