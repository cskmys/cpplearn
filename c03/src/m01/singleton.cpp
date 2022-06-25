//
// Created by csk on 25/06/2022.
//

#include <iostream>
using std::cout;
using std::endl;

#include "GlobalCoffeeCfg.h"

int main(){
    /*
    GlobalCoffeeCfg cfg = GlobalCoffeeCfg(); // throws compilation error
    // cannot create it as constructor is private
    */
    GlobalCoffeeCfg &cfg = GlobalCoffeeCfg::get();

    cfg.SetState("COFFEE_STATUS", "ON");
    cfg.SetState("COFFEE_HEALTH_URL", "./health");

    cout << "COFFEE_STATUS: " << cfg.GetState("COFFEE_STATUS") << endl;
    cout << "COFFEE_HEALTH_URL: " << cfg.GetState("COFFEE_HEALTH_URL") << endl;

    return 0;
}