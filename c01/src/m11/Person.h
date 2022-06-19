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
    friend bool operator<(int i, Person const& p); // here you are just saying that there is a function somewhere,
    // who is a friend and can access the private members
public:
    Person(std::string first, std::string last, int rand);
    Person();
    ~Person();
    // now there is no getter for "randNb" hence only friends can access it
    std::string getName() const{ return firstName + " " + lastName; }
    void setNb(int nb){ randNb = nb; }

    bool operator<(Person const& p) const;
    bool operator<(int i) const;
};

bool operator<(int i, Person const& p);

#endif //PERSON_H
