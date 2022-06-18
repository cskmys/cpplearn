//
// Created by csk on 18/06/2022.
//

#ifndef PERSON_H
#define PERSON_H

#include <string>

// don't ever use "using" statements in header files as it gets copied to several files.
// people using your header files may not want to get your "using" statements
class Person {
private:
    std::string firstName; // in header file always make it a point to call things by their full namespace names
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
