#!/bin/bash

detab=tests.detab
wc=tests.wc
fold=tests.fold

for i in {100..150} ; do
    echo "Creating file $i"
    python3 rnd.py --tabs 2 > $detab/t$i.stdin
    python3 rnd.py          >    $wc/t$i.stdin
    python3 rnd.py          >  $fold/t$i.stdin
done

