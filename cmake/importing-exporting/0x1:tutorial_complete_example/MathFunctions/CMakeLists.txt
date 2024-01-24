# 创建一个动态库(由于未显示指定类型，故引用 BUILD_SHARED_LIBS 变量的设置)
add_library(MathFunctions MathFunctions.cxx)

# 设置 target 需要包含的头文件目录
#   * 这里用了两个生成器表达式的目的以表示在不同状态下的路径
#     * BUILD_INTERFACE:
#       * 一般为我们自己源代码项目内部使用；表示源码构建期间
#       * 具体来说它代表着编译时的 -I 参数
#       * 不允许使用相对路径，它不会被转化为绝对路径
#     * INSTALL_INTERFACE:
#       * 一般为当前库导出给下游使用时，下游 include 这个库后会继承这个设置；表示安装期间
#       * 具体来说它代表下游引入该库的时候，对于 IMPORTED 的 INTERFACE_INCLUDE_DIRECTORIES 属性的设置
#       * 允许使用相对路径，其前缀由 CMAKE_INSTALL_PREFIX 构成
#   * https://cmake.org/cmake/help/latest/guide/importing-exporting/index.html#creating-relocatable-packages
#   * https://cmake.org/cmake/help/latest/prop_tgt/INTERFACE_INCLUDE_DIRECTORIES.html#prop_tgt:INTERFACE_INCLUDE_DIRECTORIES
#   * https://cmake.org/cmake/help/latest/command/target_include_directories.html
target_include_directories(
  MathFunctions
  INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

# 设置用户配置选项
option(USE_MYMATH "Use tutorial provided math implementation" ON)

if(USE_MYMATH)
  # 设置编译目标时，编译器附带的 -DUSE_MYMATH 定义
  target_compile_definitions(MathFunctions PRIVATE "USE_MYMATH")

  # 包含 MakeTable.cmake 文件，即执行里面的内容
  include(MakeTable.cmake)

  # 创建一个静态库，这里依赖了 MakeTable.cmake 中 add_custom_command 的 OUTPUT 文件引用
  #   * 由于 Table.h 的生成并没有其它特殊的设置，所以它会生成在 BINARY_DIR 中，所以我们头文件路径需要包含这个路径
  add_library(
    SqrtLibrary STATIC
    mysqrt.cxx ${CMAKE_CURRENT_BINARY_DIR}/Table.h
  )

  # 检查代码是否能够执行，可以的话就设置变量为 1(True) 否则为 0(False)
  include(CheckCXXSourceCompiles)
  check_cxx_source_compiles(
  "
    #include <cmath>
    int main() {
      std::log(1.0);
      return 0;
    }
  " HAVE_LOG)
  check_cxx_source_compiles(
  "
    #include <cmath>
    int main() {
      std::exp(1.0);
      return 0;
    }
  " HAVE_EXP)
  # 这里使用的是 generator expression，如果变量被设置后才会设置相应的 definitions
  target_compile_definitions(
    SqrtLibrary PRIVATE
    $<$<BOOL:${HAVE_LOG}>:HAVE_LOG>
    $<$<BOOL:${HAVE_EXP}>:HAVE_EXP>
  )

  # 设置 target 需要包含的头文件目录
  target_include_directories(
    SqrtLibrary
    PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}
  )

  # 设置 target 的 PIC 属性，即添加 -fPIC 编译选项
  #   * 由于 SqrtLibrary 会被连接至 MathFunctions，而 MathFunctions 会被编译为动态库，所以为了能正确链接，该 target 也要编译为 PIC 属性
  set_target_properties(
    SqrtLibrary
    PROPERTIES POSITION_INDEPENDENT_CODE ${BUILD_SHARED_LIBS}
  )

  # 设置 target 链接
  target_link_libraries(SqrtLibrary PRIVATE tutorial_compiler_flags)

  # 设置 target 链接
  target_link_libraries(MathFunctions PRIVATE SqrtLibrary)
endif()

# 设置 target 链接
target_link_libraries(MathFunctions PUBLIC tutorial_compiler_flags)

# 设置编译目标时，编译器附带的 -DEXPORTING_MYMATH 定义
target_compile_definitions(MathFunctions PRIVATE "EXPORTING_MYMATH")

# 设置 target 的 VERSION 属性
# set_property(TARGET MathFunctions PROPERTY VERSION "1.0.0")
# set_property(TARGET MathFunctions PROPERTY SOVERSION "1")

# 当我们在设置 VARIABLE 时指定了多个参数，则意味着声明数组
set(installable_libs MathFunctions tutorial_compiler_flags)
# if (TARGET): 判断是否存在某个 target
if(TARGET SqrtLibrary)
  # list(APPEND) 用于追加数组的语法
  list(APPEND installable_libs SqrtLibrary)
endif()

# 安装 targets 到 ${CMAKE_INSTALL_PREFIX}/bin 目录下
#   * 这里将 INTERFACE library 也设置为安装规则，并不是真正安装它(因为它没有源文件)，它包含一些配置型的设置，是为了别的 cmake 项目想使用我们项目的时候，就可以用导入到这个规则
#   * https://cmake.org/cmake/help/latest/guide/tutorial/Adding%20Export%20Configuration.html
install(
  TARGETS ${installable_libs}
  EXPORT MathFunctionsTargets
  DESTINATION lib
)

# 安装头文件到 ${CMAKE_INSTALL_PREFIX}/include 目录下
install(FILES MathFunctions.h DESTINATION include)

# target EXPORT 相关，相关信息见: 0x4:MathFunctions 的使用注释 (
include(CMakePackageConfigHelpers)

install(
  EXPORT MathFunctionsTargets
  FILE MathFunctionsTargets.cmake
  NAMESPACE NGPONG::
  DESTINATION lib/cmake/MathFunctions
)

configure_package_config_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
  "${CMAKE_CURRENT_BINARY_DIR}/MathFunctionsConfig.cmake"
  INSTALL_DESTINATION "lib/cmake/MathFunctions"
  NO_SET_AND_CHECK_MACRO
  NO_CHECK_REQUIRED_COMPONENTS_MACRO
)
write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/MathFunctionsConfigVersion.cmake"
  VERSION "${Tutorial_VERSION_MAJOR}.${Tutorial_VERSION_MINOR}"
  COMPATIBILITY AnyNewerVersion
)
install(
  FILES
  ${CMAKE_CURRENT_BINARY_DIR}/MathFunctionsConfig.cmake
  DESTINATION lib/cmake/MathFunctions
)
export(
  EXPORT MathFunctionsTargets
  FILE "${CMAKE_CURRENT_BINARY_DIR}/MathFunctionsTargets.cmake"
  NAMESPACE NGPONG::
)
# )
