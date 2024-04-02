#!/bin/bash

dirs=( fully minimal read )

for part in "${dirs[@]}"
do
    dir=tests.$part
    echo "Creating directory $dir"
    mkdir -p $dir
    for depth in {1..4} ; do
	    # compute depth cubed
	    d3=$((depth*depth*depth))
	    for i in `seq 1 $d3` ; do
			padded=$(printf "%01d%02d" $depth $i)
			n=t$padded.stdin
			echo "Creating file $n"
			python3 gen.py --maxdepth $depth > $dir/$n
	    done
    done
done


