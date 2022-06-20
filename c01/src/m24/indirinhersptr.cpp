#include "Person.h"
#include "Tweeter.h"
#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::shared_ptr;
using std::make_shared;

int main(){
    shared_ptr<Person> spSid = make_shared<Tweeter>("Third", "Name", 678, "@handle");
    cout << "spSid: " << spSid->getName() << endl; // though "shared_ptr" is of "Person" you can assign to it "Tweeter" the child of "Person"
    // when you call, "getName" as it is virtual in "Person", we get the version in the "Tweeter"
    return 0;
}