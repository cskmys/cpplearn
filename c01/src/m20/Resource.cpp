//
// Created by csk on 19/06/2022.
//

#include "Resource.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

Resource::Resource(string n) : name(n) {
    cout << "Constructing " << name << endl;
}

Resource::~Resource() {
    cout << "Destructing " << name << endl;
}
