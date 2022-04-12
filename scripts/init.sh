#!/bin/bash

build_dir="build"
log_file=${build_dir}/log.txt
src_dir="test/src"
exe_filename=${build_dir}/test/Debug/solution-test.exe

# init
function init() {
    # mkdir if not exist
    if [ ! -d ${build_dir} ]; then
        mkdir ${build_dir}
    fi
    
    # remove old log file
    if [ -f ${log_file} ]; then
        rm ${log_file}
    fi
}

# clean
function clean() {
    # remove old log file
    if [ -f ${log_file} ]; then
        rm ${log_file}
    fi
    
    # remove old build directory
    if [ -d ${build_dir} ]; then
        rm -rf ${build_dir}
    fi
}
