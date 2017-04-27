cmake_minimum_required(VERSION 3.3)
project(beauty_of_programming)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        #        main.cpp
        #        ch0101_cpu_runtime.c
        #        ch0102_marshal_pos.c
        ch0103_group_sort.cpp)
add_executable(beauty_of_programming ${SOURCE_FILES})