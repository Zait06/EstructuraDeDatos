cmake_minimum_required(VERSION 3.2)

project(DataStructureProject)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -Werror)

option(BUILD_STATIC_STACK "Build static stack" ON)
option(BUILD_STATIC_QUEUE "Build static queue" ON)

option(BUILD_DYNAMIC_STACK "Build dynamic stack" ON)

if(BUILD_STATIC_STACK)
    message(STATUS "Build static stack")
    set(
        SOURCES_FILES
        Stack/static/main.c 
        Stack/static/stack.c 
        utils/utils.c
    )
    add_executable(static_stack ${SOURCES_FILES})
endif(BUILD_STATIC_STACK)

if(BUILD_DYNAMIC_STACK)
    message(STATUS "Build dynamic stack")
    set(
        SOURCES_FILES
        Stack/dynamic/main.c 
        Stack/dynamic/stack.c 
        utils/node/node.c
        utils/utils.c
    )
    add_executable(dynamic_stack ${SOURCES_FILES})
endif(BUILD_DYNAMIC_STACK)

if(BUILD_STATIC_QUEUE)
    message(STATUS "Build static queue")
    set(
        SOURCES_FILES
        Queue/static/main.c 
        Queue/static/queue.c 
        utils/utils.c
    )
    add_executable(static_queue ${SOURCES_FILES})
endif(BUILD_STATIC_QUEUE)