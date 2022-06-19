#include <iostream>

#include "Resource.h"

using std::cout;
using std::endl;
using std::string;

int main(){
    {
        Resource locRsrc("local");
        string locStr = locRsrc.getName();
    }

    Resource* pRsrc = new Resource("created with new");
    string newStr = pRsrc->getName();

    Resource* p2 = pRsrc;

    delete pRsrc; // "pRsrc" deallocated, no longer valid
    /*
    delete pRsrc; // causes code crash
    // deallocated what is already deallocated has no meaning
    */
    /*
    string str3 = pRsrc->getName(); // causes code crash
    // dereferencing a pointer that is no longer valid
    */
    pRsrc = nullptr; // reinitializing to null, in order to gain null check protection

    if(pRsrc){ // null check
        string str3 = pRsrc->getName();
    }

    /*
    p2->getName(); // causes code crash
    // as the address present is already deallocated
    */

    /*
    delete p2; // causes code crash
    // as the address present is already deallocated
    */
    if(!pRsrc){
        p2 = nullptr; // after the parent is no longer valid, reinitialize to null
    }
    if(p2){ // null check protection
        p2->getName();
        delete p2;
    }

    delete pRsrc; // doing "delete" nullptr will not cause code crash
    delete p2; // doing "delete" nullptr will not cause code crash

    return 0;
}
