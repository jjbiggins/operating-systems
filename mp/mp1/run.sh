#!/bin/bash

testdir="$PWD/test"
srcdir="$PWD/src"
outputdir="$PWD/output"
program=`basename $PWD`

cd $srcdir
gcc "$program.c" -o "$program"


for test in $testdir/*
do
    test_basename=`basename $test`
    cat "$test" | "./$program" | tee "$outputdir/output_$test_basename" 
    
    exit_code=`diff -q mp1.c "$test" | grep -vq differ`
    if $exit_code; then
        echo "$test_basename : PASSED"
    else
        echo "$test_basename : FAILED"
    fi
done
