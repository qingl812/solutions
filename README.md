# solitions

> 这是一个用于刷题的项目, 使用 gtest 进行单元测试

- `bash build.sh n` ，编译运行形如 `n_*.cc` 的文件
- `bash build.sh all` ，编译运行所有 `*.cc` 文件
- 调试请在 test 文件夹中加入断点
- 从 `sample/0_sample.cc` 文件获取模板文件
- `include` 中 `common.h` 包含了大部分常用头文件，其他文件是一些自定义的类型

## 注意事项

- 使用 vscode 时，建议把默认构建目录设置为 .vscode/build, 以避免和 build.sh 的构建冲突
- 使用 vscode 时，如果提示包含文件错误，请修改 `c_cpp_properties.json` 添加 inlcude 文件，如果还是头文件错误请删除 `intelliSenseMode` 配置项

  ```conf
  "includePath": [
  "${default}",
  ".vscode/build/_deps/googletest-src/googletest/include",
  "include"
  # del
  # "intelliSenseMode": "windows-msvc-x64"
  ],
  ```

- 中文乱码问题，使用 `chcp` 检查代码页是否为 `65001`，如果不是请修改，(注：`chcp 65001` 命令是无法解决此问题的) [参考链接](https://stackoverflow.com/questions/57131654/using-utf-8-encoding-chcp-65001-in-command-prompt-windows-powershell-window)
  > `code $PROFILE` 并把下列代码添加到末尾 `$OutputEncoding = [console]::InputEncoding = [console]::OutputEncoding = New-Object System.Text.UTF8Encoding`


## 未解决的问题

## 已解决，但没解决官方题解

- [189\_轮转数组](https://leetcode-cn.com/problems/rotate-array/) 解法二
- [542_01 矩阵](https://leetcode-cn.com/problems/01-matrix/)
- [77\_组合](https://leetcode-cn.com/problems/combinations/)
- [432\_全 O(1) 的数据结构](https://leetcode-cn.com/problems/all-oone-data-structure/)
