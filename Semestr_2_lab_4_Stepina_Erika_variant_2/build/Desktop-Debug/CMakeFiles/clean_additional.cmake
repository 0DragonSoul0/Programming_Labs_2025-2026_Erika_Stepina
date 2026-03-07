# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Semestr_2_lab_4_Stepina_Erika_variant_2_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Semestr_2_lab_4_Stepina_Erika_variant_2_autogen.dir\\ParseCache.txt"
  "Semestr_2_lab_4_Stepina_Erika_variant_2_autogen"
  "carlib\\CMakeFiles\\carlib_autogen.dir\\AutogenUsed.txt"
  "carlib\\CMakeFiles\\carlib_autogen.dir\\ParseCache.txt"
  "carlib\\carlib_autogen"
  )
endif()
