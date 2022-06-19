#include "Person.h"
#include <iostream>

using namespace std; // if a typename is present in "std", then all objects are of "std" type(even if same typename exists in another class) unless they are specified otherwise
// this is a very bad method, coz this sort of overarching generalization can cause confusions
// hence, declare on what is required as done in "person.cpp"
// moreover, never ever write this in a header file

int main(){
    Person p1("K", "C", 123); // p1 comes into scope
    {
        Person p2; // p2 comes into scope
    } // p2 goes out of scope
    cout << "after scope of p2 ends" << endl; // no need to specify "cout" or "endl" or "string"
    string name = p1.getName();

    int i = p1.getNb();

    return 0;
} // p2 goes out of scope