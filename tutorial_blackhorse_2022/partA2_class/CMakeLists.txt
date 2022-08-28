cmake_minimum_required(VERSION 3.5)

###
# 指定为C++11 版本
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

add_executable(member src/1member.cpp)
add_executable(constructor src/2constructor.cpp)
add_executable(constructor_copy src/3constructor_copy.cpp)
add_executable(copy src/4copy.cpp)
add_executable(param_init src/5param_init.cpp)
add_executable(this src/6this.cpp)

add_executable(overload1_add src/7overload1_add.cpp)
add_executable(overload2_cout src/7overload2_cout.cpp)
add_executable(overload3_increase src/7overload3_increase.cpp)

add_executable(polymorphism1 src/8polymorphism1.cpp)
add_executable(polymorphism2 src/8polymorphism2.cpp)


