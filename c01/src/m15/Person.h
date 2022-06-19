//
// Created by csk on 18/06/2022.
//

#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

template <class T>
class Accum; // pre-declaration done to avoid circular dependency

class Person {
private:
    std::string firstName;
    std::string lastName;
    int randNb;
    friend bool operator<(int i, Person const& p);
    friend class Accum<Person>; // befriending a class, more specifically, only one type of generic "Accum" i.e. "Accum<Person>"
public:
    Person(std::string first, std::string last, int rand);
    Person();
    ~Person();
    std::string getName() const { return firstName + " " + lastName; }
    void setNb(int nb) { randNb = nb; }

    bool operator<(Person const& p) const;
    bool operator<(int i) const;
};

bool operator<(int i, Person const& p);
std::ostream& operator<<(std::ostream& o, Person const& p);

#endif //PERSON_H
