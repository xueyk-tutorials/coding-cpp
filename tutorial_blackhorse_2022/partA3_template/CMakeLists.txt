cmake_minimum_required(VERSION 3.5)

###
# 指定为C++11 版本
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

add_executable(template_function src/1template_function.cpp)
add_executable(call_principle src/2call_principle.cpp)
add_executable(overload src/3overload.cpp)
add_executable(template_class src/4template_class.cpp)
add_executable(call_member_function src/5call_member_function.cpp)

add_executable(as_param src/6as_param.cpp)
add_executable(friend_fun src/9friend_fun.cpp)

include_directories(
    include
)
add_executable(my_array src/my_array.cpp)