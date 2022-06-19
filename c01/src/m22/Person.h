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
    virtual ~Person() {} // if you don't mark this as "virtual", during indirection on "Tweeter" using "Person" pointer,
    // only the "Person" destructor will run, and the "Tweeter" destructor will never run
    // hence, "Tweeter" resources will never be cleaned up causing memory leak
    std::string getName() const { return firstName + " " + lastName; }
    virtual std::string getNameVir() const { return getName(); } // just illustrating which function will be called when using virtual
    void setFirstName(std::string first) { firstName = first; }
    int getNb() const { return randNb; }
    void setNb(int rand) { randNb = rand; }
};


#endif // PERSON_H
