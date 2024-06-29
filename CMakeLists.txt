cmake_minimum_required(VERSION 3.20)

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
        code/c/Stack/static/main.c
        code/c/Stack/static/stack.c
        code/c/utils/utils.c
    )
    add_executable(static_stack ${static_stack_files})
endif(STATIC_STACK)

if(DYNAMIC_STACK)
    message(STATUS "Build dynamic stack")
    set(
        dynamic_stack_files
        code/c/Stack/dynamic/main.c
        code/c/Stack/dynamic/stack.c
        code/c/node/node.c
        code/c/utils/utils.c
    )
    add_executable(dynamic_stack ${dynamic_stack_files})
endif(DYNAMIC_STACK)

if(STATIC_QUEUE)
    message(STATUS "Build static queue")
    set(
        static_queue_files
        code/c/Queue/static/main.c
        code/c/Queue/static/queue.c
        code/c/utils/utils.c
    )
    add_executable(static_queue ${static_queue_files})
endif(STATIC_QUEUE)

if(DYNAMIC_QUEUE)
    message(STATUS "Build static queue")
    set(
        dynamic_queue_files
        code/c/Queue/dynamic/main.c
        code/c/Queue/dynamic/queue.c
        code/c/node/node.c
        code/c/utils/utils.c
    )
    add_executable(dynamic_queue ${dynamic_queue_files})
endif(DYNAMIC_QUEUE)

if(LINKED_LIST)
    message(STATUS "Build simple linked list")
    set(
        linked_list_files
        code/c/LinkedList/SimpleLinkedList/main.c
        code/c/LinkedList/SimpleLinkedList/linkedlist.c
        code/c/node/node.c
        code/c/utils/utils.c
    )
    add_executable(linked_list ${linked_list_files})
endif(LINKED_LIST)
