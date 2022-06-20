//
// Created by csk on 20/06/2022.
//

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <algorithm>

int main(){
    vector<int> nums{ 2, 3, 4, -1 , 1 };

    int x = 3;
    int y = 7;
    string msg = "elements belonging to [";
    msg += std::to_string(x) + ", " + std::to_string(y) + "]: ";
    std::for_each(std::begin(nums), std::end(nums), [x, y, &msg](int n){ // capturing "x", "y" by value and "msg" by reference
        if (n >= x && n <= y){
            msg += std::to_string(n) + ", ";
        }
    });
    cout << msg << endl;

    x = y = 0;

    cout << "x: " << x << endl;
    cout << "y: " << y << endl;
    std::for_each(std::begin(nums), std::end(nums), [&, x](int element) mutable{ // "mutable" here is relevant to how "x" which is captured by value
        // it is not relevant to "y" as it is captured by reference
        // meaning, as "x" is copied we are saying that the local copy of the "x" can be changed by the code within the lambda
        // as "y" is captured by reference, there is no local copy of "y" in the lambda, and the reference "y" directly modifies the "y" outside
        // all this happens even if the keyword "mutable" was not used
        x += element;
        y += element;
    });
    cout << "x(captured by value): " << x << endl;
    cout << "y(captured by reference): " << y << endl;

    return 0;
}