# 控制台打印错误信息
def print_error(info: str):
    print("[\033[31mERROR\033[0m] " + info)


# 控制台打印成功信息
def print_success(info: str):
    print("[\033[32mERROR\033[0m] " + info)


# 控制台打印警告信息
def print_warning(info: str):
    print("[\033[33mWARNING\033[0m] " + info)
    

# 控制台打印信息
def print_info(info: str):
    print("[\033[34mINFO\033[0m] " + info)


# 打印错误信息并退出
def exit_error(info: str):
    print_error(info)
    exit(1)
