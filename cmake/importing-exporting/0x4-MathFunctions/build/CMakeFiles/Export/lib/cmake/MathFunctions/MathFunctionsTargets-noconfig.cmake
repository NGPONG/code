#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "NGPONG::MathFunctions" for configuration ""
set_property(TARGET NGPONG::MathFunctions APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(NGPONG::MathFunctions PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "CXX"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libMathFunctions.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS NGPONG::MathFunctions )
list(APPEND _IMPORT_CHECK_FILES_FOR_NGPONG::MathFunctions "${_IMPORT_PREFIX}/lib/libMathFunctions.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
