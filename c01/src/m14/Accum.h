//
// Created by csk on 19/06/2022.
//

#ifndef ACCUM_H
#define ACCUM_H

#include "Person.h"

#include <iostream>
// templates are fully written in header file

template<class T>
class Accum {
private:
    T total;
    template<class U> // to declare a template class/function as a friend, you need to specify that it is a template here
    friend std::ostream& operator<<(std::ostream &o, Accum<U> const& a); // "T" is already used, hence "U" was picked
public:
    Accum(T start): total(start){}
    T operator+=(T const& t){ return total = total + t;}
};

template<>
class Accum<Person> {
private:
    int total;
    template<class U>
    friend std::ostream& operator<<(std::ostream &o, Accum<U> const& a);
public:
    Accum(int start): total(start){}
    int operator+=(Person const& t){ return total = total + t.getNb();} // now to directly use private variable "randNb" here, we will need to declare this template as a friend
    // to do that we cannot include this into "Person.h" as that would create an ugly circular dependency as "Person.h" is already included here
    // one way would be to pre-declare on top of the "Person" in "Person.h" like making a promise
    // but just for now, to keep things simple, we are just implementing a public getter "getNb" for "randNb" in "Person"
};

template<class T>
std::ostream& operator<<(std::ostream &o, Accum<T> const& a){ // operators can be overloaded for templates as well
    o << a.total;
    return o;
}

#endif // ACCUM_H
