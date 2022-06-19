//
// Created by csk on 19/06/2022.
//

#ifndef ACCUM_H
#define ACCUM_H

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

template<class T>
std::ostream& operator<<(std::ostream &o, Accum<T> const& a){ // operators can be overloaded for templates as well
    o << a.total;
    return o;
}

#endif // ACCUM_H
