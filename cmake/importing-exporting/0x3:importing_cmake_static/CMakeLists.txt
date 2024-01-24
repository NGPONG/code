cmake_minimum_required(VERSION 3.15)

project(Importing_CMake)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS True)
set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}/../install_3")

include("${CMAKE_CURRENT_SOURCE_DIR}/../install_4/lib/cmake/MathFunctions/MathFunctionsTargets.cmake")

add_executable(mynewexe "${CMAKE_CURRENT_SOURCE_DIR}/main.cc")

target_include_directories(mynewexe PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../install_4/include/")

target_link_libraries(mynewexe PRIVATE NGPONG::MathFunctions)

install(TARGETS mynewexe DESTINATION bin)
