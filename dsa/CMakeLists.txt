cmake_minimum_required(VERSION 3.0)
project(dsa)

set(CMAKE_VERBOSE_MAKEFILE OFF)

# 指定编译选项
set(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} -std=c++11 -O0 -ggdb -Wall -Werror")

# -rdynamic: 将所有符号都加入到符号表中，便于使用dlopen或者backtrace追踪到符号
# -fPIC: 生成位置无关的代码，便于动态链接
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -rdynamic -fPIC")

# -Wno-unused-function: 不要警告未使用函数
# -Wno-builtin-macro-redefined: 不要警告内置宏重定义，用于重定义内置的__FILE__宏
# -Wno-deprecated: 不要警告过时的特性
# -Wno-deprecated-declarations: 不要警告使用带deprecated属性的变量，类型，函数
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-unused-function -Wno-builtin-macro-redefined -Wno-deprecated -Wno-deprecated-declarations")

include_directories(.)

option(BUILD_TEST "ON for complile test" ON)

set(LIB_SRC
    util/util.cpp
    partition/partition.cpp
    sort/sort.cpp 
    )

add_library(dsa SHARED ${LIB_SRC})

# wrapper for add_executable
function(sylar_add_executable targetname srcs depends libs)
    add_executable(${targetname} ${srcs})
    add_dependencies(${targetname} ${depends})
    target_link_libraries(${targetname} ${libs})
endfunction()

if(BUILD_TEST)
    sylar_add_executable(test_partition "tests/test_partition.cpp" dsa dsa)
    sylar_add_executable(test_sort "tests/test_sort.cpp" dsa dsa)
endif()

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)