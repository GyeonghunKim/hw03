//
// Created by ghkim on 18. 10. 11.
//
// Many version of get_prime_under()
// Please see development note in README.md for detail ideas about each functions.
//
// I misunderstood about "sieve of Eratosthenes" algorithm. So get_prime_under_v1() ~ get_prime_under_v5()
// is sooooooo bad programs. But Ideas for optimization is used in the following functions.
//
// I use -O3 -Ofast compiler flag for optimization.
//
// I tried to change one thing in one version change to make clear the factor which make function faster than before.

# pragma once

#include <iostream>
#include <vector>
#include <array>
#include <chrono>
#include <cmath>
#include <list>
#include <omp.h>
#include <algorithm>
#include "utils.hpp"

#define VERBOSE false


// first version of get_prime_under() with WRONG "sieve of Eratosthenes"
auto get_prime_under_v1(const int max_val){
    // vector of int type.
    // if isNotPrime[i] is true, i is not prime.
    std::vector<int> isNotPrime(max_val+1);
    isNotPrime[0] = 1;
    isNotPrime[1] = 1;
    int j;
    int k;
    for(int i = 2; i < (max_val + 1); ++i){
        if(isNotPrime[i]){ continue; }
        int sqi = std::pow(i, 0.5);
        for (j = 2; j < sqi; ++j){
            if(i%j == 0){
                isNotPrime[i] = 1;
                break;
            }
        }
        k = 2;
        while (k * i < max_val + 1) {
            isNotPrime[k * i] = 1;
            k++;
        }
    }

    auto PrimeList = isNotPrime2PrimeList_vec_array(isNotPrime);

    return PrimeList;
}

// Second version of get_prime_under() with WRONG "sieve of Eratosthenes"
// I use std::sqrt() instead of std::pow(, 0.5)
// I compare two function using compare_sqrt_and_pow() in testing_experiments.hpp
auto get_prime_under_v2(const int max_val){
    // vector of int type.
    // if isNotPrime[i] is true, i is not prime.
    std::vector<int> isNotPrime(max_val+1);
    int k;
    isNotPrime[0] = 1;
    isNotPrime[1] = 1;
    int j;
    for(int i = 2; i < (max_val + 1); ++i){
        if(isNotPrime[i]){ continue; }
        int sqi = std::sqrt(i);
        for (j = 2; j < sqi; ++j){
            if(i%j == 0){
                isNotPrime[i] = 1;
                break;
            }
        }
        k = 2;
        while (k * i < max_val + 1) {
            isNotPrime[k * i] = 1;
            k++;
        }
    }


    auto PrimeList = isNotPrime2PrimeList_vec_array(isNotPrime);

    return PrimeList;
}

// Third version of get_prime_under() with WRONG "sieve of Eratosthenes"
// use (i * i < j) instead of (i < std::sqrt(j))
// I didn't compare difference of these two independently. But get_prime_under_v3() is little faster than get_prime_under_v2()
auto get_prime_under_v3(const int max_val){
    // vector of int type.
    // if isNotPrime[i] is true, i is not prime.
    std::vector <int> isNotPrime(max_val+1);

    int k;
    isNotPrime[0] = 1;
    isNotPrime[1] = 1;
    int j;
    for(int i = 2; i < (max_val + 1); ++i){
        if(isNotPrime[i]){ continue; }
        for (j = 2; j * j < i; ++j){
            if(i%j == 0){
                isNotPrime[i] = 1;
                break;
            }
        }
        k = 2;
        while (k * i < max_val + 1) {
            isNotPrime[k * i] = 1;
            k++;
        }
    }

    auto PrimeList = isNotPrime2PrimeList_vec_array(isNotPrime);


    return PrimeList;
}


// Fourth version of get_prime_under() with WRONG "sieve of Eratosthenes"
// skip the even number in for loop
// But I makes code little more slower... I don't know what is the reason.
auto get_prime_under_v4(const int max_val){
    // vector of int type.
    // if isNotPrime[i] is true, i is not prime.
    std::vector <int> isNotPrime(max_val+1);
    int k;
    isNotPrime[0] = 1;
    isNotPrime[1] = 1;
    int j;
    for(int i = 3; i < (max_val + 1); i+=2){
        if(isNotPrime[i]){ continue; }
        for (j = 2; j * j < i; ++j){
            if(i%j == 0){
                isNotPrime[i] = 1;
                break;
            }
        }
        k = 2;
        while (k * i < max_val + 1) {
            isNotPrime[k * i] = 1;
            k++;
        }
    }
    auto PrimeList = isNotPrime2PrimeList_vec_array(isNotPrime);

    return PrimeList;

}

// I create isNotPrime2PrimeList_vec2() in utils.hpp and tested it by compare get_prime_under_v5() with get_prime_under_v4()
// But get_prime_under_v4() is faster than get_prime_under_v5()
auto get_prime_under_v5(const int max_val){
    // vector of int type.
    // if isNotPrime[i] is true, i is not prime.
    std::vector <int> isNotPrime(max_val+1);
    int k;
    isNotPrime[0] = 1;
    isNotPrime[1] = 1;
    int j;
    for(int i = 2; i < (max_val + 1); ++i){
        if(isNotPrime[i]){ continue; }
        for (j = 2; j * j < i; ++j){
            if(i%j == 0){
                isNotPrime[i] = 1;
                break;
            }
        }
        k = 2;
        while (k * i < max_val + 1) {
            isNotPrime[k * i] = 1;
            k++;
        }
    }

    auto PrimeList = isNotPrime2PrimeList_vec2(isNotPrime);
    return PrimeList;
}


// First version of get_prime_under() with CORRECT "sieve of Eratosthenes"
auto get_prime_under_v6(const int max_val){
    std::vector<int> isNotPrime(max_val+1);
    int k;
    isNotPrime[0] = 1;
    isNotPrime[1] = 1;
    auto sqt = int(std::sqrt(max_val + 1));
    for(int i = 2; i < sqt; ++i){
        if(!isNotPrime[i]) {
            k = i;
            while (k * i < max_val + 1) {
                isNotPrime[k * i] = 1;
                ++k;
            }
        }
    }

    auto PrimeList = isNotPrime2PrimeList_vec_array(isNotPrime);

    return PrimeList;
}

// I tried to use std::list
// This is function is quite much slower than other functions using std::vector.
auto get_prime_under_v7(const int max_val){
    std::list<int> isNotPrime(max_val-1);
    int k = 1;
    for(auto it = begin(isNotPrime), e = end(isNotPrime); it != e; ++it){
        *it = ++k;
    }
    auto it1 = begin(isNotPrime), e = end(isNotPrime);

    while(it1 != e){
        int i = *it1;
        int mark = 1;
        for(auto it2 = begin(isNotPrime); it2 != it1; ++it2){
            int j = *it2;
            if(i%j == 0){
                it1 = isNotPrime.erase(it1);
                mark = 0;
                break;
            }
        }
        if(mark){++it1;}
    }

    return isNotPrime;

}

// Third version of get_prime_under() with CORRECT "sieve of Eratosthenes"
// I use while instead of for loop
// I compared while and for loop with while_vs_for() in testing_experiments.hpp and while is quite much faster than for loop.
auto get_prime_under_v8(const int max_val){

    std::vector<int> isNotPrime(max_val+1);
    int k;
    isNotPrime[0] = 1;
    isNotPrime[1] = 1;
    // auto sqt = int(std::sqrt(max_val + 1));
    for(int i = 2; i*i < (max_val + 1); ++i){
        if(!isNotPrime[i]) {
            k = i;
            while (k * i < max_val + 1) {
                isNotPrime[k * i] = 1;
                ++k;
            }
        }
    }

    auto PrimeList = isNotPrime2PrimeList_vec_array(isNotPrime);

    return PrimeList;
}

// Fourth version of get_prime_under() with CORRECT "sieve of Eratosthenes"
// I remove all for loops/
// version 9 is faster than version 8 and version 7.
auto get_prime_under_v9(const int max_val){
    std::vector<int> isNotPrime(max_val+1);
    int k;
    isNotPrime[0] = 1;
    isNotPrime[1] = 1;
    int i = 2;
    while(i*i < (max_val + 1)){
        if(!isNotPrime[i]) {
            k = i;
            while (k * i < max_val + 1) {
                isNotPrime[k * i] = 1;
                ++k;
            }
        }
        ++i;
    }

    auto PrimeList = isNotPrime2PrimeList_vec_array3(isNotPrime);

    return PrimeList;
}

// Fifth version of get_prime_under() with CORRECT "sieve of Eratosthenes"
// I change codes in first while loop.
// I change this because I think version 10 has less operation than version 9.
// Little bit faster than before.
auto get_prime_under_v10(const int max_val){
    std::vector<int> isNotPrime(max_val+1);
    int k;
    isNotPrime[0] = 1;
    isNotPrime[1] = 1;
    int i = 2;
    while(i*i < (max_val + 1)){
        // this part is changed.
        if(isNotPrime[i]){++i; continue;}
        k = i;
        while (k * i < max_val + 1) {
            isNotPrime[k * i] = 1;
            ++k;
        }
        ++i;
    }

    auto PrimeList = isNotPrime2PrimeList_vec_array3(isNotPrime);

    return PrimeList;
}

// Sixth version of get_prime_under() with CORRECT "sieve of Eratosthenes"
// I change codes in first while loop.
// I change this because I think version 10 has less operation than version 9.
// Little bit faster than before.
auto get_prime_under_v11(const int max_val){
    auto max_val_plus_one = max_val+1;
    std::vector<int> isNotPrime(max_val+1);
    int k;
    isNotPrime[0] = 1;
    isNotPrime[1] = 1;
    int i = 2;

    while(i*i < max_val_plus_one){
        if(isNotPrime[i]){++i; continue;}
        k = i;
        while (k * i < max_val_plus_one) {
            isNotPrime[k * i] = 1;
            ++k;
        }
        ++i;
    }

    auto PrimeList = isNotPrime2PrimeList_vec_array3(isNotPrime);

    return PrimeList;
}

// Last version of get_prime_under() with CORRECT "sieve of Eratosthenes"
// I include some lines about exception processing.
// Display "Not Good Input" when input max_val is smaller than 2
auto get_prime_under_last_version(const int max_val){
    if (max_val < 2) {
        std::vector<int> isNotPrime;
        return isNotPrime2PrimeList_vec_array3(isNotPrime);
    }
    auto max_val_plus_one = max_val+1;
    std::vector<int> isNotPrime(max_val+1);
    int k;
    isNotPrime[0] = 1;
    isNotPrime[1] = 1;
    int i = 2;

    while(i*i < max_val_plus_one){
        if(isNotPrime[i]){++i; continue;}
        k = i;
        while (k * i < max_val_plus_one) {
            isNotPrime[k * i] = 1;
            ++k;
        }
        ++i;
    }

    auto PrimeList = isNotPrime2PrimeList_vec_array3(isNotPrime);

    return PrimeList;
}





// In "sieve of Eratosthenes", except for 2 and 3, we only have to check 6 * N +_ 1
// Let's call this method as Modified "sieve of Eratosthenes"
// First version of get_prime_under() with Modified "sieve of Eratosthenes"
// Little bit faster than before.
auto get_prime_under_v12(const int max_val){
    auto max_val_plus_one = max_val+1;
    std::vector<int> isNotPrime(max_val_plus_one, 1);
    int k;
    isNotPrime[2] = 0;
    isNotPrime[3] = 0;
    isNotPrime[5] = 0;
    auto tmp = 2;
    k = 2;
    while (k * 2 < max_val_plus_one) {
        isNotPrime[k * tmp] = 1;
        ++k;
    }

    for(int i = 1; 6*i < max_val_plus_one; ++i){
        auto tmp = 6*i;
        isNotPrime[tmp+1] = 0;
        isNotPrime[tmp+5] = 0;
    }
    int i = 6;
    while(i*i < max_val_plus_one){
        auto i1 = i-1;
        if(!isNotPrime[i1]){
            k = i1;
            while (k * i1 < max_val_plus_one) {
                isNotPrime[k * i1] = 1;
                ++k;
            }
        }
        i1 = i+1;
        if(!isNotPrime[i1]){
            k = i1;
            while (k * i1 < max_val_plus_one) {
                isNotPrime[k * i1] = 1;
                ++k;
            }
        }
        i+=6;
    }

    auto PrimeList = isNotPrime2PrimeList_vec_array3(isNotPrime);

    return PrimeList;
}


// In "sieve of Eratosthenes", except for 2 and 3, we only have to check 6 * N +_ 1
// Let's call this method as Modified "sieve of Eratosthenes"
// First version of get_prime_under() with Modified "sieve of Eratosthenes"
// Little bit faster than before.
auto get_prime_under_v13(const int max_val){
    auto max_val_plus_one = max_val+1;
    std::vector<int> isNotPrime(max_val_plus_one);
    int k = 0;
    int i = 6;
    while(i*i < max_val_plus_one){
        auto i1 = i-1;
        if(!isNotPrime[i1]){
            k = i1;
            while (k * i1 < max_val_plus_one) {
                isNotPrime[k * i1] = 1;
                ++k;
            }
        }
        i1 = i+1;
        if(!isNotPrime[i1]){
            k = i1;
            while (k * i1 < max_val_plus_one) {
                isNotPrime[k * i1] = 1;
                ++k;
            }
        }
        i+=6;
    }
    auto PrimeList = isNotPrime2PrimeList_vec_array3_6n(isNotPrime);

    return PrimeList;
}




