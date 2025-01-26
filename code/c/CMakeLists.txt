cmake_minimum_required(VERSION 3.20)

project(DataStructureProject VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -Werror)

set(STATIC_STACK_LIB static_stack)
set(DYNAMIC_STACK_LIB dynamic_stack)

add_subdirectory(utils)
add_subdirectory(structures)
add_subdirectory(app)
