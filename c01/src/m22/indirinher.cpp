#include "Person.h"
#include "Tweeter.h"
#include <iostream>

using std::cout;
using std::endl;

int main(){
    cout << "getName:" << endl;
    Person Sid("Sid", "Stark", 456);
    cout << "Sid: " << Sid.getName() << endl;

    Person &rSid = Sid;
    Person *pSid = &Sid;

    cout << "rSid: " << rSid.getName() << endl;
    cout << "pSid: " << pSid->getName() << endl;

    /*
    Tweeter &rTSid = Sid; // throws compilation error
    Tweeter *pTSid = &Sid; // throws compilation error
    // you cannot use the inherited class's pointer or reference to point or refer to a base class
    // hence the errors
    */

    Tweeter SidStark("Sid", "Stark", 567, "@stark");
    cout << "SidStark: " << SidStark.getName() << endl;

    Person &rPSidStark = SidStark;
    Person *pPSidStark = &SidStark;

    cout << "rPSidStark: " << rPSidStark.getName() << endl;
    cout << "pPSidStark: " << pPSidStark->getName() << endl;

    Tweeter &rTSidStark = SidStark;
    Tweeter *pTSidStark = &SidStark;

    cout << "rTSidStark: " << rTSidStark.getName() << endl;
    cout << "pTSidStark: " << pTSidStark->getName() << endl;

    // when function is not marked as virtual what matters is what the pointer or reference type has implemented
    // when function is marked as virtual what matter is what the actual type of the target has implemented
    cout << "----------------------" << endl;
    cout << "getNameVir:" << endl;

    cout << "Sid: " << Sid.getNameVir() << endl;

    cout << "rSid: " << rSid.getNameVir() << endl;
    cout << "pSid: " << pSid->getNameVir() << endl;

    cout << "SidStark: " << SidStark.getNameVir() << endl;

    cout << "rPSidStark: " << rPSidStark.getNameVir() << endl;
    cout << "pPSidStark: " << pPSidStark->getNameVir() << endl;

    cout << "rTSidStark: " << rTSidStark.getNameVir() << endl;
    cout << "pTSidStark: " << pTSidStark->getNameVir() << endl;

    return 0;
}