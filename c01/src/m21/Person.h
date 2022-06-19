//
// Created by csk on 18/06/2022.
//

#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
#include <memory>
#include "Resource.h"

class Person {
private:
    std::string firstName;
    std::string lastName;
    int randNb;
    std::shared_ptr<Resource> pRsrc; // use "shared_ptr" when you want to have only one instance of your resource to be shared across multiple objects

public:
    Person(std::string first, std::string last, int rand) : firstName(first), lastName(last), randNb(rand){} // initializing "pRsrc" to null not needed, it is automatically done by "shared_ptr"
    void setFName(std::string first) { firstName = first; }
    std::string getName() const { return firstName + " " + lastName; }
    void setNb(int nb) { randNb = nb; }
    int getNb() const { return randNb; }

    void addRsrc();
    std::string getRsrcName() const { return pRsrc ? pRsrc->getName() : ""; } // both "shared_ptr" and "unique_ptr" when they do not point anywhere they return null

};

#endif //PERSON_H
