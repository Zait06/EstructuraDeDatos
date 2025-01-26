option(STATIC_STACK "Build static stack" ON)
option(DYNAMIC_STACK "Build dynamic stack" ON)

# option(STATIC_QUEUE "Build static queue" OFF)
# option(DYNAMIC_QUEUE "Build dynamic queue" OFF)
#
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

# if(STATIC_QUEUE)
#     message(STATUS "Build static queue")
#     set(
#         static_queue_files
#         main_queue_static.c
#     )
#     add_executable(static_queue ${static_queue_files})
# endif(STATIC_QUEUE)
#
# if(DYNAMIC_QUEUE)
#     message(STATUS "Build dynamic queue")
#     set(
#         dynamic_queue_files
#         main_queue_dynamic.c
#     )
#     add_executable(dynamic_queue ${dynamic_queue_files})
# endif(DYNAMIC_QUEUE)
#
# if(LINKED_LIST)
#     message(STATUS "Build simple linked list")
#     set(
#         linked_list_files
#         main_linkedlist.cpp
#     )
#     add_executable(linked_list ${linked_list_files})
# endif(LINKED_LIST)

# if(DOUBLE_LINKED_LIST)
#     message(STATUS "Build double linked list")
#     set(
#         linked_list_files
#         main_doublelinkedlist.c
#         LinkedList/double/doublelinkedlist.c
#         node/node.c
#         utils/utils.c
#     )
#     add_executable(linked_list ${linked_list_files})
# endif(DOUBLE_LINKED_LIST)

include_directories(${CMAKE_SOURCE_DIR}/structures ${CMAKE_SOURCE_DIR}/utils)
