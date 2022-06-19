//
// Created by csk on 20/06/2022.
//

#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

class PersonWVirDes {
private:
    std::string firstName;
    std::string lastName;
    int randNb;
public:
    PersonWVirDes(std::string first, std::string last, int rand) : firstName(first), lastName(last), randNb(rand) {}
    virtual ~PersonWVirDes() { std::cout << "destructing Person with virtual destructor" << std::endl; }
    virtual std::string getName() const { return firstName + " " + lastName; }
    void setFirstName(std::string first) { firstName = first; }
    int getNb() const { return randNb; }
    void setNb(int rand) { randNb = rand; }
};

class PersonWoVirDes {
private:
    std::string firstName;
    std::string lastName;
    int randNb;
public:
    PersonWoVirDes(std::string first, std::string last, int rand) : firstName(first), lastName(last), randNb(rand) {}
    ~PersonWoVirDes() { std::cout << "destructing Person without virtual destructor" << std::endl; }
    virtual std::string getName() const { return firstName + " " + lastName; }
    void setFirstName(std::string first) { firstName = first; }
    int getNb() const { return randNb; }
    void setNb(int rand) { randNb = rand; }
};

#endif // PERSON_H
