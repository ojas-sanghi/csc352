#!/bin/bash

dirs=( build search remove_min delete )

for part in "${dirs[@]}"
do
    dir=tests.$part
    echo "Creating directory $dir"
    mkdir -p $dir
    for i in {0..49} ; do
        padded=$(printf "%02d" $i)
        n=t1$padded.stdin
        echo "Creating file $n"
        python3 gen.py --lines $i --words 2 --max 29 > $dir/$n
    done
done


