#include <iostream>

#include "Person.h"

using std::cout;
using std::endl;
using std::string;

int dummy(Person p){ // "Person" is passed by value, hence there's a copy.
    // all values are copied except "pRsrc" which is shared as it uses "shared_ptr"
    // now inside this function call there are 3 objects using the shared resource
    // during the creation of the copy, the constructor of "p" will increment the reference count of "shared_ptr" to 3
    return p.getNb();
} // when the copied object "p" goes out of scope, its destructor will decrement the reference count of "shared_ptr" to 2
// hence, there are 2 objects pointing to the shared resource "pRsrc"

int main(){
    {
        Person Sid("Sid", "Stark", 345);  // "shared_ptr" used by only one object hence reference count is 1
        Sid.addRsrc(); // as the "shared_ptr" is null reference count is 0 and, resetting it does nothing,
        // after "make_shared_ptr" the resource is created, and the reference count is increment to 1

        Sid.setFName("Sid2");
        Sid.addRsrc(); // shared resource is deleted and recreated, and the reference count reset to 1

    } // end of scope of "Sid", destructor of "Sid" calls destructor of "shared_ptr" which will decrement reference count to 0
    // as the reference count is 0, it deletes the resource that it is managing

    cout << "-------------------------" << endl;

    {
        Person Sid("Sid", "Stark", 345);
        Sid.addRsrc();

        cout << "Sid: " << dummy(Sid) << endl;

        Person Sid2 = Sid; // new resource("pRsrc") not deleted and constructed like before, but rather shared using "shared_ptr", but the rest of the values are copied
        // in the constructor of "Sid2" call to the "shared_ptr" will increase its reference count to 2
        // so now 2 objects are sharing the same "pRsrc" via "shared_ptr"
        cout << "Sid2: " << dummy(Sid2) << endl;

        Sid = Sid2; // new resource not constructed, but rather shared using "shared_ptr", but the rest of the values are copied
        // still there are 2 objects that share the same "pRsrc" via "shared_ptr"
        cout << "Sid: " << dummy(Sid) << endl;
        Sid.setNb(346);
        cout << "Sid: " << dummy(Sid) << endl;

    } // end of scope for both "Sid" and "Sid2", "Sid2" was created in the last, so it will be at the top of the stack and goes out of scope first,
    // "Sid2" destructor will decrement the reference count to 1
    // while "Sid" goes out of scope, its destructor will decrement the reference count 0, and hence delete the shared resource "pRsrc"

    return 0;
}
