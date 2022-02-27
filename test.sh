#!/bin/bash

file=$(find ./leetcode -name $1_*.cc)
echo ${file}
cp ${file} ./test/solution.cc

if [[ $? -ne 0 ]]; then
    printf "no such file!\n"
    exit 0
fi

cd test
cmake -S . -B build -G "MinGW Makefiles"
cmake --build build
cd build && ctest
cd ../../