# 构建

本项目使用 vcpkg 来使用 gtest 库，请在 vscode 的 setting 中添加如下配置

```json
{
  "cmake.configureSettings": {
    "CMAKE_TOOLCHAIN_FILE": "C:/ProgramGreen/vcpkg/scripts/buildsystems/vcpkg.cmake"
  }
}
```

# gtest 使用技巧

运行指定测试，而不是全部测试

```c++
  ::testing::GTEST_FLAG(filter) = "a.*";
```
