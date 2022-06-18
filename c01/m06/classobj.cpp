#include "Tweeter.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

int main(){
    Person p1("K", "C", 123);
    {
        Tweeter t1("Someone", "Else", 456, "@whoever");
        string tName = t1.getName(); // "getName" was not implemented in the "Tweeter" class, but as it (publicly) inherits from "Person"
        // you get access to all the public methods of "Person"
    }
    cout << "after scope of p2 ends" << endl;
    string name = p1.getName();

    int i = p1.getNb();

    return 0;
}
