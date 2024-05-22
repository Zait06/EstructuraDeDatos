cmake_minimum_required(VERSION 3.2)

project(DataStructureProject)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -Werror)

option(STATIC_STACK "Build static stack" OFF)
option(DYNAMIC_STACK "Build dynamic stack" OFF)

option(STATIC_QUEUE "Build static queue" OFF)
option(DYNAMIC_QUEUE "Build dynamic queue" OFF)

if(STATIC_STACK)
    message(STATUS "Build static stack")
    set(
        SOURCES_FILES
        src/Stack/static/main.c 
        src/Stack/static/stack.c 
        src/utils/utils.c
    )
    add_executable(static_stack ${SOURCES_FILES})
endif(STATIC_STACK)

if(DYNAMIC_STACK)
    message(STATUS "Build dynamic stack")
    set(
        SOURCES_FILES
        src/Stack/dynamic/main.c 
        src/Stack/dynamic/stack.c 
        src/node/node.c
        src/utils/utils.c
    )
    add_executable(dynamic_stack ${SOURCES_FILES})
endif(DYNAMIC_STACK)

if(STATIC_QUEUE)
    message(STATUS "Build static queue")
    set(
        SOURCES_FILES
        src/Queue/static/main.c 
        src/Queue/static/queue.c 
        src/utils/utils.c
    )
    add_executable(static_queue ${SOURCES_FILES})
endif(STATIC_QUEUE)

if(DYNAMIC_QUEUE)
    message(STATUS "Build static queue")
    set(
        SOURCES_FILES
        src/Queue/dynamic/main.c 
        src/Queue/dynamic/queue.c 
        src/node/node.c
        src/utils/utils.c
    )
    add_executable(dynamic_queue ${SOURCES_FILES})
endif(DYNAMIC_QUEUE)