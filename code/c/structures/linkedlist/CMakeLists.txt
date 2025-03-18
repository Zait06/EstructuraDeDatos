add_library(${SIMPLE_LINKEDLIST_LIB} simple.h simple.c)
target_link_libraries(${SIMPLE_LINKEDLIST_LIB} utils node)
