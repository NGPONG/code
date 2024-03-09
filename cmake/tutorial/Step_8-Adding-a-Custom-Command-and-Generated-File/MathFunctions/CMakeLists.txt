add_library(MathFunctions
  MathFunctions.cxx
)

option(USE_MYMATH "Use tutorial provided math implementation" ON)

if (USE_MYMATH)
  target_compile_definitions(
    MathFunctions
    PRIVATE "USE_MYMATH"
  )

  include(MakeTable.cmake)

  # 0x1: 设置生成 SqrtLibrary 需要依赖的头文件，cmake系统会在进行查找，包括 add_custom_command 的输出
  # 0x2: CMAKE_CURRENT_BINARY_DIR 相较于 PROJECT_BINARY_DIR/CMAKE_BINARY_DIR不同
  add_library(
    SqrtLibrary STATIC
    mysqrt.cxx ${CMAKE_CURRENT_BINARY_DIR}/Table.h
  )
  target_include_directories(
    SqrtLibrary
    PRIVATE ${CMAKE_CURRENT_BINARY_DIR}
  )
  target_link_libraries(
    SqrtLibrary
    PUBLIC tutorial_compiler_flags
  )

  target_link_libraries(
    MathFunctions
    PRIVATE SqrtLibrary
  )
endif()

target_include_directories(MathFunctions
                           INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
                           )

target_link_libraries(MathFunctions PUBLIC tutorial_compiler_flags)

set(installable_libs MathFunctions tutorial_compiler_flags)
if(TARGET SqrtLibrary)
  list(APPEND installable_libs SqrtLibrary)
endif()
install(TARGETS ${installable_libs} DESTINATION lib)
install(FILES MathFunctions.h DESTINATION include)
