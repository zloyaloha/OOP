cmake_minimum_required(VERSION 3.10)
project(lab_02)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/test)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${INCLUDE_DIR})

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES false ${SOURCE_DIR}/*.cpp)

add_library(lab_02_lib ${SOURCES})
add_executable(lab_02_exe main.cpp ${SOURCE_DIR}/help.cpp)
add_executable(tests_exe ${TEST_DIR}/tests.cpp ${SOURCE_DIR}/help.cpp)

enable_testing()

add_test(NAME BASIC COMMAND test)
target_link_libraries(tests_exe ${GTEST_LIBRARIES} lab_02_lib)
target_link_libraries(lab_02_exe PRIVATE lab_02_lib)