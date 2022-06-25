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

int main(){
    vector<int> v;
    v.push_back(1);
    try {
        int j = v.at(99);
        // if in case, you got the vector reference and its index from somewhere else, then you wouldn't be in a position to do anything
    } catch (out_of_range &e) { // "e" takes "out_of_range" exception class by reference
        cout << "out of range exception:" << e.what() << endl; // "what" gives a string that describes what went wrong in a loggable format
    } catch (exception &e) { // "e" takes "exception" base class by reference
        cout << e.what() << endl;
    }
    return 0;
}