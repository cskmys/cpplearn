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
public:
    Person(std::string first, std::string last, int rand);
    std::string getName();
    int getNb();
}; // do not forget to put the semicolon here

class PersonWDef {
private:
    std::string firstName;
    std::string lastName;
    int randNb;

public:
    PersonWDef(std::string first, std::string last, int rand);
    PersonWDef()=default; // here we are not telling the compiler to generate default constructor despite having a constructor.
    // here we are actually writing the default constructor as it no longer generates one.
    // normally default constructor loads fundamental types with junk values by using this "default" keyword,
    // we are telling compiler to load fundamental types with default values instead of junk
};

#endif //PERSON_H
