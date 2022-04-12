#!/bin/bash

source scripts/init.sh

# print error
function print_error() {
    printf "[\033[31mERROR\033[0m] "
    printf "$1\n"
}

# print success
function print_success() {
    printf "[\033[32mSUCCESS\033[0m] "
    printf "$1\n"
}

# print info
function print_info() {
    printf "[\033[33mINFO\033[0m] "
    printf "$1\n"
}

# exit with error
function exit_with_error() {
    print_error "$1"
    print_info "run \033[34mcat ${log_file}\033[0m to view the error message"
    exit 1
}

# run no error
function run_no_error() {
    $1 >>${log_file}
    if [ $? -ne 0 ]; then
        exit_with_error "$1"
    fi
}

# mkdir if not exist
function mkdir_if_not_exist() {
    if [ ! -d $1 ]; then
        mkdir $1
    fi
}

# run no error no log
function run_no_error_no_log() {
    $1
    if [ $? -ne 0 ]; then
        exit 1
    fi
}
