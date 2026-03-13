project("bigintlib")
add_library(bigintlib bigint.cpp bigint.h)
target_include_directories(bigintlib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})