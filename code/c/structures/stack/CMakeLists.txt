add_library(${STATIC_STACK_LIB} static.h static.c)
add_library(${DYNAMIC_STACK_LIB} dynamic.h dynamic.c)

target_link_libraries(${STATIC_STACK_LIB} utils)
target_link_libraries(${DYNAMIC_STACK_LIB} utils node)
