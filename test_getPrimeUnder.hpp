//
// Created by ghkim on 18. 10. 15.
//

#pragma once
#include <functional>
#include <iostream>
#include <vector>

template <typename T>
bool test_isCorrect(T func, const std::string& function_name){
    std::vector<int> prime_under_200_true = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199};
    auto prime_under_200_from_func = func(200);
    bool isTrue = true;
    auto length = prime_under_200_from_func.size();
    for(int i = 0; i < length; ++i){
        if(prime_under_200_from_func[i] != prime_under_200_true[i]){
            isTrue = false;
            std::cout << "test failed -> " << function_name << "\n";
            break;
        }
    }
    if (isTrue){
        std::cout << "test passed -> " << function_name << "\n";
    }
    return isTrue;
}

// It just run functions in box with star...
template <typename T>
auto test_time(T func, int N){
    std::cout << "****************************************************************************************" << std::endl;
    std::cout << "get prime under " << N << std::endl;
    auto prime_under_200_from_func = func(N);
    std::cout << "****************************************************************************************" << std::endl;
}
