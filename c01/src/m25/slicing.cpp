#include "Person.h"
#include "Tweeter.h"
#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::shared_ptr;
using std::make_shared;

int dummy(Person p){ return p.getNb(); }

int dummyConstRef(Person const& p){ return p.getNb(); }

int main(){
    Person Sid("Sid", "Stark", 456);
    Tweeter SidStark("Sid", "Stark", 567, "@stark");

    cout << "SidStark(before copying to Sid): " << SidStark.getName() << " " << SidStark.getNb() << endl;
    cout << "Sid(before copying SidStark): " << Sid.getName() << " " << Sid.getNb() << endl;

    Sid = SidStark;

    cout << "SidStark(after copying to Sid): " << SidStark.getName() << " " << SidStark.getNb() << endl;
    cout << "Sid(after copying SidStark): " << Sid.getName() << " " << Sid.getNb() << endl;

    cout << "Passing base(Sid) by value " << dummy(Sid) << endl;
    cout << "Passing child(SidStark) by value(slicing happens) " << dummy( SidStark) << endl; // slicing is happening, hence the "getNb" method called inside "dummy" is the method of "Person" not "Tweeter" despite it being virtual

    cout << "Passing base(Sid) by reference " << dummyConstRef(Sid) << endl;
    cout << "Passing child(SidStark) by reference(no slicing happens) " << dummyConstRef( SidStark) << endl; // as a reference is used, no slicing happens, so polymorphism is not lost

    return 0;
}