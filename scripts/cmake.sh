#!/bin/bash
source scripts/functions.sh

# run cmake
print_info "Running cmake..." >>${log_file}
run_no_error "cmake -S . -B ${build_dir}"
run_no_error "cmake --build ${build_dir}"
