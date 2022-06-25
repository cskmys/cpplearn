//
// Created by csk on 25/06/2022.
//

#include <iostream>
using std::cout;
using std::endl;

#include <memory>
using std::unique_ptr;

#include <exception>
using std::exception;

#include "Resource.h"

int main(){
    // RAII means resource acquisition is initialization
    // which means objects must own their resources
    try {
        auto x = new Resource("wo raii");
        throw exception();
        delete x; // never cleaned up
    } catch (exception &e) {
        cout << e.what() << endl;
    }

    try {
        unique_ptr<Resource> x(new Resource("raii"));
        throw exception();
    } catch (exception &e) {
        cout << e.what() << endl;
    }

    cout << "'wo raii' not cleaned up until end of program" << endl; // memory leak

    return 0;
}