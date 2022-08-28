cmake_minimum_required(VERSION 3.5)

###
# 指定为C++11 版本
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

add_executable(string_basic.cpp        src/test_string/1string_basic.cpp)
add_executable(string_find_replace.cpp src/test_string/2string_find_replace.cpp)
add_executable(string_compare.cpp      src/test_string/3string_compare.cpp)
add_executable(string_substr.cpp       src/test_string/4string_substr.cpp)

add_executable(vector_basic.cpp        src/test_vector/1vector_basic.cpp)
add_executable(vector_nesting.cpp      src/test_vector/2vector_nesting.cpp)
add_executable(vector_insert_erase.cpp src/test_vector/3vector_insert_erase.cpp)
add_executable(vector_reserve.cpp      src/test_vector/4vector_reserve.cpp)

add_executable(queue_construct.cpp      src/test_list/1queue_construct.cpp)

add_executable(list_construct.cpp      src/test_list/1list_construct.cpp)
