cmake_minimum_required(VERSION 3.10)
project(smart_ptr)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -march=native -O3 -pthread")
set(CMAKE_CXX_STANDARD 17) 
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(unique_ptr src/unique_ptr.cpp)
add_executable(unique_ptr_thread src/unique_ptr_thread.cpp)