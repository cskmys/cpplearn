//
// Created by csk on 20/06/2022.
//

#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <algorithm>


int main(){
    auto isOdd = [](int nb){ return nb % 2 != 0; };
    // in a lambda, "[]" is capture clause, "()" is for passing the parameters, and "{}" is the body

    bool is3Odd = isOdd(3); // not calling the lambda, executing the lambda

    cout << is3Odd << endl;

    vector<int> nums{ 2, 3, 4, -1 , 1 };

    int odds = std::count_if(begin(nums), end(nums), isOdd);
    int evens = std::count_if(begin(nums), end(nums), [](int nb){ return nb % 2 == 0; }); // writing in place and using it is the most widely used

    cout << odds << endl;
    cout << evens << endl;

    return 0;
}