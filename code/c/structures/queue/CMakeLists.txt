add_library(${STATIC_QUEUE_LIB} static.h static.c)
add_library(${DYNAMIC_QUEUE_LIB} dynamic.h dynamic.c)

target_link_libraries(${STATIC_QUEUE_LIB} utils)
target_link_libraries(${DYNAMIC_QUEUE_LIB} utils node)
