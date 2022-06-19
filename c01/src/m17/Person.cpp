//
// Created by csk on 18/06/2022.
//

#include "Person.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

Person::Person(std::string first, std::string last, int rand) : firstName(first), lastName(last), randNb(rand){
}

Person::Person() : randNb(5) {
}

Person::~Person() {
}

bool Person::operator<(Person const& p) const {
    return randNb < p.randNb;
}

bool Person::operator<(int i) const {
    return randNb < i;
}

bool operator<(int i, Person const& p){
    return i < p.getNb();
}

std::ostream& operator<<(std::ostream& o, Person const& p){
    o << p.getName();
    return o;
}