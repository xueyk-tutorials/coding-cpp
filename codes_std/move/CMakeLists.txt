cmake_minimum_required(VERSION 3.10)
set(PROJECT_NAME "MOVE")
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 11) 
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_executable(rvalue_reference_definition src/rvalue_reference_definition.cpp)
add_executable(lvalue_rvalue_define src/lvalue_rvalue_define.cpp)
add_executable(rvalue_reference src/rvalue_reference.cpp)
add_executable(move_construct src/move_construct.cpp)


