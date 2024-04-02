#!/bin/bash

# Usage: test.sh <executable> <testdir>

if [ $# -ne 2 ]; then
    echo "Usage: $0 <executable> <testdir>"
    exit 1
fi

executable=$1
testdir=$2
assigndir=$(dirname "$0")
script="$assigndir/../../bin/check.sh"

# echo "executable: $executable"
# echo "script: $script"

if [ ! -x "$executable" ]; then
    echo "FAIL: Executable $executable not found"
    exit 1
fi

if [ ! -f "$script" ]; then
    echo "FAIL: Script $script not found"
    exit 1
fi

if [ ! -d "$testdir" ]; then
    echo "FAIL: Test directory $assigndir/$testdir not found"
    exit 1
fi

for testcase in "$testdir/"*.stdin; do 
    # echo "--- Running $script" on "$executable" "$testcase"
    $script $executable $testcase
done