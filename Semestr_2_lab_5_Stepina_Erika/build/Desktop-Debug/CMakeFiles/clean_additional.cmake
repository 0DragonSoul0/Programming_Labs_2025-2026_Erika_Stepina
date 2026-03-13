# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Semestr_2_lab_5_Stepina_Erika_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Semestr_2_lab_5_Stepina_Erika_autogen.dir\\ParseCache.txt"
  "Semestr_2_lab_5_Stepina_Erika_autogen"
  "bigintlib\\CMakeFiles\\bigintlib_autogen.dir\\AutogenUsed.txt"
  "bigintlib\\CMakeFiles\\bigintlib_autogen.dir\\ParseCache.txt"
  "bigintlib\\bigintlib_autogen"
  )
endif()
