//
// Created by csk on 18/06/2022.
//

#include "Tweeter.h"

#include <iostream>

using std::cout;
using std::endl;
using std::string;

Tweeter::Tweeter(string first, string last, int rand, string handle) : Person(first, last, rand), twitterHandle(handle) {
    // no matter what order you write, the base class gets constructed first, and then the inherited class gets constructed
    cout << "constructing tweeter " << twitterHandle << endl;
}

Tweeter::~Tweeter() { // the inherited class gets destructed first and then the base class
    cout << "destructing tweeter " << twitterHandle << endl;
}
