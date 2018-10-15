//
// Created by ghkim on 18. 10. 11.
//

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

auto get_prime_under_v1(const int max_val){
    // time - things are from Eric's github
    std::chrono::time_point<std::chrono::system_clock> start, stop;
    start = std::chrono::system_clock::now();
    std::vector<int> isNotPrime(max_val+1);
    int k;
    isNotPrime[0] = 1;
    isNotPrime[1] = 1;
    int j;
    for(int i = 2; i < (max_val + 1); ++i){
        if(VERBOSE) std::cout << i << std::endl;
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
        if(VERBOSE) print_vec_array(isNotPrime);
    }


    auto PrimeList = isNotPrime2PrimeList_vec_array(isNotPrime);
    auto finish = std::chrono::high_resolution_clock::now();
    stop = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = stop - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(stop);

    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << "s\n";

    return PrimeList;
}


auto get_prime_under_v2(const int max_val){
    // time - things are from Eric's github
    std::chrono::time_point<std::chrono::system_clock> start, stop;
    start = std::chrono::system_clock::now();
    std::vector<int> isNotPrime(max_val+1);
    int k;
    isNotPrime[0] = 1;
    isNotPrime[1] = 1;
    int j;
    for(int i = 2; i < (max_val + 1); ++i){
        if(VERBOSE) std::cout << i << std::endl;
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
        if(VERBOSE) print_vec_array(isNotPrime);
    }


    auto PrimeList = isNotPrime2PrimeList_vec_array(isNotPrime);
    auto finish = std::chrono::high_resolution_clock::now();
    stop = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = stop - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(stop);

    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << "s\n";

    return PrimeList;
}


auto get_prime_under_v3(const int max_val){
    // time - things are from Eric's github


    std::chrono::time_point<std::chrono::system_clock> start, stop;
    start = std::chrono::system_clock::now();
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
    auto finish = std::chrono::high_resolution_clock::now();
    stop = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = stop - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(stop);
    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << "s\n";

    return PrimeList;
}


// skip the even number in for loop....
auto get_prime_under_v4(const int max_val){
    std::chrono::time_point<std::chrono::system_clock> start, stop;
    start = std::chrono::system_clock::now();
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
    auto finish = std::chrono::high_resolution_clock::now();
    stop = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = stop - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(stop);

    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << "s\n";


    return PrimeList;

}


auto get_prime_under_v5(const int max_val){
    std::chrono::time_point<std::chrono::system_clock> start, stop;
    start = std::chrono::system_clock::now();
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

    auto PrimeList = isNotPrime2PrimeList_vec_array2(isNotPrime);
    auto finish = std::chrono::high_resolution_clock::now();
    stop = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = stop - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(stop);
    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << "s\n";

    return PrimeList;
}

auto get_prime_under_v6(const int max_val){
    std::chrono::time_point<std::chrono::system_clock> start, stop;
    start = std::chrono::system_clock::now();
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
    auto finish = std::chrono::high_resolution_clock::now();
    stop = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = stop - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(stop);
    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << "s\n";

    return PrimeList;
}


