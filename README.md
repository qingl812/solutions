# solitions

- 这是一个用于刷题的项目, 使用 gtest 进行单元测试
- 执行 `bash build.sh n` 命令会复制形如 `n_*.cc` 的文件到 `test/solution.cc` 编译运行
- 调试可以单独打开 test 文件夹编译运行
- 从 `template/0_template.cc` 文件获取模板文件
- `test/include` 中 `common.h` 包含了大部分常用头文件，其他文件是一些自定义的类型

## 注意事项

- 使用 vscode 时，建议把默认构建目录设置为 .vscode/build, 以避免和 build.sh 的构建冲突
- 使用 vscode 时，如果提示包含文件错误，请修改 `c_cpp_properties.json` 文件，

```conf
"includePath": [
"${default}",
".vscode/build/_deps/googletest-src/googletest/include",
"include"
],
```

## 未解决的问题

## 已解决，但没解决官方题解

- [189\_轮转数组](https://leetcode-cn.com/problems/rotate-array/) 解法二
- [542_01 矩阵](https://leetcode-cn.com/problems/01-matrix/)
- [77\_组合](https://leetcode-cn.com/problems/combinations/)
- [432\_全 O(1) 的数据结构](https://leetcode-cn.com/problems/all-oone-data-structure/)
