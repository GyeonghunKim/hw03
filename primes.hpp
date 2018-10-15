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

template <typename T>
auto sum_vector(const T &V){
    int sum = 0;
    int length = V.size();
    for(int i = 0; i < length; ++i){
        sum += int(V[i]);
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


auto print_list(const std::list<bool> &l){
    std::cout << "[ ";
    for(auto it = begin(l), e = end(l); it != e; ++it){
        std::cout << *it << "  ";
    }
    std::cout << "]" << std::endl;
}


template <typename T>
auto isNotPrime2PrimeList(const T &isNotPrime){
    int max_size = isNotPrime.size();
    int length = isNotPrime.size() - sum_vector(isNotPrime);
    T PrimeList(length);
    int j = 0;
    for(int i = 2; i < max_size; ++i){
        if(!isNotPrime[i]){
            PrimeList[j++] = i;
        }
    }
    return PrimeList;
}



// for N = 2^24-1, elapsed time: 7.61087s
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


// for N = 2^24-1, elapsed time: 7.59487s
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

// use j * j < i instead j < std::root(i)
// littttttttttttttttttttttttle bit faster...
// for N = 2^24-1, elapsed time: 7.30782s
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
        // std::cout << i << std::endl;
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

// use j * j < i instead j < std::root(i)
// littttttttttttttttttttttttle bit faster...
// for N = 2^24-1, elapsed time: 7.30782s
auto get_prime_under_v3_withOMP(const int max_val){
    // time - things are from Eric's github
    std::chrono::time_point<std::chrono::system_clock> start, stop;
    start = std::chrono::system_clock::now();
    std::vector <int> isNotPrime(max_val+1);
    isNotPrime[0] = 1;
    isNotPrime[1] = 1;
    // omp_set_num_threads(8);
    #pragma omp parallel for
    for(int i = 2; i < (max_val + 1); ++i){
        // std::cout << i << std::endl;
        if(isNotPrime[i]){ continue; }
        for (int j = 2; j * j < i; ++j){
            if(i%j == 0){
                isNotPrime[i] = 1;
                break;
            }
        }
        int k = 2;
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
void omp_test()
{
    int i;
    omp_set_num_threads(4);
    #pragma omp parallel
    for(i=0; i<100; i++)
        printf("%d Hello, World! Thread ID: %d\n",
               i,
               omp_get_thread_num());
}

void access_time_test(){
    std::vector<int> vec(1000000);
    std::array<int, 1000000> arr;

    std::chrono::time_point<std::chrono::system_clock> start, stop;
    start = std::chrono::system_clock::now();
    for(int i = 0; i < 1000000; ++i)
        vec[i] += 1;
    auto finish = std::chrono::high_resolution_clock::now();
    stop = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = stop - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(stop);
    std::cout << "vector elapsed time: " << elapsed_seconds.count() << "s\n";

    std::chrono::time_point<std::chrono::system_clock> start2, stop2;
    start2 = std::chrono::system_clock::now();
    for(int i = 0; i < 1000000; ++i)
        arr[i] += 1;
    auto finish2 = std::chrono::high_resolution_clock::now();
    stop2 = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds2 = stop2 - start2;
    std::time_t end_time2 = std::chrono::system_clock::to_time_t(stop);
    std::cout << "vector elapsed time: " << elapsed_seconds2.count() << "s\n";

}

// skip the even number in for loop....
// littttttttttttttle bit faster...
// for N = 2^24-1, elapsed time: 7.30782s
auto get_prime_under_v4(const int max_val){
    // time - things are from Eric's github


    std::chrono::time_point<std::chrono::system_clock> start, stop;
    start = std::chrono::system_clock::now();
    std::vector <int> isNotPrime(max_val+1);
    int k;
    isNotPrime[0] = 1;
    isNotPrime[1] = 1;
    int j;
    for(int i = 3; i < (max_val + 1); i+=2){
        // std::cout << i << std::endl;
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

// skip the even number in for loop....
// littttttttttttttle bit faster...
// for N = 2^24-1, elapsed time: 7.30782s
auto get_prime_under_v5(const int max_val){
    // time - things are from Eric's github
    
    std::chrono::time_point<std::chrono::system_clock> start, stop;
    start = std::chrono::system_clock::now();
    std::vector <int> isNotPrime(max_val+1);
    int k;
    isNotPrime[0] = 1;
    isNotPrime[1] = 1;
    int j;
    for(int i = 3; i < (max_val + 1); i+=2){
        // std::cout << i << std::endl;
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

auto sum_list(std::list<bool> isNotPrime){
    auto sum = 0;
    for(auto it = begin(isNotPrime), e = end(isNotPrime); it != e; ++it){
        sum += *it;
    }
    return sum;
}


auto isNotPrime2PrimeList_listversion(std::list<bool> isNotPrime){
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


// I implement with list but its soooooooooooooooooooooo slow...
auto get_prime_under_v6(const int max_val){
    // time - things are from Eric's github


    std::chrono::time_point<std::chrono::system_clock> start, stop;
    start = std::chrono::system_clock::now();

    std::list<bool> isNotPrime(max_val+1);
    int k = 2;
    auto it = begin(isNotPrime);
    auto e = end(isNotPrime);
    *it = 1;
    ++it;
    for(;it != e;){
        // std::cout << k << std::endl;
        // if number is not prime, mark set isNotPrime() = 1;
        for(auto j = 2; j < k; ++j){
            if(k%j == 0){
                *it = 1;
                break;
            }
        }
        // if run all for loop without break, number k is prime
        auto tmp_it = begin(isNotPrime);
        for(auto i = 0; i < (2 * k - 1); ++i){
            ++tmp_it;
        }
        // infinite loop...
        while(true){
            *tmp_it = 1;
            auto mrk = 0;
            for(auto kk = 0; kk < k; ++kk){
                ++tmp_it;
                if(tmp_it == e){
                    mrk = 1;
                    break;
                }
            }
            if(mrk){
                break;
            }
        }
        while(true){
            ++it;
            ++k;
            if(it == e) break;
            if(*it == 0) break;
        }
    }



    auto finish = std::chrono::high_resolution_clock::now();
    stop = std::chrono::system_clock::now();

    // From Eric's code.
    std::chrono::duration<double> elapsed_seconds = stop - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(stop);

    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << "s\n";
    auto PrimeList = isNotPrime2PrimeList_listversion(isNotPrime);

    return PrimeList;

}

