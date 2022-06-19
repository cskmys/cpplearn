//
// Created by csk on 18/06/2022.
//

#ifndef TWEETER_H
#define TWEETER_H

#include "Person.h"

class Tweeter : public Person { // public inheritance, hence "public" of "Person" become "public" of "Tweeter" and "protected" of "Person" become "private" of "Tweeter"
private:
    std::string twitterHandle;
public:
    Tweeter(std::string first, std::string last, int rand, std::string handle);
    ~Tweeter();
};


#endif // TWEETER_H
