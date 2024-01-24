# 添加一个可执行文件的 tatrget
add_executable(MakeTable MakeTable.cxx)

# 为 target 链接我们之前创建的 INTERFACE target，里面包含了一些编译警告的选项
target_link_libraries(MakeTable PRIVATE tutorial_compiler_flags)

# 创建一个自定义命令
#   * 执行了 MakeTable ${CMAKE_CURRENT_BINARY_DIR}/Table.h 命令
#   * 它依赖于 MakeTable target，所以只有当 add_executable(MakeTable) 执行完毕后才会执行它
#   * 它 OUTPUT 了${CMAKE_CURRENT_BINARY_DIR}/Table.h文件，注意这里并不是真正指定 OUPUT 的目录，只是做一个声明作用，具体路径有 COMMAND 的执行结果决定
add_custom_command(
  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/Table.h
  COMMAND MakeTable ${CMAKE_CURRENT_BINARY_DIR}/Table.h
  DEPENDS MakeTable
)
