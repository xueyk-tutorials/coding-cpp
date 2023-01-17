cmake_minimum_required(VERSION 3.5)
project(test)

set(CMAKE_CXX_STANDARD 11) 
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
    include
)
add_executable(read_file_tostring src/read_file_tostring.cpp)
add_executable(test_enum src/test_enum.cpp)