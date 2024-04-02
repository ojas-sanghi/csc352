#!/bin/bash

dirs=( "column_major" "row_major" "right_justified" "variable_width")

for part in "${dirs[@]}"
do
    dir=tests.$part
    echo "Creating directory $dir"
    mkdir -p $dir
    for i in {1..10} ; do
        padded=$(printf "%02d" $i)
        n=t0$padded.stdin
        echo "Creating file $n"
        seq 1 $i > $dir/$n
    done
done


