//
// Created by csk on 25/06/2022.
//

#include <iostream>
using std::cout;
using std::endl;

#include "CoffeeBuilder.h"

int main(){
    Coffee coffee = Coffee::Create("Sid")
            .MakeHot() // Because of the operator overloading inside the "CoffeeBuilder", we can easily assign the "CoffeeBuilder" object returned by any of these methods to the "coffee" variable
            .AddSugar()
            .AddMilk()
            .Costs(4.00);
    Coffee coffee2 = Coffee::Create("Theo")
            .MakeHot()
            .Costs(3.50);

    cout << coffee.cost << endl;
    cout << coffee2.cost << endl;

    return 0;
}