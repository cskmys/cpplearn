//
// Created by csk on 20/06/2022.
//

#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>
#include <iostream>

class Resource {
private:
    std::string name;
public:
    Resource(std::string n) : name(n) { std::cout << "constructing " << name << std::endl; }
    ~Resource(){ std::cout << "destructing " << name << std::endl; }
    Resource(const Resource& r) : name(r.name){ std::cout << "copy constructing " << name << std::endl; }
    Resource& operator=(const Resource& r) {  name = r.getName(); std::cout << "copy assigning " << name << std::endl; return *this; }
    std::string getName() const { return name; }
};


#endif //RESOURCE_H
