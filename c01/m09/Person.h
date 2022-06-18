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
    std::string getName() const; // member function declared as "const" to make sure that this function doesn't change any member variables
    int getNb() const{ return randNb; }; // very simple one line functions can be implemented "inline" in the header files
    void setNb(int nb){ randNb = nb; }; // we will need this member function to change the member variable value, hence we do not declare this as "const"
    /*
    void Person::setNbConstMemFunc(int nb) const {
        randNb = nb; // throws compilation error
        // the "const" above tells compiler that this function will not change any member variables
        // but by assignment we are changing the member variable, hence the error
    }
    */
};

#endif //PERSON_H
