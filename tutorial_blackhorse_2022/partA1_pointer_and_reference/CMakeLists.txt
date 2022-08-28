cmake_minimum_required(VERSION 3.5)

###
set(CMAKE_BUILD_TYPE Debug)

add_executable(memory_global src/memory/memory_global.cpp)
add_executable(memory_stack src/memory/memory_stack.cpp)
add_executable(memory_heap src/memory/memory_heap.cpp)
add_executable(memory_new src/memory/memory_new.cpp)

add_executable(pointer_basic src/pointer/pointer_basic.cpp)
add_executable(pointer_const src/pointer/pointer_const.cpp)
add_executable(pointer_array src/pointer/pointer_array.cpp)
add_executable(pointer_double src/pointer/pointer_double.cpp)


add_executable(reference_basic src/reference/reference_basic.cpp)
add_executable(reference_use src/reference/reference_use.cpp)
add_executable(reference_funparam src/reference/reference_funparam.cpp)
add_executable(reference_funreturn src/reference/reference_funreturn.cpp)
add_executable(reference_const src/reference/reference_const.cpp)

