//
// Created by ghkim on 18. 10. 11.
//
// SNU-ID: 2016-16746
//
// Homework 03
//
// In this homework, I create many version of functions which check prime
// number under some large number N
// It is sooo complicate to write all informations about my code in header, I create README.md file. Please read README.md
// I

#include <iostream>
#include <cmath>
#include "primes.hpp"
#include "utils.hpp"
#include "test_getPrimeUnder.hpp"
#include "testing_experiments.hpp"
int main() {

    auto N = std::pow(2,30) - 1;
    // get_prime_under_v13() takes 17s in my laptop to get prime number under 2^30 - 1
    std::cout << estimate_time(get_prime_under_v13, N) << std::endl;

    return 0;
}