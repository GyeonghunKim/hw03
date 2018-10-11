cmake_minimum_required(VERSION 3.12)
project(hw03)

# set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -fopenmp")

add_executable(hw03 main.cpp primes.hpp)