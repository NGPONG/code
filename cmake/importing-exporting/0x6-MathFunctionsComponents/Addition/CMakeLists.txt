add_library(Addition STATIC Addition.cxx)

# 声明一个 target，其作为 Addistion 的 alias
add_library(MathFunctions::Addition ALIAS Addition)

target_include_directories(
  Addition
  PUBLIC
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

install(
  TARGETS Addition
  EXPORT AdditionTargets
  # LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  # ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  # RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  # INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(
  FILES Addition.h
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(
  EXPORT AdditionTargets
  FILE MathFunctionsAdditionTargets.cmake
  NAMESPACE MathFunctions::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/MathFunctions
)
