#!/bin/bash

mp=$1

if [ -d "./$mp" ]; then
    echo "Directory $mp already exists"
    exit
else
    mkdir "$mp"
    mkdir "$mp/output"
    mkdir "$mp/tests"
    mkdir "$mp/src"
    touch "$mp/src/$mp.c"
    program_code=`echo "$mp" | tr [:lower:] [:upper:]`
    echo "/* $program_code by Joe Biggins for CS:3620 */" >> "$mp/src/$mp.c"

    wget -O "$PWD/$mp/README.html" "http://homepage.divms.uiowa.edu/~jones/opsys/hw/$mp.shtml"
    cat "$PWD/$mp/README.html" | html2text > "$PWD/$mp/README.txt"
    rm "$PWD/$mp/README.html"
fi

