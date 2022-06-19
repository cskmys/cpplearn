//
// Created by csk on 18/06/2022.
//

#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
#include "Resource.h"

class Person {
private:
    std::string firstName;
    std::string lastName; // for something that is mandatory, object is used
    int randNb;
    Resource *pRsrc; // for something that is optional, pointer to an object is used

public:
    Person(std::string first, std::string last, int rand) : firstName(first), lastName(last), randNb(rand), pRsrc(nullptr){}
    ~Person(){}
    Person(Person const& p); // copy constructor taking const reference to an object of the same type to build a new object instead of shallow copy
    Person& operator=(Person const& p); // simple assignment operator overloaded as a copy assignment operator to build a new object instead of shallow copy
    void setFName(std::string first) { firstName = first; }
    std::string getName() const { return firstName + " " + lastName; }
    void setNb(int nb) { randNb = nb; }
    int getNb() const { return randNb; }

    void addRsrc();
};

#endif //PERSON_H
