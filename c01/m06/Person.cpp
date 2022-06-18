//
// Created by csk on 18/06/2022.
//

#include "Person.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

Person::Person(std::string first, std::string last, int rand) : firstName(first), lastName(last), randNb(rand){
    printInitMsg();
}

Person::Person() : randNb(5) {
    printInitMsg();
}

Person::~Person() {
    cout << "destructing " << firstName << " " << lastName << endl;
}

void Person::printInitMsg() {
    cout << "constructing " << firstName << " " << lastName << endl;
}

string Person::getName() {
    return firstName + " " + lastName;
}

int Person::getNb() {
    return randNb;
}
