#!/bin/bash

# Usage: doall.sh <executable> <script> <results_dir> tests...

if [ $# -lt 3 ]; then
    echo "Usage: $0 <executable> <script> <results_dir> tests..."
    exit 1
fi

executable=$1
script=$2
destdir=$3

if [ ! -x "$executable" ]; then
    echo "Executable $executable not found"
    exit 1
fi

if [ ! -f "$script" ]; then
    echo "Script $script not found"
    exit 1
fi

if [ ! -d "$destdir" ]; then
    mkdir -p "$destdir"
fi

shift 3

for testcase in "$@"; do 
    # echo "Running $script" on "$executable" "$testcase"
    $script "$executable" "$testcase" "$destdir"
done