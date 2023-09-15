cmake_minimum_required(VERSION 3.10)
project(gtest)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(task01 task1.cpp brackets_check.cpp)


enable_testing()
add_executable(tests1 tests1.cpp  brackets_check.cpp)
target_link_libraries(tests1 ${GTEST_LIBRARIES})

add_test(NAME BASIC COMMAND tests1)