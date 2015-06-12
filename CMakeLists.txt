cmake_minimum_required(VERSION 3.2)
project(CP5)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pedantic -Wall")

set(SOURCE_FILES TEST_29.cpp)
add_executable(CP5 ${SOURCE_FILES} TEST_29.cpp ex15_27_Bulk_quote.h ex15_15_Disc_quote.h ex15_03_Quote.h)