cmake_minimum_required(VERSION 3.5)
set(PROJECT_NAME "CreationalSingleton")
project(${PROJECT_NAME})

# 引入thread
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -march=native -O3 -pthread")
# std::thread是C++11之后才有的特性，故需要设置C++版本
set(CMAKE_CXX_STANDARD 11) 
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(government_simple    src/government_simple.cpp)
add_executable(government_safty    src/government_safty.cpp)


