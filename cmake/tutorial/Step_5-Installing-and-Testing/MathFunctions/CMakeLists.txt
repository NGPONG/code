add_library(MathFunctions MathFunctions.cxx)

target_include_directories(MathFunctions
                           INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
                           )

option(USE_MYMATH "Use tutorial provided math implementation" ON)
if (USE_MYMATH)
  target_compile_definitions(MathFunctions PRIVATE "USE_MYMATH")

  add_library(SqrtLibrary STATIC
              mysqrt.cxx
              )

  target_link_libraries(SqrtLibrary PUBLIC tutorial_compiler_flags)

  target_link_libraries(MathFunctions PRIVATE SqrtLibrary)
endif()

target_link_libraries(MathFunctions PUBLIC tutorial_compiler_flags)

set(installable_libs MathFunctions tutorial_compiler_flags)
# 0x1: if (TARGET) 用于判断是否存在某个目标
if (TARGET SqrtLibrary)
  # 0x2: list(APPEND) 用于追加数组的语法
  list(APPEND installable_libs SqrtLibrary)
endif()

# 0x3: 这里将 INTERFACE library 也设置为安装规则，并不是真正安装它(因为它没有源文件)，它包含
#      一些配置型的设置，是为了别的 cmake 项目想使用我们项目的时候，就可以用导入到这个规则。
#      具体参考: https://cmake.org/cmake/help/latest/guide/tutorial/Adding%20Export%20Configuration.html

# 0x4: install(TARGETS [...] FILES [...] DESTINATION [...])
#   * TARGETS: 需要安装的目标
#   * FILES: 需要安装的文件，通常指定为头文件
#   * DESTINATION: 安装路径
#     * 可以指定相对或绝对路径
#     * 当指定为绝对路径时则安装到指定路径，但是官方不推荐这样的做法
#     * 更推崇相对路径的做法，路径前缀由: 1. CMAKE_INSTALL_PREFIX 变量；2. install --prefix；3. DESTDIR 环境变量进行指定
#
#   * https://cmake.org/cmake/help/latest/command/install.html#command:install
#   * https://cmake.org/cmake/help/latest/variable/CMAKE_INSTALL_PREFIX.html#variable:CMAKE_INSTALL_PREFIX
#   * https://cmake.org/cmake/help/latest/envvar/DESTDIR.html#envvar:DESTDIR
install(
  TARGETS ${installable_libs}
  DESTINATION lib
)
install(
  FILES "${CMAKE_CURRENT_SOURCE_DIR}/MathFunctions.h" "${CMAKE_CURRENT_SOURCE_DIR}/mysqrt.h"
  DESTINATION include
)
