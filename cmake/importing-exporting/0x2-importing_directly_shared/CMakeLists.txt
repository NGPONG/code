cmake_minimum_required(VERSION 3.15)

project(Importing_Directly)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS True)
set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}/../install_2")

set(SOURCE_FILE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/main.cc")
set(LIBRARY_INSTALL_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../install_1")

# 0x1: if (NOT EXISTS ) 判断是否存在源文件，如果不存在我们就引入外部可执行文件创建它
if (NOT EXISTS "${SOURCE_FILE_PATH}")
  # 0x2: 设置一个 IMPORTED target，构建过程中它不会产生任何文件
  add_executable(
    myexe IMPORTED
  )
  # 0x3: 设置 IMPORTED target 的具体位置，使其关联一个可执行文件
  set_property(
    TARGET myexe
    PROPERTY
    IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/../install_0/myexe"
  )
  # 0x4:
  #   * 这里的 OUTPUT 文件仅在 build prase 阶段才会执行
  #   * 具体的文件位置并不由 OUTPUT 决定，而是由 COMMAND 本身执行结果决定
  #   * OUTPUT 的作用更类似对一个结果做一个 "声明"，当拥有了这个声明后，我们在下面的代码中(add_executable)就能够引用到这个声明，以此形成一个关联的目的
  #   * WORKING_DIRECTORY 指定 COMMAND 执行的目录，借此我们才能在 SOURCE_DIR 中生成我们要的 main.cc 文件
  add_custom_command(
    OUTPUT "${SOURCE_FILE_PATH}"
    COMMAND myexe
    WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
  )
endif()

# 0x5: add_library 的 IMPORTED 签名声明该库由外部导入，而不是从源项目中编译
add_library(
  MathFunctions SHARED IMPORTED
)
# 0x6: 设置 IMPORTED LIBRARY 的具体路径
set_target_properties(
  MathFunctions
  PROPERTIES
  IMPORTED_LOCATION "${LIBRARY_INSTALL_PATH}/lib/libMathFunctions.so"
)

# 0x7: 由于在配置阶段并不存在这个文件，所以我们没法单纯的用 main.cc 来索引，真实存在的仅是上面 add_custom_command 中所声明的 OUTPUT 文件，所以这里我们起到一个 "引用声明" 的目的
add_executable(mynewexe "${SOURCE_FILE_PATH}")

# 0x8: 设置 INSTALL RPATH，以便在 install 后能够找到共享库
set_target_properties(
  mynewexe
  PROPERTIES
  INSTALL_RPATH "$ORIGIN/../lib/"
)

# 0x9: 设置 target 包含库的头文件路径
target_include_directories(mynewexe PRIVATE "${LIBRARY_INSTALL_PATH}/include/")

target_link_libraries(mynewexe PRIVATE MathFunctions)

install(TARGETS mynewexe DESTINATION bin)
# 0xA: 无法通过 TARGETS 签名安装 IMPORTED LIBRARY，只能通过 FILES 签名将共享库拷贝到当前目录下，以映射上面所设置的 INSTALL_RPATH 能够顺利找到共享库
install(FILES "${LIBRARY_INSTALL_PATH}/lib/libMathFunctions.so" DESTINATION lib)
