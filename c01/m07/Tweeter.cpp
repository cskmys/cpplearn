//
// Created by csk on 18/06/2022.
//

#include "Tweeter.h"

#include <iostream>

using std::cout;
using std::endl;
using std::string;

Tweeter::Tweeter(string first, string last, int rand, string handle) : Person(first, last, rand), twitterHandle(handle) {
    cout << "constructing tweeter " << twitterHandle << endl;
}

Tweeter::~Tweeter() {
    cout << "destructing tweeter " << twitterHandle << endl;
}
