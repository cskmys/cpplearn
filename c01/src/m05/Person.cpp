//
// Created by csk on 18/06/2022.
//

#include "Person.h"
#include <iostream>

using std::cout; // "using" construct used to specify that all "cout" are from "std" namespace unless specified
using std::endl;
// moreover, never ever write this "using" declaration in a header file

Person::Person(std::string first, std::string last, int rand) : firstName(first), lastName(last), randNb(rand){
    printInitMsg();
}

Person::Person() : randNb(5) { // you can initialize to whatever you want, and you don't have to initialize all the properties
    printInitMsg();
}

Person::~Person() {
    cout << "destructing " << firstName << " " << lastName << endl; // only "cout" and "endl" is written as they are declared above via "using" construct
}

void Person::printInitMsg() {
    cout << "constructing " << firstName << " " << lastName << endl; // variables already initialized in initializer list
}

std::string Person::getName() { // you'll still have to specify "std::string" as you have not declared it like you have done for "cout" and "endl"
    return firstName + " " + lastName;
}

int Person::getNb() {
    return randNb;
}
