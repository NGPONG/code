#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "MathFunctions::Addition" for configuration ""
set_property(TARGET MathFunctions::Addition APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(MathFunctions::Addition PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "CXX"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libAddition.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS MathFunctions::Addition )
list(APPEND _IMPORT_CHECK_FILES_FOR_MathFunctions::Addition "${_IMPORT_PREFIX}/lib/libAddition.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
