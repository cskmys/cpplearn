//
// Created by csk on 20/06/2022.
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
    Person(std::string first, std::string last, int rand) : firstName(first), lastName(last), randNb(rand) {}
    virtual ~Person() {}
    virtual std::string getName() const { return firstName + " " + lastName; }
    void setFirstName(std::string first) { firstName = first; }
    virtual int getNb() const { return randNb; }
    void setNb(int rand) { randNb = rand; }
};


#endif // PERSON_H
