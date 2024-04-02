#!/bin/bash

# Usage: correct.sh <executable> <testcase>

executable=$1
testcase=$2
basedir=$(dirname "$testcase")
basename=$(basename "$testcase")
basename="${basename%.*}"

echo "basedir: $basedir"
echo "basename: $basename"
echo "executable: $executable"
echo "testcase: $testcase"

if [ ! -x "$executable" ]; then
    echo "Executable $executable not found"
    exit 1
fi

if [ ! -f "$testcase" ]; then
    echo "Testcase $testcase not found"
    exit 1
fi

expectedout="$basedir/$basename".stdout.expected
expectederr="$basedir/$basename".stderr.expected

echo "Running $executable" on "$testcase"
$executable < "$testcase" > "$expectedout" 2> "$expectederr"
