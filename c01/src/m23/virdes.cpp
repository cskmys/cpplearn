#include "Person.h"
#include "Tweeter.h"
#include <iostream>

using std::cout;
using std::endl;

int main(){
    PersonWVirDes* someoneWVirDes = new TweeterPersonWVirDes("Someone", "else", 567, "@WVirDes");
    cout << someoneWVirDes->getName() << endl;
    delete someoneWVirDes;

    cout << "-------------------" << endl;

    PersonWoVirDes* someoneWoVirDes = new TweeterPersonWoVirDes("Someone", "else", 567, "@WoVirDes");
    cout << someoneWoVirDes->getName() << endl;
    delete someoneWoVirDes;

    return 0;
}