//
// Created by ghkim on 18. 10. 11.
//

#include <iostream>
#include <cmath>
#include "primes.hpp"
int main() {
    int N_max = std::pow(2,28) - 1;
    // omp_test();
    //auto v = get_prime_under_v1(N_max);
    //auto u = get_prime_under_v2(N_max);
    // auto w = get_prime_under_v3(N_max);
    // auto p = get_prime_under_v3_withOMP(N_max);
    auto q = get_prime_under_v4(N_max);
    // print_vector(w);
    // print_vector(p);
    access_time_test();
    return 0;
}