cmake_minimum_required(VERSION 3.2)

project(StackProject)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -Werror)

option(BUILD_STATIC "Build static stack" ON)
option(BUILD_DYNAMIC "Build dynamic stack" ON)

set(utils_dir "${CMAKE_SOURCE_DIR}/../utils/")
include_directories(${utils_dir})

if(BUILD_STATIC)
    message(STATUS "BUILD STATIC STACK")
    set(
        SOURCES_FILES
        static/src/main.c 
        static/src/stack/stack.c 
        static/src/menu/menu.c
    )
    add_executable(static_stack ${SOURCES_FILES})
endif()

if(BUILD_DYNAMIC)
    message(STATUS "BUILD DYNAMIC STACK")
    set(
        SOURCES_FILES
        dynamic/src/main.c 
        dynamic/src/stack/stack.c 
        dynamic/src/menu/menu.c
        ${utils_dir}/node/node.c
    )
    add_executable(dynamic_stack ${SOURCES_FILES})
endif()