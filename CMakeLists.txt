cmake_minimum_required(VERSION 3.12)
project(hw03)

# set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-O3 -Ofast -std=c++17")
add_executable(hw03 main.cpp primes.hpp utils.hpp test_getPrimeUnder.hpp testing_experiments.hpp)