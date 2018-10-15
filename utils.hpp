//
// Created by ghkim on 18. 10. 15.
//

#pragma once

#include <iostream>
#include <vector>
#include <array>
#include <list>

// print vector or array
// It prints like [1, 2, ..., 100]
template <typename T>
auto print_vec_array(const T &container){
    std::cout << "[ ";
    int length = container.size();
    for(int i = 0; i < length; ++i){
        std::cout << container[i] << "  ";
    }
    std::cout << "]" << std::endl;
}


// print list
// It prints like [1, 2, ..., 100]
template <typename T>
auto print_list(const T &l){
    std::cout << "[ ";
    for(auto it = begin(l), e = end(l); it != e; ++it){
        std::cout << *it << "  ";
    }
    std::cout << "]" << std::endl;
}

// This function calculate sum of some input vector or array
template <typename T>
auto sum_vec_array(const T &V){
    auto sum = V[0];
    int length = V.size();
    for(int i = 1; i < length; ++i){
        sum += V[i];
    }
    return sum;
}

// This function calculate sum of some input list
template <typename T>
auto sum_list(const T &isNotPrime){
    auto it = begin(isNotPrime);
    auto sum = *it;
    ++it;
    for(auto e = end(isNotPrime); it != e; ++it){
        sum += *it;
    }
    return sum;
}


template <typename T>
auto isNotPrime2PrimeList_vec_array(const T &isNotPrime){
    int max_size = isNotPrime.size();
    int length = isNotPrime.size() - sum_vec_array(isNotPrime);
    T PrimeList(length);
    int j = 0;
    for(int i = 2; i < max_size; ++i){
        if(!isNotPrime[i]){
            PrimeList[j++] = i;
        }
    }
    return PrimeList;
}

template <typename T>
auto isNotPrime2PrimeList_list(const T &isNotPrime){
    int max_size = isNotPrime.size();
    int length = isNotPrime.size() - sum_list(isNotPrime);
    std::vector<int> PrimeList(length);
    int j = 0;
    int k = 1;
    for(auto it = begin(isNotPrime), e = end(isNotPrime); it != e; ++it){
        if(!(*it)){
            PrimeList[j++] = k;
        }
        ++k;
    }
    return PrimeList;
}

template <typename T>
auto isNotPrime2PrimeList_vec_array2(const T &isNotPrime){
    int max_size = isNotPrime.size();
    T PrimeList;
    PrimeList.reserve(max_size);
    int j = 0;
    for(int i = 2; i < max_size; ++i){
        if(!isNotPrime[i]){
            PrimeList[j++] = i;
        }
    }
    PrimeList.shrink_to_fit();
    return PrimeList;
}
