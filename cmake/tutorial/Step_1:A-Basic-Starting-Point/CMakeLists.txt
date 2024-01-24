# 0x0: 最低cmake版本要求
cmake_minimum_required(VERSION 3.22)

# 0x1: project 用于指定 <项目名> [版本] [...]
#   * 该函数会创建 PROJECT_ 相关的一些变量，关于详细查看文档
project(Tutorial VERSION 1.0)

# 0x2: CMakePrintHelpers 是一个可用于方便打印变量的内置库
include(CMakePrintHelpers)
cmake_print_variables(PROJECT_NAME)
cmake_print_variables(PROJECT_SOURCE_DIR)
cmake_print_variables(PROJECT_BINARY_DIR)
cmake_print_variables(PROJECT_VERSION)

# 0x3: CMAKE 开头的都是内置变量
#   * 指定 cmake 生成 compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS true)
#   * 指定 cpp 版本号
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)

# 0x4: 设置配置文件的输入输出
configure_file("TutorialConfig.h.in" "TutorialConfig.h" @ONLY)

# 0x5: 指定构建目标与源文件
add_executable(Tutorial tutorial.cxx)

# 0x6: 指定构建目标包含的头文件目录
#   * 需要使用绝对路径
#   * 该函数的调用会影响 target 的 INCLUDE_DIRECTORIES or INTERFACE_INCLUDE_DIRECTORIES 属性
target_include_directories(Tutorial PUBLIC ${PROJECT_BINARY_DIR}) # or relative path: "build"

# 0x7: 获取 target 的属性
get_target_property(LIBA_INCLUDES Tutorial INCLUDE_DIRECTORIES)
cmake_print_variables(LIBA_INCLUDES)
