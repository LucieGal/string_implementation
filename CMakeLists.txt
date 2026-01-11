cmake_minimum_required(VERSION 4.2)

project(string_project VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17) # Use C++17
add_executable(test string_tests.cpp String.cpp)
