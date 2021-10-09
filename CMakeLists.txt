# CMakeLists.txt
cmake_minimum_required(VERSION 3.0)
project(leetcode-sol VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

# gtest
find_package(GTest CONFIG REQUIRED)

add_executable(leetcode-sol "main.cpp")

# gtest
target_link_libraries(leetcode-sol PRIVATE GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main)
