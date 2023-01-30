cmake_minimum_required(VERSION 3.8)

project(StackProject)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -Werror)

set(
    SOURCES_FILES
    src/main.c 
    src/stack/stack.c 
    src/menu/menu.c
)

# executable name
add_executable(static_stack ${SOURCES_FILES})