cmake_minimum_required(VERSION 3.2)

project(DataStructureProject)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -Werror)

option(BUILD_STATIC "Build static structures" ON)
option(BUILD_DYNAMIC "Build dynamic structures" ON)

option(BUILD_STACK "Build stack structure" ON)
option(BUILD_QUEUE "Build queue structure" ON)


if(BUILD_STATIC)
    if(BUILD_STACK)
        message(STATUS "BUILD STATIC STACK")
        set(
            SOURCES_FILES
            Stack/static/main.c 
            Stack/static/stack.c 
            utils/menu/menu.c
        )
        add_executable(static_stack ${SOURCES_FILES})
    endif(BUILD_STACK)
endif(BUILD_STATIC)

if(BUILD_DYNAMIC)
    if(BUILD_STACK)
        message(STATUS "BUILD DYNAMIC STACK")
        set(
            SOURCES_FILES
            Stack/dynamic/main.c 
            Stack/dynamic/stack.c 
            utils/node/node.c
            utils/menu/menu.c
        )
        add_executable(dynamic_stack ${SOURCES_FILES})
    endif(BUILD_STACK)
endif(BUILD_DYNAMIC)