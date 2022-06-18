//
// Created by csk on 18/06/2022.
//

#include "Person.h"

Person::Person(std::string first, std::string last, int rand) : firstName(first), lastName(last), randNb(rand){
    // ":" everything after is called initializer list which is used to load the variables before running any initialization code

}

std::string Person::getName() {
    return firstName + " " + lastName; // member functions operate on member variables and arguments passed to them
}

int Person::getNb() {
    return randNb;
}

PersonWDef::PersonWDef(std::string first, std::string last, int rand) : firstName(first), lastName(last), randNb(rand) {

}
