#include "Person.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

int main(){
    Person p1("K", "C", 123);
    Person p2("Someone", "Else", 456);

    cout << "p1 is " << (!(p1 < p2) ? "not" : "" ) << " less than p2" << endl;
    cout << "p1 is " << (!(p1 < 300) ? "not" : "" ) << " less than 300" << endl;
    cout << "300 is " << (!(300 < p1) ? "not" : "" ) << " less than p1" << endl; // operator overloading using free function

    return 0;
}
