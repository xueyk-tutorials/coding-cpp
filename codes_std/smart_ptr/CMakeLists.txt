cmake_minimum_required(VERSION 3.10)
project(smart_ptr)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -march=native -O3 -pthread")
set(CMAKE_CXX_STANDARD 17) 
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(shared_ptr_basic src/shared_ptr/shared_ptr_basic.cpp)
add_executable(shared_from_this src/shared_ptr/shared_from_this.cpp)

add_executable(unique_ptr_basic src/unique_ptr/unique_ptr_basic.cpp)
add_executable(unique_ptr_destructor src/unique_ptr/unique_ptr_destructor.cpp)
add_executable(unique_ptr_thread src/unique_ptr/unique_ptr_thread.cpp)
