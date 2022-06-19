//
// Created by csk on 18/06/2022.
//

#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

class Person {
private:
    std::string firstName;
    std::string lastName;
    int randNb;
public:
    Person(std::string first, std::string last, int rand);
    Person();
    ~Person();
    std::string getName() const{ return firstName + " " + lastName; }
    int getNb() const{ return randNb; }
    void setNb(int nb){ randNb = nb; }

    bool operator<(Person const& p) const; // comparing two instances of this class
    bool operator<(int i) const; // comparing instance of this class with an integer1
    // operator overloading using the member function,
    // the argument comes on the right side of the operator while the class itself will come on the left side
    // here, Person < integer works, not the other way around
};

// just putting this free function here as it is relevant to "Person" class
bool operator<(int i, Person const& p); // operator overloading via free function
// comparing an integer and an instance of "Person"
// The order of comparisons is in the order of the parameters
// hence here it works if is used as integer < Person, not the other way around
// here we had to resort to using a free function coz you wouldn't be able to overload the operator for the fundamental type integer

#endif //PERSON_H
