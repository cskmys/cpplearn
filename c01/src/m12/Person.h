//
// Created by csk on 18/06/2022.
//

#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

class Person {
private:
    std::string firstName;
    std::string lastName;
    int randNb;
    friend bool operator<(int i, Person const& p);
public:
    Person(std::string first, std::string last, int rand);
    Person();
    ~Person();
    std::string getName() const{ return firstName + " " + lastName; }
    void setNb(int nb){ randNb = nb; }

    bool operator<(Person const& p) const;
    bool operator<(int i) const;
};

bool operator<(int i, Person const& p);
std::ostream& operator<<(std::ostream& o, Person const& p);

#endif //PERSON_H
