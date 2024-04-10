#!/bin/bash

# Usage: check.sh <executable> <testcase>

if [ $# -ne 2 ]; then
    echo "Usage: $0 <executable> <testcase>"
    exit 1
fi

executable=$1
testcase=$2
basedir=$(dirname "$testcase")
base=$(basename "$testcase" .stdin)

testdir=${basedir##*/}
destdir="./results/$testdir"


expectedout="$basedir/$base.stdout.expected"
expectederr="$basedir/$base.stderr.expected"

# echo "executable: $executable"
# echo "testcase: $testcase"
# echo "expectedout: $expectedout"
# echo "expectederr: $expectederr"

if [ ! -x "$executable" ]; then
    echo "Executable $executable not found"
    exit 1
fi

if [ ! -f "$testcase" ]; then
    echo "Testcase $testcase not found"
    exit 1
fi

basedir=$(dirname "$base")
basename=$(basename "$base")    

if [ ! -d "$destdir" ]; then
    mkdir -p "$destdir"
fi

cp "$expectedout" "$expectederr" "$destdir"

stdout=$destdir/$basename.stdout
stderr=$destdir/$basename.stderr
outdiff=$destdir/$basename.stdout.diff
errdiff=$destdir/$basename.stderr.diff


echo "--- Running $executable" on "$testcase"
$executable < "$testcase" > "$stdout" 2> "$stderr"

if [ $? -ne 0 ]; then
    echo "FAIL: Execution failed: main did not return 0: $executable $testcase"
    exit 1
fi

if [ ! -f "$stdout" ]; then
    echo "FAIL: Output file $stdout not found: $executable $testcase"
    exit 1
fi

if [ ! -f "$stderr" ]; then
    echo "FAIL: Error file $stderr not found: $executable $testcase"
    exit 1
fi

if [ ! -f "$expectedout" ]; then
    if [ ! -z "$stdout" ]; then
        echo "FAIL: $stdout should be empty: $executable $testcase"
        exit 1
    fi
else
    diff "$stdout" "$expectedout" > "$outdiff"

    if [ $? -ne 0 ]; then
        echo "FAIL: stdout mismatch: $executable $testcase"
        exit 1
    fi
fi

if [ ! -f "$expectederr" ]; then
    if [ ! -z $stderr ]; then
        echo "FAIL: $stderr should be empty: $executable $testcase"
        exit 1
    fi
else
    diff "$stderr" "$expectederr" > "$errdiff"

    if [ $? -ne 0 ]; then
        echo "FAIL: stderr mismatch: $executable $testcase"
        exit 1
    fi
fi

echo "PASS: $executable $testcase"