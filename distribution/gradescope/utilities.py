from typing import Any
import json


# https://gradescope-autograders.readthedocs.io/en/latest/specs/
# https://gradescope-autograders.readthedocs.io/en/latest/submission_metadata/


class GradescopeTest:
    score: float
    max_score: float
    status: str
    name: str
    name_format: str
    number: int
    output: str
    output_format: str
    tags: list[str]
    visibility: str
    extra_data: Any

    def __init__(self, d: dict[str, Any]) -> None:
        for k, v in d.items():
            setattr(self, k, v)

    def marshal(self) -> dict[str, Any]:
        return {k: v for k, v in self.__dict__.items() if not k.startswith("_")}


class GradescopeLeader:
    name: str
    value: float | str
    order: str

    def __init__(self, d: dict[str, Any]) -> None:
        for k, v in d.items():
            setattr(self, k, v)

    def marshal(self) -> dict[str, Any]:
        return {k: v for k, v in self.__dict__.items() if not k.startswith("_")}


class GradescopeResults:
    score: float
    output: str
    execution_time: int
    visibility: str
    output_format: str
    test_output_format: str
    test_name_format: str
    stdout_visibility: str
    extra_data: Any
    tests: list[GradescopeTest]
    leaderboard: list[GradescopeLeader]

    def __init__(self, d: dict[str, Any]) -> None:
        for k, v in d.items():
            match k:
                case "tests":
                    setattr(self, k, [GradescopeTest(x) for x in v])
                case "leaderboard":
                    setattr(self, k, [GradescopeLeader(x) for x in v])
                case _:
                    setattr(self, k, v)

    def marshal(self) -> dict[str, Any]:
        retval: dict[str, Any] = {}
        for k, v in self.__dict__.items():
            if not k.startswith("_"):
                if k == "tests":
                    retval[k] = [x.marshal() for x in v]
                elif k == "leaderboard":
                    retval[k] = [x.marshal() for x in v]
                else:
                    retval[k] = v
        return retval

    def to_json(self) -> str:
        return json.dumps(self.marshal(), indent=4)

    def write_results(self, fname: str) -> None:
        with open(fname, "w") as f:
            json.dump(self.marshal(), f, indent=4)
            f.write("\n")


class GradescopeSubmission:
    submission_time: str
    score: float
    results: GradescopeResults

    def __init__(self, d: dict[str, Any]) -> None:
        for k, v in d.items():
            match k:
                case "results":
                    setattr(self, k, GradescopeResults(v))
                case _:
                    setattr(self, k, v)

    # no need to marshal


class GradescopeUser:
    id: str
    email: str
    name: str

    def __init__(self, d: dict[str, Any]) -> None:
        for k, v in d.items():
            setattr(self, k, v)

    # no need to marshal


class GradesScopeAssignment:
    due_date: str
    group_size: int
    group_submission: bool
    id: str
    course_id: str
    late_due_date: str
    release_date: str
    title: str
    total_points: str

    def __init__(self, d: dict[str, Any]) -> None:
        for k, v in d.items():
            setattr(self, k, v)

    # no need to marshal


class GradescopeMetadata:
    id: str
    created_at: str
    assignment: GradesScopeAssignment
    submission_method: str
    users: list[GradescopeUser]
    previous_submissions: list[GradescopeSubmission]

    def __init__(self, d: dict[str, Any]) -> None:
        for k, v in d.items():
            match k:
                case "assignment":
                    setattr(self, k, GradesScopeAssignment(v))
                case "users":
                    setattr(self, k, [GradescopeUser(x) for x in v])
                case "previous_submissions":
                    setattr(self, k, [GradescopeSubmission(x) for x in v])
                case _:
                    setattr(self, k, v)

    # no need to marshal metadata


def read_metadata(
    fname: str,
) -> GradescopeMetadata:
    with open(fname, "r") as f:
        return GradescopeMetadata(json.load(f))
