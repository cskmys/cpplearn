//
// Created by csk on 20/06/2022.
//

#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>

class Resource {
private:
    std::string name;
public:
    Resource(std::string n) : name(n) {}
    virtual ~Resource(){}
    virtual std::string getName() const { return name; }
};


#endif //RESOURCE_H
