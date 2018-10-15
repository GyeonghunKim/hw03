Get prime numbers under input N
===============================
## 0. prelim.
This is for homework 3 of SNU TPCS2 class  
Codes related to measuring program operating time and run test refer to Eric(TA)'s code.  

## 1. Basic information
In utils.cpp, it includes some functions about print, sum, ... etc..   
In primes.cpp, it includes some functions about get prime numbers under some input integer N  
In test_getPrimeUnder.cpp, it includes test functions which test whether functions in primes.cpp well  
In testing_experiments.cpp, it includes some testing about speed and etc..........  

## 2. Function list
* **utils.hpp**
    1. print_vec_array()
    2. print_list()
    3. sum_vec_array()
    4. sum_list()
    5. isNotPrime2PrimeList_vec_array()
    6. isNotPrime2PrimeList_list()
* **primes.hpp**
    1. get_prime_under_v1()
    2. get_prime_under_v2()
    3. get_prime_under_v3()
    4. get_prime_under_v4()
* **test_getPrimeUnder.hpp**
    1. 
    2. 
    3. 
    4. 
* **testing_experiments.hpp**
    1. test_getPrimeUnder()

## 3.Development Notes
* I wrote Development Notes in order of "question -> test -> new_code -> feed back -> question -> ...  "
1. I create get_prime_under_v1() using "Seive of Erotosthenes"  
 => It can calculate prime under ~(2^24) in 10s  
1 - 1. I compare std::sqrt() and std::pow(, 0.5). Function for test is in testing_experiments.hpp  
1 - 2. std::sqrt() is much faster than std::pow(,0.5) so I use std::sqrt() instead of std::pow(,0.5)
2. I create get_prime_under_v2() by replace std::pow(,0.5) to std::sqrt()  
 => It can calculate prime under ~(2^24) in 10s.  
 => Same order but little faster than version 1.   
2 - 1. I wonder whether would be faster to calculate square every for loop or calculate root once.
3. I create get_prime_under_v3() which calculate square every for loop
 => It can calculate prime under ~(2^24) in 10s.  
 => Same order but little faster than version 2.  
3 - 1. I want to compare vector and array's access speed. Function for test is in testing_experiments.hpp  
    => Access speed of vector is faster than array.  
4. I create get_prime_under_v4() whether skip the even number in for loop
 => It can calculate prime under ~(2^24) in 10s.  
 => Same order but little slower than version 3.  
 => HELP ME: I can understand this result.. 
4 - 1. I think that isNotPrime2PrimeList might be dominant factor.
 => Use method reserve() and shrink_to_fit() instead of calculate number of primes under N  
5. I create isNotPrime2PrimeList_vec_array2() and get_prime_under_v5()  
isNotPrime2PrimeList_vec_array2() use reserve() and shrink_to_fit() instead of calculate number of primes under N  
and get_prime_under_v5() use isNotPrime2PrimeList_vec_array2() instead of isNotPrime2PrimeList_vec_array() 
 => It can calculate prime under ~(2^24) in 10s.  
 => Same order but little faster than version 3.   
5 - 1. Maybe make isNotPrime is bool type array rather than int type array...  
5 - 1 - 1. I want to compare bool type vector and int type vector's access speed. Function for test is in testing_experiments.hpp  
5 - 1 - 2. int type is faster than bool type vector....  
6. I found that I misunderstood the algorithm "Seive of Erotosthenes"...
 => It can calculate prime under ~(2^27) in 10s .....!!!
