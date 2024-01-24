
####### Expanded from @PACKAGE_INIT@ by configure_package_config_file() #######
####### Any changes to this file will be overwritten by the next CMake run ####
####### The input file was Config.cmake.in                            ########

get_filename_component(PACKAGE_PREFIX_DIR "${CMAKE_CURRENT_LIST_DIR}/../../../" ABSOLUTE)

macro(set_and_check _var _file)
  set(${_var} "${_file}")
  if(NOT EXISTS "${_file}")
    message(FATAL_ERROR "File or directory ${_file} referenced by variable ${_var} does not exist !")
  endif()
endmacro()

####################################################################################

set(_MathFunctions_supported_components Addition SquareRoot)

foreach(_comp ${MathFunctions_FIND_COMPONENTS})
  if (NOT _comp IN_LIST _MathFunctions_supported_components)
    set(MathFunctions_FOUND False)
    set(MathFunctions_NOT_FOUND_MESSAGE "Unsupported component: ${_comp}")
  endif()
  include("${CMAKE_CURRENT_LIST_DIR}/MathFunctions${_comp}Targets.cmake")
endforeach()
