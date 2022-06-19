//
// Created by csk on 18/06/2022.
//

#include "Person.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

void Person::addRsrc() {
    pRsrc.reset(); // instead of "delete"
    pRsrc = std::make_shared<Resource>("Rsrc for " + getName()); // instead of "new"

    cout << "ending addRsrc" << endl;
    cout << endl;
}
