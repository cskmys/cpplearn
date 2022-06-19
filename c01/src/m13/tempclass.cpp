#include <iostream>

#include "Accum.h"

using std::cout;
using std::endl;
using std::string;

int main(){

    Accum<int> integers(0);
    /*
    Accum integers(0); // throws compilation error in all versions before C++17
    // compiler doesn't know the type of "T" in the template that it should generate code with
    // in C++17, this is automatically deduced, and hence no error
    */
    integers += 3;
    integers += 7;
    cout << integers << endl;

    Accum<string> strings("");
    strings += "Hello";
    strings += " ";
    strings += "world";
    cout << strings << endl;

    return 0;
}
