#include <iostream>

#include "Person.h"

using std::cout;
using std::endl;
using std::string;

int doubleInt(int x){
    return x * 2;
}

int doubleIntRef(int &x){
    return x * 2;
}

int doubleIntConstRef(int const&x){
    return x * 2;
}

int main(){
    int const ci = 3;
    /*
    ci = 4; // throws compilation error
    // "ci" is declared as "const" hence it cannot be modified
    */
    /*
    int &rci = ci; //  throws compilation error
    // reference to "ci" which is a "const" is not allowed coz "rci" as it's not declared as "const" should allow the change of "ci" from it
    // but here "ci" is a "const", and hence then there's no way to change it.
    // this is a paradox and, hence not allowed.
    */

    int i = 5;
    int const& cri = i;
    /*
    cri = 5; // throws compilation error
    // though the target "i" is not "const", the reference to it "cri" is "const", hence it cannot be modified from that reference
    */
    doubleInt(i);
    doubleInt(5);

    doubleIntRef(i);
    /*
    doubleIntRef(5); // throws compilation error
    // "5" is a literal that sits in the code memory, you cannot take a non-const reference to something that cannot be changed(as explained above in case of non-const reference to a const)
    // hence, this is not allowed
    */
    doubleIntConstRef(i);
    doubleIntConstRef(5); // here "5" is a const as it is a part of the code memory and will not be changed.
    // here the reference is a const as well, hence there is no way to change the target("5" in code memory). using it, hence this is allowed.

    Person Sid("Sid", "Stark", 234);
    Sid.setNb(235);
    Person const cSid = Sid;
    /*
    cSid.setNb(236); // throws compilation error
    // "cSid" is "const" hence, you cannot call any non-"const" member functions as they allow to change the member variables of the class
    // here, the compiler only checks if the member function is qualified with a "const" rather than checking if any of the member variables are actually modified or not.
    // hence, even if you are not modifying any member variables within the member function, if member function is not qualified as "const", you cannot call that.
    */
    int const sidNb = cSid.getNb();

    return 0;
}
