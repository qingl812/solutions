cmake_minimum_required(VERSION 3.14)

project(solution)

add_subdirectory(test)
include_directories(include)

add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
