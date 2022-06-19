//
// Created by csk on 18/06/2022.
//

#include "Person.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

void Person::addRsrc() {
    /*
    pRsrc = new Resource("Rsrc for " + getName()); // will cause memory leak
    // just doing this will stomp out the old address and write a new one when called multiple times.
    // once an address is lost, that memory cannot be freed until program exits.
    */
    delete pRsrc; // now doing a pre-delete will ensure whatever currently exists is cleared before creating and assigning the new one
    // during the first, "pRsrc" is null, hence no issues
    pRsrc = new Resource("Rsrc for " + getName());
    // now, with delete above, this function can be called multiple times without any issues
    cout << "ending addRsrc" << endl;
    cout << endl;
}

Person::Person(const Person &p) {
    // this is a constructor, so you'll only need to create a new resource, there is no existing resource to bother about
    pRsrc = new Resource(p.pRsrc->getName()); // creating an independent copy instead of shallow copy
    cout << "ending copy constructor" << endl;
    cout << endl;
}

Person &Person::operator=(const Person &p) {
    // this code is not perfect as we are not checking for things such as self-assignment
    delete pRsrc;
    pRsrc = new Resource(p.pRsrc->getName());
    cout << "ending copy assignment" << endl;
    cout << endl;
    return *this;
}
