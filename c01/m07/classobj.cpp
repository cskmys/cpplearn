#include "Tweeter.h"
#include "status.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

int main(){
    Person p1("K", "C", 123);
    {
        Tweeter t1("Someone", "Else", 456, "@whoever");
        string tName = t1.getName();
    }
    string name = p1.getName();

    int i = p1.getNb();

    Status s = Pending;
    s = Approved;

    FileError fe = FileError::notfound;
    fe = FileError::ok;

    NetworkError ne = NetworkError::disconnected;
    ne = NetworkError::ok;

    return 0;
}
