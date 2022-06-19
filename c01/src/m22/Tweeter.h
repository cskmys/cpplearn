//
// Created by csk on 20/06/2022.
//

#ifndef TWEETER_H
#define TWEETER_H

#include "Person.h"

class Tweeter : public Person {
private:
    std::string twitterHandle;
public:
    Tweeter(std::string first, std::string last, int rand, std::string handle) : Person(first, last, rand), twitterHandle(handle) {}
    ~Tweeter(){}
    std::string getName() const { return Person::getName() + " " + twitterHandle; } // to call the functionality from the base class
    std::string getNameVir() const { return getName(); }
};


#endif // TWEETER_H
