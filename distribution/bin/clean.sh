#!/bin/bash

rm -f *.out *.err *.diff

if [ "$1" == "EXPECTED" ]; then
    rm -f *.out.expected *.err.expected
fi