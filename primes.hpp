//
// Created by ghkim on 18. 10. 11.
//

# pragma once

#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>


auto sum_vector(const std::vector<int> &V){
    int sum = 0;
    int length = V.size();
    for(int i = 0; i < length; ++i){
        sum += V[i];
    }
    return sum;
}

auto print_vector(const std::vector<int> &v){
    std::cout << "[ ";
    int length = v.size();
    for(int i = 0; i < length; ++i){
        std::cout << v[i] << "  ";
    }
    std::cout << "]" << std::endl;
}

auto print_vector(const std::vector<time_t> &v){
    std::cout << "[ ";
    int length = v.size();
    for(int i = 0; i < length; ++i){
        std::cout << v[i] << "  ";
    }
    std::cout << "]";
}
auto isNotPrime2PrimeList(const std::vector<int> &isNotPrime){
    int max_size = isNotPrime.size();
    int length = isNotPrime.size() - sum_vector(isNotPrime);
    std::vector<int> PrimeList(length);
    int j = 0;
    for(int i = 2; i < max_size; ++i){
        if(!isNotPrime[i]){
            PrimeList[j++] = i;
        }
    }
    return PrimeList;
}

// for N = 2^25-1, elapsed time: 19.7774s
auto get_prime_under_v1(const int max_val){
    // time - things are from Eric's github
    std::chrono::time_point<std::chrono::system_clock> start, stop;
    start = std::chrono::system_clock::now();
    std::vector <int> isNotPrime(max_val+1);
    int k;
    isNotPrime[0] = 1;
    isNotPrime[1] = 1;
    int j;
    for(int i = 2; i < (max_val + 1); ++i){
        // std::cout << i << std::endl;
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
        // print_vector(isNotPrime);
    }

    auto PrimeList = isNotPrime2PrimeList(isNotPrime);

    auto finish = std::chrono::high_resolution_clock::now();
    stop = std::chrono::system_clock::now();

    // From Eric's code.
    std::chrono::duration<double> elapsed_seconds = stop - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(stop);

    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << "s\n";

    return PrimeList;

}

// use sqrt instead pow( ,0.5);
// for N = 2^25-1, elapsed time: 19.6116s
auto get_prime_under_v2(const int max_val){
    // time - things are from Eric's github
    std::chrono::time_point<std::chrono::system_clock> start, stop;
    start = std::chrono::system_clock::now();
    std::vector <int> isNotPrime(max_val+1);
    int k;
    isNotPrime[0] = 1;
    isNotPrime[1] = 1;
    int j;
    for(int i = 2; i < (max_val + 1); ++i){
        // std::cout << i << std::endl;
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
        // print_vector(isNotPrime);
    }

    auto PrimeList = isNotPrime2PrimeList(isNotPrime);

    auto finish = std::chrono::high_resolution_clock::now();
    stop = std::chrono::system_clock::now();

    // From Eric's code.
    std::chrono::duration<double> elapsed_seconds = stop - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(stop);

    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << "s\n";

    return PrimeList;

}


// for N = 2^25-1, elapsed time: 19.6116s
auto get_prime_under_v2(const int max_val){
    // time - things are from Eric's github
    std::chrono::time_point<std::chrono::system_clock> start, stop;
    start = std::chrono::system_clock::now();
    std::vector <int> isNotPrime(max_val+1);
    int k;
    isNotPrime[0] = 1;
    isNotPrime[1] = 1;
    int j;
    for(int i = 2; i < (max_val + 1); ++i){
        // std::cout << i << std::endl;
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
        // print_vector(isNotPrime);
    }

    auto PrimeList = isNotPrime2PrimeList(isNotPrime);

    auto finish = std::chrono::high_resolution_clock::now();
    stop = std::chrono::system_clock::now();

    // From Eric's code.
    std::chrono::duration<double> elapsed_seconds = stop - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(stop);

    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << "s\n";

    return PrimeList;

}
