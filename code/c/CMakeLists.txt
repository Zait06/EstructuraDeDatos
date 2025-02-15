cmake_minimum_required(VERSION 3.20)

project(DataStructureProject VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -Werror)

# Library names
set(STATIC_STACK_LIB static_stack)
set(DYNAMIC_STACK_LIB dynamic_stack)

set(STATIC_QUEUE_LIB static_queue)
set(DYNAMIC_QUEUE_LIB dynamic_queue)

# Options
option(STATIC_STACK "Build static stack" OFF)
option(DYNAMIC_STACK "Build dynamic stack" OFF)

option(STATIC_QUEUE "Build static queue" OFF)
option(DYNAMIC_QUEUE "Build dynamic queue" OFF)

# Source code
add_subdirectory(utils)
add_subdirectory(structures)
add_subdirectory(app)
