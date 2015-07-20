cmake_minimum_required(VERSION 3.2)
project(CP5)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pedantic -Wall")

set(SOURCE_FILES test.cpp)
add_executable(CP5 ${SOURCE_FILES} test.cpp ex13_49_StrVec.cpp)