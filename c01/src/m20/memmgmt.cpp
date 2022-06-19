#include <iostream>

#include "Person.h"

using std::cout;
using std::endl;
using std::string;

int main(){
    Person Sid("Sid", "Stark", 345);
    Sid.addRsrc();

    Sid.setFName("Sid2");
    Sid.addRsrc();

    Person Sid2 = Sid; // without copy constructor it will do a shallow copy of all the pointers
    // hence at the end of the scope, when destructing "Sid2" and "Sid" both will do delete on the pointers that were shallow copied
    // which will lead to double delete and hence code crash

    Sid = Sid2;
    return 0;
}
