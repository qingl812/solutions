import sys
import os
import re
import tools

# 给定参数 <file_name_number> <folder_source> <folder_target>
# 将 <folder_source> 中的 <file_name_number>_*.cc
# 文件拷贝到 <folder_target> 中
# 同时向 <file_name_number>_*.cc 文件添加命名空间
# 如果 <file_name_number> 为 all，则拷贝所有文件


# 参数校验
def check_args(args):
    # 参数为4个
    if len(sys.argv) != 4:
        tools.print_error("wrong number of parameters")
        return False

    # 第一个为 all 或 正整数
    if not (sys.argv[1].strip() == "all" or
            (sys.argv[1].isdigit() and int(sys.argv[1]) >= 0)):
        tools.print_error("parameter 1 error")
        return False

    # 第二个,第三个为存在的文件夹
    if not os.path.isdir(sys.argv[2]):
        tools.print_error("parameter 2 error")
        return False
    if not os.path.isdir(sys.argv[3]):
        tools.print_error("parameter 3 error")
        return False

    return True


# 参数错误退出程序
if not check_args(sys.argv):
    tools.exit_error(
        "Usage: src_move.py <all|number> <folder_source> <folder_target>")

# 获取参数
file_name_number = sys.argv[1]
folder_source = sys.argv[2]
folder_target = sys.argv[3]

# 文件名应符合的正则表达式
if file_name_number == "all":
    file_name_pattern = re.compile(r'^[0-9]*_.*\.cc$')
else:
    file_name_pattern = re.compile(r'^' + str(file_name_number) + '_.*\.cc$')

# 列出文件夹中的所有文件
file_count = 0  # 统计文件数量
for root, dirs, files in os.walk(folder_source):
    # root 表示当前正在访问的文件夹路径
    # dirs 表示该文件夹下的子目录名list
    # files 表示该文件夹下的文件list

    # 遍历所有文件
    # 向其中添加命名空间
    for file in files:
        # 判断文件名是否符合要求
        if re.match(file_name_pattern, file):
            file_count += 1
            source_path = os.path.join(root, file)
            target_path = os.path.join(folder_target, file)

            # 打开文件
            ifile = open(source_path, 'rb')
            file_content = ifile.read().decode("utf-8")
            ifile.close()

            # 添加命名空间
            pos = file_content.rfind("#include")
            if pos == -1:
                pos = 0
            else:
                pos = file_content.find("\"", pos + 1)
                pos = file_content.find("\"", pos + 1) + 1
            file_content = "// " + source_path + "\n" + \
                file_content[:pos] + \
                "\n\nnamespace {" + \
                file_content[pos:] + \
                "\n} // namespace\n"

            # 判断 folder_target 下没有 target_path 文件
            same_file = 0
            new_file_name = target_path
            while os.path.exists(new_file_name):
                new_file_name = target_path[:-3]+"_"+str(same_file)+".cc"
                same_file += 1
            target_path = new_file_name

            # 写入文件
            ofile = open(target_path, 'wb')
            ofile.write(file_content.encode("utf-8"))
            ofile.close()
