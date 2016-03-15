cmake_minimum_required(VERSION 3.3)
project(Ind_arr)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Ind_arr ${SOURCE_FILES})