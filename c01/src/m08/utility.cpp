//
// Created by csk on 18/06/2022.
//

#include <iostream>

#include "utility.h"

using std::cout;
using std::endl;

bool isPrime(int x){
    bool prime = true;
    for (int i = 2; i < x/i; ++i) {
        int fact = x/i;
        if(fact * i == x){
            cout << "factor found: " << fact << endl;
            prime = false;
            break;
        }
    }
    return prime;
}

bool is2MorePrime(int x){ // pass by value
    x = x + 2; // here "x" is a copy, so changing it has no impact on original "x"
    return isPrime(x); // you can directly return the returned value from the function call
}

bool is2MorePrimeRef(int& x){ // pass by reference("&")
    x = x + 2; // here "x" is a reference, so changing it changes the original "x"
    return isPrime(x);
}

bool is2MorePrimeRefConst(int const& x){ // pass by const reference("const&")
    /*
    x = x + 2; // throws compilation error
    // here "x" is a const reference, so you cannot change it
    */
    return isPrime(x + 2);
}

int& badFunc(){
    int a = 3; // "a" comes into scope
    return a; // returning reference to "a" meaning address of "a"
} // "a" goes out of scope, hence, the address returned above is no longer valid meaning whatever was returned is a dangling reference
