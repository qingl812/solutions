#!/bin/bash
source scripts/functions.sh

# 参数为 [all|number]
if [ $# -ne 1 ]; then
    exit_with_error "Usage: $0 [all|number]"
fi

# 获取参数 all
if [ "$1" == "all" ]; then
    bash scripts/build.sh -1 leetcode
else
    bash scripts/build.sh $1 leetcode
fi
