//
// Created by csk on 18/06/2022.
//

#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
private:
    std::string firstName;
    std::string lastName;
    int randNb;
    void printInitMsg();
public:
    Person(std::string first, std::string last, int rand);
    Person();
    ~Person();
    std::string getName();
    int getNb();
};

#endif //PERSON_H
