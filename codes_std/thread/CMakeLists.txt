cmake_minimum_required(VERSION 3.10)
set(PROJECT_NAME "THREAD")
project(${PROJECT_NAME})

# 引入thread
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -march=native -O3 -pthread")
# std::thread是C++11之后才有的特性，故需要设置C++版本
set(CMAKE_CXX_STANDARD 11) 
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(learn_1 src/learn_1.cpp)
add_executable(learn_2 src/learn_2.cpp)
add_executable(learn_3 src/learn_3_join_detach.cpp)

add_executable(mutex_with src/mutex/test1_with_mutex.cpp)

