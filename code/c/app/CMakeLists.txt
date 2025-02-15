# option(LINKED_LIST "Build simple linked list" OFF)
# option(DOUBLE_LINKED_LIST "Build double linked list" OFF)

if(STATIC_STACK)
  message(STATUS "Build static stack")
  add_executable(sstack_exe main_stack_static.c)
  target_link_libraries(sstack_exe utils ${STATIC_STACK_LIB})
endif(STATIC_STACK)

if(DYNAMIC_STACK)
  message(STATUS "Build dynamic stack")
  add_executable(dstack_exe main_stack_dynamic.c)
  target_link_libraries(dstack_exe utils node ${DYNAMIC_STACK_LIB})
endif(DYNAMIC_STACK)

if(STATIC_QUEUE)
  message(STATUS "Build static queue")
  add_executable(squeue_exe main_queue_static.c)
  target_link_libraries(squeue_exe utils ${STATIC_QUEUE_LIB})
endif(STATIC_QUEUE)

if(DYNAMIC_QUEUE)
    message(STATUS "Build dynamic queue")
    add_executable(dqueue_exe main_queue_dynamic.c)
    target_link_libraries(dqueue_exe utils node ${DYNAMIC_QUEUE_LIB})
endif(DYNAMIC_QUEUE)

include_directories(${CMAKE_SOURCE_DIR}/structures ${CMAKE_SOURCE_DIR}/utils)
