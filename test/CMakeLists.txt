cmake_minimum_required(VERSION 3.14)
project(solution-test)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)

add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://blog.winterwonder.top/upload/2022/04/googletest-release-1.11.0.zip
  URL_HASH SHA256=353571C2440176DED91C2DE6D6CD88DDD41401D14692EC1F99E35D013FEDA55A
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  solution-test
  solution.cc
)
target_link_libraries(
  solution-test
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(solution-test)

include_directories(../include)
