# 0x1: 设置选项，可以在 cmake 命令行通过 -D 参数指定
#   * 第一个参数设置选项名
#   * 第二个参数设置帮助文档
#   * 第三个参数设置选项的默认值
option(USE_MYMATH "ngpong helper message" ON)

# 0x2: 指定构建库(STATIC)与源文件
add_library(MathFunctions STATIC MathFunctions.cxx)

# 0x3: 条件表达式
if (USE_MYMATH)
  add_library(SqrtLibrary STATIC mysqrt.cxx)

  # 0x4: 设置目标需要连接到的库
  #   * 注意 scope 传递的问题，这里指定了 PRIVATE 限制了 SqrtLibrary 的传递性，但是在最终可执行文件生成的时还是会传递下去
  target_link_libraries(MathFunctions PRIVATE SqrtLibrary)

  # 0x5: 设置编译目标时，编译器附带的 -D 定义(#ifdef)
  target_compile_definitions(MathFunctions PRIVATE USE_MYMATH)
endif()

target_include_directories(MathFunctions INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")
