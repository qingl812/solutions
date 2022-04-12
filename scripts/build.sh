#!/bin/bash
source scripts/functions.sh

# 该文件需要的参数，位置固定且不可或缺
# build.sh [n] [path] [path] ...
# 移动文件 path/n*.cc 到 test/src 下以编译运行
# 如果 n == -1 则移动所有文件到 test/src 下

# init
init
# clean test/src
rm -rf ${src_dir}/*

# move files to test/src
if [ $1 == "-1" ]; then
    # 如果 n == -1 则移动所有文件到 test/src 下
    find_name=*.cc
else
    find_name=$1_*.cc
fi
shift 1
find_dir=$*
# 存在文件夹 find_dir
for folder in ${find_dir}; do
    if [ ! -d ${folder} ]; then
        exit_with_error "folder \033[33m${folder}\033[0m does not exist."
    fi
done

# 统计文件数量
find_file_number=`find ${find_dir} -name ${find_name} | wc -l`
if [ ${find_file_number} -eq 0 ]; then
    # 如如果文件数量为 0 则打印没找到文件
    exit_with_error ${find_name}" file not found"
    
    elif [ ${find_file_number} -eq 1 ]; then
    # 如如果文件数量为 1 则打印出文件名
    find_res=`find ${find_dir} -name ${find_name}`
    print_info "find file: ${find_res}"
    
else
    # 否则打印文件数量
    print_info "find ${find_file_number} files."
fi
# 复制文件到 src_dir
find ${find_dir} -name ${find_name} -print0 | xargs -0 cp -t ${src_dir}
# 执行失败则退出
if [ $? -ne 0 ]; then
    exit_with_error "copy files failed."
fi

# cmake
run_no_error_no_log "bash scripts/cmake.sh"

# Execute the generated program
${exe_filename}
if [ $? -ne 0 ]; then
    print_error "${exe_filename} return code is $?"
    exit 1
fi
