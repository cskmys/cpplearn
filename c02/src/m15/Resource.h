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
    Resource(std::string n) : name(n) { std::cout << "constructing resource " << name << std::endl; }
    ~Resource() { std::cout << "Destructing resource " << name << std::endl; }

    std::string getName() const { return name; }
};

#endif //RESOURCE_H
