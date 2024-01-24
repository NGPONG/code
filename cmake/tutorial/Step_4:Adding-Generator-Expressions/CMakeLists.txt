# 0x1: 生成器表达式要求cmake的最低版本为3.15
cmake_minimum_required(VERSION 3.15)

project(Tutorial VERSION 1.0)

# 0x2: 生成器表达式
#   * 生成器表达式是在构建的时候才进行评估，所以正常打印无法打印出来，可以将它理解为cpp中的模板
#   * https://stackoverflow.com/questions/51353110/how-do-i-output-the-result-of-a-generator-expression-in-cmake
#   * https://cmake-doc.readthedocs.io/zh-cn/latest/manual/cmake-generator-expressions.7.html#manual:cmake-generator-expressions(7)
#   * https://cmake.org/cmake/help/latest/manual/cmake-generator-expressions.7.html#manual:cmake-generator-expressions(7)
set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")

add_library(tutorial_compiler_flags INTERFACE)

target_compile_features(tutorial_compiler_flags INTERFACE cxx_std_11)

# 0x3: 设置target的编译选项
target_compile_options(tutorial_compiler_flags
                       INTERFACE
                       "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>>"
                       "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>")

# configure a header file to pass some of the CMake settings
# to the source code
configure_file(TutorialConfig.h.in TutorialConfig.h)

# add the MathFunctions library
add_subdirectory(MathFunctions)

# add the executable
add_executable(Tutorial tutorial.cxx)

target_link_libraries(Tutorial PUBLIC MathFunctions tutorial_compiler_flags)

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
target_include_directories(Tutorial PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )
