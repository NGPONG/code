cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(Tutorial VERSION 1.0)

# 0x1: 创建一个接口库
#   * 接口库通常情况下并不包含源文件，但是它可以像普通的 target 一样去使用
add_library(tutorial_compiler_flags INTERFACE)
# 0x2: 为target设置编译功能，具体支持的内容参见文档
#   * 这里设置的是 INTERFACE target，我们可以像普通目标一样使用它
#   * 为单独的target设置cpp版本并在需要的时候添加它，这种做法能够不污染整个项目的设置
target_compile_features(tutorial_compiler_flags INTERFACE cxx_std_20)

configure_file(TutorialConfig.h.in TutorialConfig.h)

add_subdirectory(MathFunctions)

add_executable(Tutorial tutorial.cxx)

target_link_libraries(Tutorial MathFunctions tutorial_compiler_flags)

target_include_directories(Tutorial PUBLIC "${PROJECT_BINARY_DIR}")
