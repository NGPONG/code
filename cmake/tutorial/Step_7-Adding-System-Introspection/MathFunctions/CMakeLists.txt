add_library(MathFunctions MathFunctions.cxx)

target_include_directories(MathFunctions
                           INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
                           )

option(USE_MYMATH "Use tutorial provided math implementation" ON)
if (USE_MYMATH)
  include(CheckCXXSourceCompiles)

  target_compile_definitions(MathFunctions PRIVATE "USE_MYMATH")

  add_library(SqrtLibrary STATIC
              mysqrt.cxx
              )

  target_link_libraries(SqrtLibrary PUBLIC tutorial_compiler_flags)

  # 0x1: 检查代码是否能够执行，可以的话就设置变量为 1(True) 否则为 0(False)
  check_cxx_source_compiles("
    #include <cmath>
    int main() {
      std::log(1.0);
      return 0;
    }
  " HAVE_LOG)
  check_cxx_source_compiles("
    #include <cmath>
    int main() {
      std::exp(1.0);
      return 0;
    }
  " HAVE_EXP)

  # 0x2: 这里使用的是 generator expression，如果变量被设置后才会设置相应的 definitions
  target_compile_definitions(SqrtLibrary PRIVATE
    $<$<BOOL:${HAVE_LOG}>:HAVE_LOG>
    $<$<BOOL:${HAVE_EXP}>:HAVE_EXP>
  )

  target_link_libraries(MathFunctions PRIVATE SqrtLibrary)
endif()

target_link_libraries(MathFunctions PUBLIC tutorial_compiler_flags)

set(installable_libs MathFunctions tutorial_compiler_flags)
if(TARGET SqrtLibrary)
  list(APPEND installable_libs SqrtLibrary)
endif()
install(TARGETS ${installable_libs} DESTINATION lib)
install(FILES MathFunctions.h DESTINATION include)
