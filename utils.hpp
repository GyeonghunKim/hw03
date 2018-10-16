//
// Created by ghkim on 18. 10. 15.
//
// Utilities for this project.
// Some are used but some are replaced by other function or not used.
//
// List of functions:
//
// print_vec_arrat()
// print_list()
// sum_vec_arrat()
// sum_list()
// isNotPrime2PrimeList_vec_array()
// isNotPrime2PrimeList_list()
// isNotPrime2PrimeList_vec_array2()
// isNotPrime2PrimeList_vec_array3()
//
//


#pragma once

#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <cmath>


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

// this function create PrimeList from isNotPrime
// input data(isNotPrime) should be std::vector or std::array
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

// this function create PrimeList from isNotPrime
// input data(isNotPrime) should be std::list
template <typename T>
auto isNotPrime2PrimeList_list(const T &isNotPrime){
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

// this function create PrimeList from isNotPrime
// input data(isNotPrime) should be std::vector or std::array
// use method reserve and shrink_to_fit
// I don't use this function because isNotPrime2PrimeList_vec_array1() and isNotPrime2PrimeList_vec_array2()
// is faster.
template <typename T>
auto isNotPrime2PrimeList_vec2(const T &isNotPrime){
    int max_size = isNotPrime.size();
    T PrimeList;
    // siz is upper limit of prime-counting function
    // https://en.wikipedia.org/wiki/Prime-counting_function
    auto siz = int(max_size/std::log(max_size) * 1.3);
    PrimeList.reserve(siz);
    for(int i = 2; i < max_size; ++i){
        if(!isNotPrime[i]){
            PrimeList.push_back(i);
        }
    }
    PrimeList.shrink_to_fit();
    return PrimeList;
}

// This function is modified from isNotPrime2PrimeList_vec_array1()
// for loop is replaced by while loop because while loop is faster.
// Please see development note - 9 in README.md
// include some lines about exception processing.
template <typename T>
auto isNotPrime2PrimeList_vec_array3(const T &isNotPrime){
    if(isNotPrime.size() == 0){
        std::vector<int> PrimeList(0);
        std::cout << "Not Good Input" << std::endl;
        return PrimeList;
    }
    int max_size = isNotPrime.size();
    int length = isNotPrime.size() - sum_vec_array(isNotPrime);
    std::vector<int> PrimeList(length);
    int j = 0;
    int i = 2;
    while(i < max_size){
        if(!isNotPrime[i]){
            PrimeList[j++] = i;
        }
        ++i;
    }
    return PrimeList;
}


// This function is modified from isNotPrime2PrimeList_vec_array2()
// only pushback a number to PrimeList 6n plus minus 1
template <typename T>
auto isNotPrime2PrimeList_vec_array3_6n(const T &isNotPrime){
    int max_size = isNotPrime.size();
    T PrimeList;
    // siz is upper limit of prime-counting function
    // https://en.wikipedia.org/wiki/Prime-counting_function
    auto siz = int(max_size/std::log(max_size) * 1.3);
    PrimeList.reserve(siz);
    PrimeList.push_back(2);
    PrimeList.push_back(3);
    auto k = 0;
    for(int i = 0; i < (max_size+1)/6; ++i){
        k = 6*i+5;
        if(!isNotPrime[k]){
            PrimeList.push_back(k);
        }
        k += 2;
        if(k > max_size) break;
        if(!isNotPrime[k]){
            PrimeList.push_back(k);
        }
    }
    PrimeList.shrink_to_fit();
    return PrimeList;
}