cmake_minimum_required(VERSION 3.15)
project(MathFunctions)

include(CMakePrintHelpers)

# 0x1: GNUInstallDirs模块提供 GNU 编码标准定义的安装目录变量
#   * 相关变量都以 CMAKE_INSTALL_* 或 CMAKE_INSTALL_FULL_* 开头
#   * 例如: CMAKE_INSTALL_BINDIR, CMAKE_INSTALL_INCLUDEDIR
#   * 最好将该模块置于顶层
include(GNUInstallDirs)
cmake_print_variables(CMAKE_INSTALL_BINDIR)
cmake_print_variables(CMAKE_INSTALL_SBINDIR)
cmake_print_variables(CMAKE_INSTALL_LIBEXECDIR)
cmake_print_variables(CMAKE_INSTALL_SYSCONFDIR)
cmake_print_variables(CMAKE_INSTALL_SHAREDSTATEDIR)
cmake_print_variables(CMAKE_INSTALL_LOCALSTATEDIR)
cmake_print_variables(CMAKE_INSTALL_RUNSTATEDIR)
cmake_print_variables(CMAKE_INSTALL_LIBDIR)
cmake_print_variables(CMAKE_INSTALL_INCLUDEDIR)
cmake_print_variables(CMAKE_INSTALL_OLDINCLUDEDIR)
cmake_print_variables(CMAKE_INSTALL_DATAROOTDIR)
cmake_print_variables(CMAKE_INSTALL_DATADIR)
cmake_print_variables(CMAKE_INSTALL_INFODIR)
cmake_print_variables(CMAKE_INSTALL_LOCALEDIR)
cmake_print_variables(CMAKE_INSTALL_MANDIR)
cmake_print_variables(CMAKE_INSTALL_DOCDIR)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}/../install_4")

add_library(MathFunctions STATIC MathFunctions.cxx)

target_include_directories(
  MathFunctions
  PUBLIC
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
  "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)

# 0x2:
#   * 通过 EXPORT 签名将 install target 声明为 EXPORTED；注意：在这一步骤中不会安装任何文件，仅只是声明 target 为 EXPORTED
#   * 这四个 DESTINATION 的作用？好像注释掉也不影响
#   * 可执行文件也可以使用 EXPORT 签名，流程和这个一致
install(
  TARGETS MathFunctions
  EXPORT MathFunctionsTargets
  DESTINATION ${CMAKE_INSTALL_LIBDIR}
  # LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  # ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  # RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  # INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
  # LIBRARY DESTINATION "test/ngpong/1/"
  # ARCHIVE DESTINATION "test/ngpong/2/"
  # RUNTIME DESTINATION "test/ngpong/3/"
  # INCLUDES DESTINATION "test/ngpong/4/"
)

install(FILES MathFunctions.h DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# 0x3: install(EXPORT): 安装导出目标为 cmake 文件，以便其它项目可以直接通过 include 来调用
#   * EXPORT 目标为我们在上面在 intall 中使用 EXPORT 签名声明的 target
#   * NAMESPACE: 如字面意思，在下游使用当前模块到处的目标时需要追加 namespace，即：NGPONG:MathFunctions
#   * FILES: 设置生成的文件名
#   * DESTINATION: 设置生成的文件路径
#   * 生成的 cmake 文件主要为了我们干了几件事方便我们 import target
#     * add_library(IMPORTED) 当前 target
#     * 设置 target 的 INTERFACE_INCLUDE_DIRECTORIES 属性为我们在这里设置(target_include_directories)(install 期间指定的 INCLUDES DESTINATION 也会追加进去)
#     * 设置 target 的 IMPORTED_LOCATION 属性(默认会生成一个)(install 期间指定的 LIBRARY DESTINATION 也会追加进去)
install(
  EXPORT MathFunctionsTargets
  FILE MathFunctionsTargets.cmake
  NAMESPACE NGPONG::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/MathFunctions
)

# 0x4:
#   * 至此已经完成了到处cmake文件的工作，下游使用的时候则可以通过 include 我们安装的 cmake 文件来 import 当前 target
#   * 还有一种更方便的方式是使当前 target 支持 find_package() 函数，这样的支持需要我们为当前 target 创建一个 package

# find_package
#  帮我们 include
#  帮我们检查一些依赖项？
#  module mode and config mode，这里介绍的是 config mode

# 0x5: CMakePackageConfigHelpers模块提供一个package生成config的一些帮助函数
include(CMakePackageConfigHelpers)

# 0x6: 设置软件包版本，当调用 find_package 的时候我们可以指定版本 (
set(version 3.4.1)

set_property(TARGET MathFunctions PROPERTY VERSION ${version})
set_property(TARGET MathFunctions PROPERTY SOVERSION 3)
set_property(TARGET MathFunctions PROPERTY
  INTERFACE_MathFunctions_MAJOR_VERSION 3)
set_property(TARGET MathFunctions APPEND PROPERTY
  COMPATIBLE_INTERFACE_STRING MathFunctions_MAJOR_VERSION
)

# generate the version file for the config file
write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/MathFunctionsConfigVersion.cmake"
  VERSION "${version}"
  COMPATIBILITY AnyNewerVersion
)
# )

# 0x7: configure_package_config_file: 生成package的配置文件
#   * 为什么要创建 package 需要创建配置文件？
#     * 为了使 find_package 函数
#     * 配置文件可以帮我们省略掉上面的版本在 IMPORT target 时候的 include 工作，而且我们可以做一些依赖的前置检查
#   * 使用相对路径作为 INPUT，其和 CMAKE_CURRENT_SOURCE_DIR  有关
#   * 使用相对路径作为 OUTPUT，其和 CMAKE_CURRENT_BINARY_DIR  有关
#   * 配置文件内(INPUT)的 @PACKAGE_INIT@ 语法能我们展开一段代码
#   * INSTALL_DESTINATION 必须指定为 EXPORT target 的 cmake 文件的路径
configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
  "${CMAKE_CURRENT_BINARY_DIR}/MathFunctionsConfig.cmake"
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/MathFunctions
)

# 0x8: 安装 write_basic_package_version_file 与 configure_package_config_file 生成的配置文件
install(
  FILES
  "${CMAKE_CURRENT_BINARY_DIR}/MathFunctionsConfig.cmake"
  "${CMAKE_CURRENT_BINARY_DIR}/MathFunctionsConfigVersion.cmake"
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/MathFunctions
)

# 0x9: 上面所导出的配置文件仅在 install 的过程中才会安装，通过下面的命令则可以在构建时候直接装在构建目录下，适用于一些特殊的情景
export(
  EXPORT MathFunctionsTargets
  FILE "${CMAKE_CURRENT_BINARY_DIR}/cmake/MathFunctionsTargets.cmake"
  NAMESPACE NGPONG::
)
