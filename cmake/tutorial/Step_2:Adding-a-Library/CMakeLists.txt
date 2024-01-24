cmake_minimum_required(VERSION 3.10)

include(CMakePrintHelpers)

project(Tutorial VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS True)

configure_file(TutorialConfig.h.in TutorialConfig.h)

# 0x0: 列出指定目录下的所有源文件
#   * 可以使用相对路径或绝对路径，但是路径结果前缀会依据选择而不同
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} DIR_LIB_SRCS)

# 0x1: 添加子目录，即解析子目录下的 CMakeLists.txt 文件
add_subdirectory(hahah)

add_executable(Tutorial ${DIR_LIB_SRCS})

target_link_libraries(Tutorial MathFunctions)

# 0x3: 支持多次调用，依据多次调用的结果填入 target 的包含路径属性当中
target_include_directories(Tutorial PUBLIC "${PROJECT_BINARY_DIR}")
