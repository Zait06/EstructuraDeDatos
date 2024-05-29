cmake_minimum_required(VERSION 3.2)

project(DataStructureProject)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -Werror)

option(STATIC_STACK "Build static stack" OFF)
option(DYNAMIC_STACK "Build dynamic stack" OFF)

option(STATIC_QUEUE "Build static queue" OFF)
option(DYNAMIC_QUEUE "Build dynamic queue" OFF)

option(LINKED_LIST "Build simple linked list" OFF)

if(STATIC_STACK)
    message(STATUS "Build static stack")
    set(
        static_stack_files
        src/Stack/static/main.c 
        src/Stack/static/stack.c 
        src/utils/utils.c
    )
    add_executable(static_stack ${static_stack_files})
endif(STATIC_STACK)

if(DYNAMIC_STACK)
    message(STATUS "Build dynamic stack")
    set(
        dynamic_stack_files
        src/Stack/dynamic/main.c 
        src/Stack/dynamic/stack.c 
        src/node/node.c
        src/utils/utils.c
    )
    add_executable(dynamic_stack ${dynamic_stack_files})
endif(DYNAMIC_STACK)

if(STATIC_QUEUE)
    message(STATUS "Build static queue")
    set(
        static_queue_files
        src/Queue/static/main.c 
        src/Queue/static/queue.c 
        src/utils/utils.c
    )
    add_executable(static_queue ${static_queue_files})
endif(STATIC_QUEUE)

if(DYNAMIC_QUEUE)
    message(STATUS "Build static queue")
    set(
        dynamic_queue_files
        src/Queue/dynamic/main.c 
        src/Queue/dynamic/queue.c 
        src/node/node.c
        src/utils/utils.c
    )
    add_executable(dynamic_queue ${dynamic_queue_files})
endif(DYNAMIC_QUEUE)

if(LINKED_LIST)
    message(STATUS "Build simple linked list")
    set(
        linked_list_files
        src/LinkedList/SimpleLinkedList/main.c 
        src/LinkedList/SimpleLinkedList/linkedlist.c 
        src/node/node.c
        src/utils/utils.c
    )
    add_executable(linked_list ${linked_list_files})
endif(LINKED_LIST)