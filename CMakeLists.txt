cmake_minimum_required(VERSION 3.2)
project(CP5)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pedantic -Wall")

set(SOURCE_FILES TEST_30.cpp)
add_executable(CP5 ${SOURCE_FILES} TEST_30.cpp ex15_30_Basket.h ex15_30_Quote_Bulk_quote.h)