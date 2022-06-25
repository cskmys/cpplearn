//
// Created by csk on 25/06/2022.
//

#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <exception>
using std::exception;
using std::out_of_range;

#include "Person.h"

int main(){
    try {
        Person Sid("Sid", "Stark", 0);
        cout << "this line will not print" << endl;
    } catch (out_of_range &e) {
        cout << "out of range exception:" << e.what() << endl;
    } catch (exception &e) {
        cout << e.what() << endl;
    }
    try {
        Person Sid("Sid", "Stark", 0);
        cout << "this line will not print" << endl;
    } catch (exception e) { // if you don't catch exception "e" by reference
        cout << e.what() << endl; // slicing happens and hence you won't see the intended error message which is more specific
    }

    return 0;
}