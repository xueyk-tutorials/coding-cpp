cmake_minimum_required(VERSION 3.10)
project(function)

set(CMAKE_CXX_STANDARD 17) 
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(constructor src/constructor.cpp)
add_executable(wrap_callable src/wrap_callable.cpp)
add_executable(function_pointer src/function_pointer.cpp)
