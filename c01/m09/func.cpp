#include "Tweeter.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

int main(){
    Person p1("K", "C", 123);
    {
        Tweeter t1("Someone", "Else", 456, "@whoever");
        string tName = t1.getName();
    }

    cout << p1.getName() << " " << p1.getNb() << endl;
    p1.setNb(124);
    cout << p1.getName() << " " << p1.getNb() << endl;

    return 0;
}
