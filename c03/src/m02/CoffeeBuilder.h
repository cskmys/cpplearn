//
// Created by csk on 25/06/2022.
//

#ifndef COFFEEBUILDER_H
#define COFFEEBUILDER_H

#include <string>

class CoffeeBuilder; // forward declaration

class Coffee {
private:
    std::string requestorName;
public:
    bool isHot;
    bool hasMilk;
    bool hasSugar;
    double cost;

    Coffee(std::string reqNam) : requestorName(reqNam){}

    friend class CoffeeBuilder; // now "CoffeeBuilder" can have access to "requestorName"
    static CoffeeBuilder Create(std::string requestorName); // this will return the instance of a "CoffeeBuilder" which implements the step-by-step workflow required to create the "Coffee"
};

class CoffeeBuilder{
private:
    Coffee coffee; // this is to hide the "Coffee" from the client while using the "CoffeeBuilder"
public:
    CoffeeBuilder(std::string reqName) : coffee(Coffee(reqName)){}

    operator Coffee() const { return std::move(coffee); } // operator will allow for easy conversion between "CoffeeBuilder", and "Coffee"

    CoffeeBuilder& MakeHot(){ coffee.isHot = true; return *this; }
    CoffeeBuilder& AddMilk(){ coffee.hasMilk = true; return *this; }
    CoffeeBuilder& AddSugar(){ coffee.hasSugar = true; return *this; }
    CoffeeBuilder& Costs(double cost){ coffee.cost = cost; return *this; }
};

#endif //COFFEEBUILDER_H
