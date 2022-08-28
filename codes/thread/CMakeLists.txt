cmake_minimum_required(VERSION 3.10)
set(PROJECT_NAME "THREAD")
project(${PROJECT_NAME})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -march=native -O3 -pthread")
# set(CMAKE_CXX_STANDARD 17) 
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(learn_1 src/learn_1.cpp)
