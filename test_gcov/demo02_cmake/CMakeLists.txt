cmake_minimum_required(VERSION 3.10)
project(learn_gcov)

# set(CMAKE_CXX_STANDARD 11) 
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fprofile-arcs -ftest-coverage")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")

# set(CMAKE_CXX_FLAGS_RELEASE "-O0 -fopenmp")
# add_compile_options(-fprofile-arcs)
# add_compile_options(-ftest-coverage)
# add_compile_options(--coverage)
link_libraries(gcov)

add_executable(learn01 src/learn01.c)