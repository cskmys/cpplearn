//
// Created by csk on 20/06/2022.
//

#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <exception>
#include <stdexcept>
#include "Noise.h"

class Person {
private:
    std::string firstName;
    std::string lastName;
    int randNb;
public:
    Person() : firstName(""), lastName(""), randNb(-1) {}
    Person(std::string first, std::string last, int rand) : firstName(first), lastName(last), randNb(rand) {
        Noise np("speaking");
        if (randNb == 0){
            throw std::invalid_argument("randNb cant be 0");
            std::cout << "this line will not print" << std::endl;
        }
    }
    std::string getName() const { return firstName + " " + lastName; }
    int getNb() const { return randNb; }
};


#endif // PERSON_H
