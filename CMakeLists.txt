cmake_minimum_required(VERSION 3.3)
project(beauty_of_programming)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(beauty_of_programming ${SOURCE_FILES})