cmake_minimum_required(VERSION 3.15)
project(MathFunctionsComponents)

include(GNUInstallDirs)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}/../install_6")

add_subdirectory(Addition)
add_subdirectory(SquareRoot)

include(CMakePackageConfigHelpers)

set(version 3.4.1)

write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/MathFunctionsConfigVersion.cmake"
  VERSION "${version}"
  COMPATIBILITY AnyNewerVersion
)

configure_package_config_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
  "${CMAKE_CURRENT_BINARY_DIR}/MathFunctionsConfig.cmake"
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/MathFunctions
  NO_CHECK_REQUIRED_COMPONENTS_MACRO
)

install(
  FILES
  "${CMAKE_CURRENT_BINARY_DIR}/MathFunctionsConfig.cmake"
  "${CMAKE_CURRENT_BINARY_DIR}/MathFunctionsConfigVersion.cmake"
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/MathFunctions
)
