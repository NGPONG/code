# 添加一个可执行文件的 tatrget
add_executable(MakeTable MakeTable.cxx)

# 为 target 链接我们之前创建的 INTERFACE target，里面包含了一些编译警告的选项
target_link_libraries(MakeTable PRIVATE tutorial_compiler_flags)

# 依据 custom command 的 OUTPUT 创建一个 target 
add_custom_target(Table.h DEPENDS Table.h.command)

# 创建一个自定义命令
#   * 执行了 MakeTable ${CMAKE_CURRENT_BINARY_DIR}/Table.h 命令
#   * 它依赖于 MakeTable target，所以只有当 add_executable(MakeTable) 执行完毕后才会执行它
add_custom_command(
  OUTPUT Table.h.command
  COMMAND MakeTable ${CMAKE_CURRENT_BINARY_DIR}/Table.h
  DEPENDS MakeTable
)
