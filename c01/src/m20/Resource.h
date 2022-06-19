//
// Created by csk on 19/06/2022.
//

#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>

class Resource {
private:
    std::string name;
public:
    Resource(std::string n);
    ~Resource();
    std::string getName() const { return name; }
};


#endif //RESOURCE_H
