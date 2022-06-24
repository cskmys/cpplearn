//
// Created by csk on 20/06/2022.
//

#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>
#include <iostream>

class ResourceR0 {
private:
    std::string name;
public:
    ResourceR0(std::string n) : name(std::move(n)) {}

    std::string getName() const { return name; }

    bool operator>(ResourceR0 const& r){ return name > r.name; }
    bool operator<(ResourceR0 const& r){ return name < r.name; }
    bool operator==(ResourceR0 const& r){ return name == r.name; }
    // we are using rule of zero i.e. use variable types that manage themselves
    // without writing a destructor, and copy & move constructor & assignment operator, the compiler will generate whatever is needed to ensure the best performance
};

class ResourceR3 {
private:
    std::string name;
public:
    ResourceR3(std::string n) : name(n) {}

    ~ResourceR3(){}
    ResourceR3(ResourceR3 const& r) : name(r.name){}
    ResourceR3& operator=(ResourceR3 const& r) { name = r.getName(); return *this; }

    std::string getName() const { return name; }

    bool operator>(ResourceR3 const& r){ return name > r.name; }
    bool operator<(ResourceR3 const& r){ return name < r.name; }
    bool operator==(ResourceR3 const& r){ return name == r.name; }

    // here we are doing a copy of "name"
    // hence, we are using rule of three i.e. write all the three: destructor, copy constructor and copy assignment operator, when you need any one of them
    // here no move constructor or move assignment operator, just copy constructor and copy assignment operator, so performance will not be great
};

class ResourceR5 {
private:
    std::string name;
public:
    ResourceR5(std::string n) : name(n) {}

    ResourceR5(ResourceR5 const& r) : name(r.name){}
    ResourceR5& operator=(ResourceR5 const& r) { name = r.getName(); return *this; }

    std::string getName() const { return name; }

    bool operator>(ResourceR5 const& r){ return name > r.name; }
    bool operator<(ResourceR5 const& r){ return name < r.name; }
    bool operator==(ResourceR5 const& r){ return name == r.name; }

    ResourceR5(ResourceR5&& r) noexcept : name(std::move(r.name)){} // move constructor, used to "move" "r.name" to "name"
    // reference of reference taken coz you are moving the address to another variable rather than the data
    ResourceR5& operator=(ResourceR5&& r) noexcept {
        if (this != &r){ // checking for self assignment
            name = std::move(r.name);
            r.name.clear(); // normally not required, but for strings, when it is small size, for purposes of optimization "move" will do "copy"
        }
        return *this;
    }

    // here "name" is a type "string" that is movable, hence we can get better performance
    // hence, we are using rule of five i.e. write all the five: destructor, copy constructor, copy assignment operator, move constructor, and move assignment operator, when you need any one of them
};

/*
class ResourceWMv {
private:
    std::string name;
public:
    ResourceWMv(std::string n) : name(std::move(n)) {}

    std::string getName() const { return name; }

    bool operator>(ResourceWMv const& r){ return name > r.name; }
    bool operator<(ResourceWMv const& r){ return name < r.name; }
    bool operator==(ResourceWMv const& r){ return name == r.name; }

    ResourceWMv(ResourceWMv&& r) noexcept :name(std::move(r.name)){}
    ResourceWMv& operator=(ResourceWMv&& r) noexcept {
        if (this != &r){ // checking for self assignment
            name = std::move(r.name);
            r.name.clear();
        }
        return *this;
    }
    // only move constructor and move assignment operator
    // implicitly deleted copy constructor and copy assignment operator, code won't compile
};
*/

#endif //RESOURCE_H
