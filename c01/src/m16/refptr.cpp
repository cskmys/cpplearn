#include <iostream>

#include "Person.h"

using std::cout;
using std::endl;
using std::string;

int main(){

    int a = 3;
    cout << "a is " << a << endl;
    int &rA = a;
    rA = 5;
    cout << "a is " << a << endl;

    Person Sid("Sid", "Stark", 234);
    Person &rSid = Sid;
    rSid.setNb(345);
    cout << "rSid: " << rSid.getName() << " " << rSid.getNb() << endl;


    int *pA = &a;
    *pA = 4;
    cout << "a is " << a << endl;
    int b = 100;
    pA = &b; // reinitialization
    *pA = (*pA) + 1; // can also be written as "(*pA)++" or "*pA += 1", but for the sake of readability we pick this one
    cout << "a is " << a << ", *pA is " << *pA << endl;

    Person *pSid = &Sid;
    (*pSid).setNb(235);
    pSid->setNb(236); // compiler converts "var->" into "(*var)."
    cout << "Sid: " << Sid.getName() << " " << Sid.getNb() << endl;
    cout << "pSid: " << pSid->getName() << " " << pSid->getNb() << endl;

    /*
    int &badRef; // throws compilation error
    // references must always be initialized while declaring, here no initialization, hence the error
    */

    /*
    int *badPtr;
    *badPtr = 3; // code will crash here
    // as pointer is not initialized, it contains a junk value which is interpreted as address and trying to write to that invalid address is going to cause code crash
    */

    int *badPtrFix = nullptr; // you should never leave a pointer uninitialized, if you still don't have a value to initialize, then initialize with a "nullptr"
    if(badPtrFix){ // when done this way, you have the option of checking for null pointer whenever you have uninitialized or invalid pointer
        *badPtrFix = 3;
        cout << *badPtrFix << endl;
    }

    return 0;
}
