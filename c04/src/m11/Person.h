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
    Person() = default;
    Person(std::string first, std::string last, int rand) : firstName(first), lastName(last), randNb(rand) {}
    std::string getName() const { return firstName + " " + lastName; }
    int getNb() const { return randNb; }
    bool operator<(Person const& p){
        return getName() < p.getName();
    }
};

std::ostream& operator<<(std::ostream& o, Person const& p){
    o << p.getName();
    return o;
}


#endif // PERSON_H
