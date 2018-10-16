Get prime numbers under input N
===============================
## 0. prelim.
This is for homework 3 of SNU TPCS2 class  
Codes related to measuring program operating time and run test refer to Eric(TA)'s code.  
I use -O3 -Ofast compiler flag for optimization.
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
    7. isNotPrime2PrimeList_vec_array2()
    8. isNotPrime2PrimeList_vec_array3()
    9. isNotPrime2PrimeList_vec_array3_6n()

* **primes.hpp**
    1. get_prime_under_v1()
    2. get_prime_under_v2()
    3. get_prime_under_v3()
    4. get_prime_under_v4()
    5. get_prime_under_v5()
    6. get_prime_under_v6()
    7. get_prime_under_v7()
    8. get_prime_under_v8()
    9. get_prime_under_v9()
    10. get_prime_under_v10()
    11. get_prime_under_v11()
    12. get_prime_under_v12()
    13. get_prime_under_v13()
    
* **test_getPrimeUnder.hpp**
    1. test_isCorrect_vec_arr()
    2. estimate_time()

* **testing_experiments.hpp**
    1. compare_sqrt_and_pow()
    2. container_access_time_test()
    3. int_bool_vector_access_time_test()
    4. while_vs_for()

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
7. I try to use std::list. But it's sooooooooooo slow...
8. I create get_prime_under_v8() based on get_prime_under_v6(). calculate square every for loop like (3)
=> little more faster, same time scale.
9. I found that while is faster than for loop. See while_vs_for() in testing_experiments.hpp
I use while instead of for loop. 
I also create isNotPrime2PrimeList_vec_array3() which use while loop instead of for loop
=> little more faster, same time scale.(But compared to the previous one, it is relatively large.)
10. I think Code 2 is faster than Code 1. Because Code 2 has less operation. 
```cpp
// Code 1 
while(some conditions){
    if(!isNotPrime){
    ~ ~ ~ ~
    }
}

// Code 2
while(some conditions){
    if(isNotPrime) break;
    ~ ~ ~ ~
} 
```
So I create get_prime_under_v10() which look like Code 2.  
It makes my code 2 times faster!  
10.  I use some compiler flags and I found that -O3 -Ofast flag make my code quiet faster. 
=> Now I can get prime under (2^30 -1) in 18s!!!!
But My I can increase input size because of memory error... (my computer is 8GB memeory)
11. I pre_calculate auto max_val_plus_one = max_val + 1 because In loop, It calculate so many times.  
=> little bit faster
12. I found that accessing speed for array is so much faster than accessing speed for vector with compiler flag -O3 -Ofast
13. In "sieve of Eratosthenes", except for 2 and 3, we only have to check 6 * N +_ 1.  
Let's call this method as Modified "sieve of Eratosthenes"  
With this algorithm, I create get_prime_under_v11() and get_prime_under_v12() in primes.hpp and isNotPrime2PrimeList_vec_array3_6n() in utils.hpp
=> It makes code little faster but, not change order.
14. I found that with compiler flag -O3 -Ofast, accessing to array is soooooo much faster than accessing to vector....
=> But I can't find smart methods to declare array with size which is variable...