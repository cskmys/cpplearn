#include "Person.h"

int main(){
    Person p1("K", "C", 123); // instantiating an object of type class

    std::string name = p1.getName(); // call to the member function of this particular instance of the "Person" class

    /*
    int i = p1.randNb; // throws compilation error
    // "randNb" is a private member hence, any code outside the class cannot access
    */
    int i = p1.getNb();

    /*
    Person p2; // will throw a compilation error
    // you have a non-default constructor, hence the compiler no longer generates the default constructor
    */
    PersonWDef p2; // we have a default constructor now
    return 0;
}