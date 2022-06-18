//
// Created by csk on 18/06/2022.
//

#include <iostream>

#include "utility.h"

using std::cout;
using std::endl;
using std::cin;

int main(){
    int x;
    cout << "Enter a number" << endl;
    cin >> x;

    cout << x << " is " << (isPrime(x) ? "" : "not ") << "a prime" << endl;
    cout << x << " is " << (is2MorePrime(x) ? "" : "not ") << "a prime" << endl;

    cout << x << " is " << (is2MorePrimeRef(x) ? "" : "not ") << "a prime" << endl;
    cout << x << " is " << (is2MorePrimeRefConst(x) ? "" : "not ") << "a prime" << endl;
    cout << x << " is " << (is2MorePrimeRefConst(x) ? "" : "not ") << "a prime" << endl;

    int a = badFunc();
    cout << "to crash code, we read \"a\"" << a << endl;
    return 0;
}
