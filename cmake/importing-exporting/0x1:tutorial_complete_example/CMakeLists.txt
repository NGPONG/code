# cmake_minimum_required: 指定cmake最低运行版本
#   * 该参数必填
#   * cmake 在 3.15+ 以后才支持 generator expression 的使用

# project: 指定项目相关信息
#   * 该参数必填
#   * 创建 PROJECT_ 相关的一些变量，关于详细查看文档

# include: 导入一些 buildin module 或者是可以引入一些 cmake 文件
#   * CMAKE_MODULE_PATH 是 include 的搜索路径参照之一，搜索 <include_name>.cmake 文件

# set: 设置变量
#   * 可以通过 CACHE 声明创建缓存变量，参考：https://cmake.org/cmake/help/book/mastering-cmake/chapter/CMake%20Cache.html
#   * PARENT_SCOPE 签名可以将变量创建到上一级作用域，类似于函数传递引用变量作为返回值的形式

# add_library: 创建一个库
#   * 可以通过类型(STATIC, SHARED) 来关联 target 的编译类型
#   * 需要指定创建的 target 与其关联的 source
#   * source 指定源文件，其搜索目录可以是相对于当前的 SOURCE_DIR 或者是 BINARY_DIR
#   * source 不一定是 "文件"，它可以是一些 "声明引用"，例如 add_custom_command 的 OUTPUT 声明

# add_executable: 创建一个可执行文件
#   * 需要指定创建的 target 与其关联的 source
#   * source 指定源文件，其搜索目录可以是相对于当前的 SOURCE_DIR 或者是 BINARY_DIR
#   * source 不一定是 "文件"，它可以是一些 "声明引用"，例如 add_custom_command 的 OUTPUT 声明

# target_include_directories: 指定构建目标包含的头文件目录
#   * 需要注意 scope 的继承问题
#   * 影响编译时候 -I 参数的生成
#   * 支持多次调用，依据多次调用的结果填入 target 的包含路径属性当中
#   * 需要使用绝对路径
#   * 该函数的调用会影响 target 的 INCLUDE_DIRECTORIES or INTERFACE_INCLUDE_DIRECTORIES 属性

# target_link_libraries: 设置目标需要连接到的库
#   * 可以指定一个 target
#   * 需要注意 scope 的继承问题

# target_compile_definitions: 设置编译时加入的定义，影响 -D 参数的生成

# target_compile_features: 为 target 设置编译功能，类似于 -std=c++20 等等

# target_compile_options: 为 target 设置编译选项，类似于 -Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused 等等

# set_target_properties: 设置 target 的属性

# generation expression: 一种语法
#   * 生成器表达式是在构建的时候才进行评估，所以正常打印无法打印出来，可以将它理解为cpp中的模板
#   * https://stackoverflow.com/questions/51353110/how-do-i-output-the-result-of-a-generator-expression-in-cmake
#   * https://cmake-doc.readthedocs.io/zh-cn/latest/manual/cmake-generator-expressions.7.html#manual:cmake-generator-expressions(7)
#   * https://cmake.org/cmake/help/latest/manual/cmake-generator-expressions.7.html#manual:cmake-generator-expressions(7)
#   * $<BUILD_INTERFACE:>: 当编译(cmake --build)期间才会应用，否则返回 False
#   * $<${VARIABLE}:>: 当设置了 VARIABLE 才会应用，否则返回 False

# option: 设置 cmake 配置选项，可以暴露出去给用户配置
#   * BUILD_SHARED_LIBS: 内置选项，当开启状态下，则 add_library 未显示指定类型的时候都统一采用 SHARED

# configure_file: 配置文件
#   * 使用相对路径作为 INPUT，其和 CMAKE_CURRENT_SOURCE_DIR  有关
#   * 使用相对路径作为 OUTPUT，其和 CMAKE_CURRENT_BINARY_DIR  有关
#   * 可配置 COPYONLY 以单纯用来 copy 文件
#   * 可配置 @ONLY 以限制 in 文件只能使用 @ 语法
#   * configure prase 阶段就会执行

# aux_source_directory: 列出指定目录下的所有源文件
#   * 可以使用相对路径或绝对路径，但是路径结果前缀会依据选择而不同
#   * aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} DIR_LIB_SRCS)

# add_subdirectory: 添加子目录
#   * 当添加了子目录后即解析子目录下的 CMakeLists.txt 文件
#   * 注意路径的设置问题

# install: 安装
#   * TARGETS: 需要安装的目标
#   * FILES: 需要安装的文件，通常指定为头文件
#   * DESTINATION: 安装路径
#     * 可以指定相对或绝对路径
#     * 当指定为绝对路径时则安装到指定路径，但是官方不推荐这样的做法
#     * 指定为 . 则代表安装具体路径完全遵循前缀的设置
#     * 更推崇相对路径的做法，路径前缀由: 1. CMAKE_INSTALL_PREFIX 变量；2. install --prefix；3. DESTDIR 环境变量进行指定
#   * EXPORT: TODO
#     * 如果作为一级参数，则意味着安装先前 EXPORT 的 target 到 cmake 配置文件中
#     * 如果作为二级参数，则意味着将
#
#   * https://cmake.org/cmake/help/latest/command/install.html#command:install
#   * https://cmake.org/cmake/help/latest/variable/CMAKE_INSTALL_PREFIX.html#variable:CMAKE_INSTALL_PREFIX
#   * https://cmake.org/cmake/help/latest/envvar/DESTDIR.html#envvar:DESTDIR

# add_custom_command: 创建自定义命令
#   * OUTPUT:
#     * 这里的 OUTPUT 文件仅在 build prase 阶段才会执行
#     * 具体的文件位置并不由 OUTPUT 决定，而是由 COMMAND 本身执行结果决定
#     * OUTPUT 的作用更类似对一个结果做一个 "声明"，当拥有了这个声明后，我们在后面的代码中(add_executable等等)就能够引用到这个声明，以此形成一个关联的目的
#   * WORKING_DIRECTORY: 指定 COMMAND 执行的目录
#   * DEPENDS: 指定当前 COMMAND 需要依赖的 target，以此达成一个顺序执行的需求

# cmake 对于 RPATH 处理:
#   * 关于 RUNPATH/RPATH/LD_LIBRARY_PATH 的区别在网页收藏夹找找
#   * cmake 默认不支持 RUNPATH 的添加
#     * 让 cmake 启用参考: https://cmake.org/pipermail/cmake/2011-August/045927.html
#     * cmake 是否支持并不是决定性因素，还需要依赖操作系统的环境，比如有些操作系统可能默认支持
#   * cmake 在 build 的过程中，默认情况下会将 build 的目录作为RPATH传递，即在编译过程中添加 -Wl,-rpath,<CMAKE_CURRENT_BINARY_DIR> 选项
#   * cmake 在 install 前，为了方便用户安装，默认会重新链接 build 出来的可执行文件的 RPATH 目录为空(即不启用 RPATH)(如果存在 [CMAKE_]_INSTALL_RPATH 的设置且无其它特殊限制设置则使用它)，然后再安装
#   * 控制 RPATH 的相关全局变量或属性
#     * [CMAKE_]BUILD_RPATH: 设置在 build 的时候使用的 RPATH 目录；数组，默认为空；
#     * [CMAKE_]INSTALL_RPATH: 设置 install 重新链接的 RPATH 目录，支持 $ORIGIN/@executable_path 的设置；数组，默认为空；
#     * CMAKE_SKIP_INSTALL_RPATH: 设置 cmake 在 install 之前始终不会启用 RPATH
#     * CMAKE_SKIP_BUILD_RPATH: 设置 cmake 在 build 的时候始终不会启用 RPATH
#     * CMAKE_SKIP_RPATH: 设置 CMAKE_SKIP_INSTALL_RPATH && CMAKE_SKIP_BUILD_RPATH
#     * CMAKE_BUILD_WITH_INSTALL_RPATH: 设置 cmake 在 build 的过程中采用 INSTALL RPATH 的设置
#     * CMAKE_INSTALL_RPATH_USE_LINK_PATH: 不清楚

cmake_minimum_required(VERSION 3.15)

project(Tutorial VERSION 1.0)

# CMakePrintHelpers: 可用于方便打印变量的内置库
include(CMakePrintHelpers)
cmake_print_variables(PROJECT_NAME)
cmake_print_variables(PROJECT_SOURCE_DIR)
cmake_print_variables(PROJECT_BINARY_DIR)
cmake_print_variables(PROJECT_VERSION)

# 设置 cmake 的构建输出目录
#   * 不要将其设置为缓存(全局)变量，因为如果有其它项目将你的项目作为子项目的时候，该项更改的将会是呈污染性的
#   * https://stackoverflow.com/questions/6594796/how-do-i-make-cmake-output-into-a-bin-dir
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})# /lib
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})# /lib
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})# /bin
# 设置 cmake install 的目录
set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}/../install_1")
# 设置 cmake 生成 compile_commands.json 文件
set(CMAKE_EXPORT_COMPILE_COMMANDS True)
# 指定 cpp 版本号
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)
# 不知道干啥的
set(CMAKE_DEBUG_POSTFIX d)

# 默认编译为动态库
option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

# 创建一个接口库
#   * 接口库通常情况下并不包含源文件，但是它可以像普通的 target 一样去使用，通常用来完成一些 "配置继承" 的场景
add_library(tutorial_compiler_flags INTERFACE)
# 设置编译时的 cpp 版本，实际效果为加上 -std=c++20
#   * 我们可以也给一个接口库(INTERFACE)的 target 单独设置一些编译功能，当有其它 target 需要相同功能的时候我们就可以链接它们，以此来完成 "配置继承" 的目的
target_compile_features(tutorial_compiler_flags INTERFACE cxx_std_20)
# 确定当前的语言还有使用的编译器
set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")
# 为接口库设置编译选项
#   * 由于这里是接口库，做的是配置继承的目的，所以为了让 "安装了" 我们项目的用户并不会产生提示，仅编译时才会产生提示，所以使用了 BUILD_INTERFACE
target_compile_options(
  tutorial_compiler_flags INTERFACE
  "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>>"
  "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>"
)

# 为不同平台设置 INSTALL 后的 RPATH 路径
#   * @executable_path/$ORIGIN 是链接器支持的语法，即为当前可执行文件所在目录
if(APPLE)
  set(CMAKE_INSTALL_RPATH "@executable_path/../lib")
elseif(UNIX)
  set(CMAKE_INSTALL_RPATH "$ORIGIN/../lib")
endif()

# 配置文件，以为源码生成 Tutorial_VERSION_MAJOR 和 Tutorial_VERSION_MINOR 的宏定义
configure_file(TutorialConfig.h.in TutorialConfig.h)

# 设置子目录，即 ${CMAKE_CURRENT_SOURCE_DIR}/MathFunctions
add_subdirectory(MathFunctions)

# 添加一个可执行文件的 tatrget
add_executable(Tutorial tutorial.cxx)
# 不知道干啥的
set_target_properties(Tutorial PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})
# 链接至 MathFunctions subdirectory 生成的 target
target_link_libraries(Tutorial PUBLIC MathFunctions tutorial_compiler_flags)
# 设置 target 需要包含的头文件目录
target_include_directories(Tutorial PUBLIC "${PROJECT_BINARY_DIR}")

# 安装 Tutorial target 到 ${CMAKE_INSTALL_PREFIX}/bin 目录下
install(TARGETS Tutorial DESTINATION bin)
# 安装头文件到 ${CMAKE_INSTALL_PREFIX}/include 目录下
install(FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h" DESTINATION include)

# 添加单元测试相关 (
enable_testing()
add_test(NAME Runs COMMAND Tutorial 25)
add_test(NAME Usage COMMAND Tutorial)
set_tests_properties(Usage
  PROPERTIES PASS_REGULAR_EXPRESSION "Usage:.*number"
)
function(do_test target arg result)
  add_test(NAME Comp${arg} COMMAND ${target} ${arg})
  set_tests_properties(Comp${arg}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result}
    )
endfunction()
do_test(Tutorial 4 "4 is 2")
do_test(Tutorial 9 "9 is 3")
do_test(Tutorial 5 "5 is 2.236")
do_test(Tutorial 7 "7 is 2.645")
do_test(Tutorial 25 "25 is 5")
do_test(Tutorial -25 "-25 is (-nan|nan|0)")
do_test(Tutorial 0.0001 "0.0001 is 0.01")
# )

# 打包功能相关 (
include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VERSION_MAJOR "${Tutorial_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${Tutorial_VERSION_MINOR}")
set(CPACK_SOURCE_GENERATOR "TGZ")
include(CPack)
# )
