add_library(node STATIC node.h node.c)
target_include_directories(node PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
