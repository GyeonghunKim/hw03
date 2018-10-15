//
// Created by ghkim on 18. 10. 11.
//

#include <iostream>
#include <cmath>
#include "primes.hpp"
#include "utils.hpp"
#include "test_getPrimeUnder.hpp"
#include "testing_experiments.hpp"
int main() {
    int N = std::pow(2, 29) - 1;
    // test_isCorrect(get_prime_under_v6, "get_prime_under_v6");
    // test_time(get_prime_under_v6, N);
    test_time(get_prime_under_v6, N);
    // test_isCorrect(get_prime_under_v7, "get_prime_under_v7");
    // auto tmp = get_prime_under_v7(100);
    // print_list(tmp);
    return 0;
}
