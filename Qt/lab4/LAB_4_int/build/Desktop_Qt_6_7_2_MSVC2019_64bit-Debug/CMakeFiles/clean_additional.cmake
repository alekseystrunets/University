# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\LAB_4_int_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\LAB_4_int_autogen.dir\\ParseCache.txt"
  "LAB_4_int_autogen"
  )
endif()
