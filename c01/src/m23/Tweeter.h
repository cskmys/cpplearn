//
// Created by csk on 20/06/2022.
//

#ifndef TWEETER_H
#define TWEETER_H

#include "Person.h"

class TweeterPersonWVirDes : public PersonWVirDes {
private:
    std::string twitterHandle;
public:
    TweeterPersonWVirDes(std::string first, std::string last, int rand, std::string handle) : PersonWVirDes(first, last, rand), twitterHandle(handle) {}
    ~TweeterPersonWVirDes() { std::cout << "destructing Twitter which inherits from Person with virtual destructor" << std::endl; }
    std::string getName() const { return PersonWVirDes::getName() + " " + twitterHandle; }
};

class TweeterPersonWoVirDes : public PersonWoVirDes {
private:
    std::string twitterHandle;
public:
    TweeterPersonWoVirDes(std::string first, std::string last, int rand, std::string handle) : PersonWoVirDes(first, last, rand), twitterHandle(handle) {}
    ~TweeterPersonWoVirDes() { std::cout << "destructing Twitter which inherits a Person without virtual destructor" << std::endl; }
    std::string getName() const { return PersonWoVirDes::getName() + " " + twitterHandle; }
};

#endif // TWEETER_H
