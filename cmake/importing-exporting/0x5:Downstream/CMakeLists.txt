cmake_minimum_required(VERSION 3.15)
project(Downstream)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}/../install_5")

# 0x1: 该变量作为 find_package 搜索的前缀
list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../install_1/")

# 0x2: 查找软件包，其实相当于帮我们调用了生成的那几个 cmake 文件
find_package(MathFunctions)

add_executable(myexe main.cc)

target_link_libraries(myexe PRIVATE NGPONG::MathFunctions)
