from ast import arg
import os
import sys
import tools

# 给定参数 <all|number> <folder_target> <folder_source> ...


# 参数校验
def check_args(args):
    # 参数至少为4个
    if len(sys.argv) < 4:
        tools.print_error("wrong number of parameters")
        return False

    # 第一个为 all 或 正整数
    if not (sys.argv[1].strip() == "all" or
            (sys.argv[1].isdigit() and int(sys.argv[1]) >= 0)):
        tools.print_error("parameter 1 error")
        return False

    # 第二个为可能不存在的文件夹 <folder_target>
    if not os.path.isdir(sys.argv[2]):
        os.mkdir(sys.argv[2])

    # 第三个后面都是必须存在的文件夹
    for i in range(3, len(sys.argv)):
        if not os.path.isdir(sys.argv[i]):
            tools.exit_error("parameter 3 error: " +
                             sys.argv[i] + " folder does not exist")
    return True


# 参数错误退出程序
if not check_args(sys.argv):
    tools.exit_error(
        "Usage: build.py <all|number> <folder_target> <folder_source> ...")

# 删除 <folder_target> 中的所有文件
for root, dirs, files in os.walk(sys.argv[2]):
    for file in files:
        os.remove(os.path.join(root, file))
# 执行复制文件操作
for i in range(3, len(sys.argv)):
    os.system("python scripts/src_move.py " +
              sys.argv[1] + " " + sys.argv[i] + " " + sys.argv[2])

# 执行编译操作
build_dir = "build"
# 如果 build_dir 文件夹不存在
if not os.path.isdir(build_dir):
    os.mkdir(build_dir)
# cmake
os.system("cmake -S . -B " + build_dir)
os.system("cmake --build " + build_dir)

# 执行程序
os.system(".\\" + build_dir + "\\test\\Debug\\solution-test.exe")
