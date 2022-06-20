#include "Person.h"
#include "Tweeter.h"
#include "Resource.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(){
    Tweeter t("Sid", "Stark", 123, "@stark");
    Person *p = &t;
    /*
    Tweeter *pt = p; // throws compilation error
    // cannot simply allocate a base class pointer to inherited class
    */
    Tweeter *pt = static_cast<Tweeter*>(p); // very sure that this is possible, hence safe to cast using "static_cast"
    cout << pt->getNb() << endl;
    /*
    int i = 3;
    Tweeter *pi = static_cast<Tweeter*>(i); // throws compilation error
    // you cannot simply cast between totally unrelated types by throwing in "static_cast"
    */

    /*
    int j = 3;
    Tweeter *pj = (Tweeter*)(j); // no warning as we are using c-style cast to perform casting totally unrelated things.
    pj->getNb(); // causes code crash
    // converting totally unrelated things will cause misinterpretation of data and hence code crash
    */

    Resource r("local");
    Tweeter *pt2;
    cout << "Use resource/tweeter?" << endl;
    string ans;
    cin >> ans;
    if(ans == "r"){
        pt2 = dynamic_cast<Tweeter *>(&r); // though "Resource" has a virtual table, it doesn't have the proper type
        // hence, it cannot be converted to "Tweeter"
    } else {
        pt2 = dynamic_cast<Tweeter *>(p); // "Person" has a virtual table of proper type
        // hence, it can be converted to "Tweeter"
    }
    if(pt2){ // if conversion was successful, pointer "pt2" will not be null
        cout << pt2->getName() << endl;
    } else {
        cout << "pointer cannot be cast to tweeter" << endl;
    }
    return 0;
}