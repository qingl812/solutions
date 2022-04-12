#!/bin/bash

# 参数为 [all|number]

# 如果参数个数不等于1
if [ $# -ne 1 ]; then
    echo "Usage: $0 [all|clean|number]"
    exit 1
fi

# 如果参数是 clean
if [ $1 == "clean" ]; then
    echo "clean"
    rm -rf build
    exit 0
fi

python scripts/build.py $1 test/src leetcode template
