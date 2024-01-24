# https://cmake.org/cmake/help/latest/command/add_custom_command.html#examples-generating-files

add_executable(
  MakeTable MakeTable.cxx
)

target_link_libraries(
  MakeTable
  PRIVATE tutorial_compiler_flags
)

# 0x1: 设置定义命令
#   * 包含该命令的输出，可用于 add_* 的时候指定依赖文件
#   * 包含执行命令
#   * 包含依赖
add_custom_command(
  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/Table.h
  COMMAND MakeTable ${CMAKE_CURRENT_BINARY_DIR}/Table.h
  DEPENDS MakeTable
)
