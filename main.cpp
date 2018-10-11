//
// Created by ghkim on 18. 10. 11.
//

#include <iostream>
#include <cmath>
#include "primes.hpp"
int main() {
    int N_max = std::pow(2,25) - 1;
    auto v = get_prime_under_v1(N_max);
    auto u = get_prime_under_v2(N_max);
    //print_vector(v);
    return 0;
}