#!/bin/bash

file=$(find ./leetcode -name $1_*.cc)
echo ${file}
cp "${file}" ./test/solution.cc

if [[ $? -ne 0 ]]; then
    printf "no such file!\n"
    exit 0
fi

cmake -S . -B build
cmake --build build
if [[ $? -ne 0 ]]; then
    printf "build failed!\n"
    exit 0
fi
./build/test/DeBug/solution-test.exe
