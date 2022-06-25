//
// Created by csk on 25/06/2022.
//

#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <exception>
using std::exception;
using std::out_of_range;

#include "Person.h"
#include "Noise.h"

int main(){
    Noise n1("beep 1");
    try {
        Noise n("bloop 2");
        Person Sid("Sid", "Stark", 0);
        cout << "this line will not print" << endl;
    } catch (exception &e) { // before you arrive here, the stack is unwound, hence you see destructors fired already
        cout << e.what() << endl;
    }
    cout << "here n1 is still in scope" << endl; // coz its scope was not limited to "try" block
    return 0;
}