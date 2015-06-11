cmake_minimum_required(VERSION 3.2)
project(CP5)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pedantic -Wall")

set(SOURCE_FILES TEST_26.cpp)
add_executable(CP5 ${SOURCE_FILES} ex15_26_Quote.h ex15_26_Bulk_quote.h)