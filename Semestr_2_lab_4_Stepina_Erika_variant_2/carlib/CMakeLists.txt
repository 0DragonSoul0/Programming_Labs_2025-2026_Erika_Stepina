project("carlib")
add_library(carlib car.cpp car.h)
target_include_directories(carlib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})