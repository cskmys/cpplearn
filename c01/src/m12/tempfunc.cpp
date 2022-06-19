#include "Person.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

template <class T>
T myMax(T const& t1, T const& t2){
    return (t1 < t2) ? t2 : t1;
}

template <class T>
void doMax(T const& t1, T const& t2){
    cout << "max of " << t1 <<" and "<< t2 << " is " << myMax(t1, t2) << endl;
}


int main(){

    doMax(33, 44);

    string s1 = "hello";
    string s2 = "world";
    doMax(s1, s2);

    /*
    doMax(33, 200.02); // throws compilation error
    // coz both arguments need to be of the same type
    */
    doMax<double>(33, 200.2); // by specifying the template to be used as "double"
    // we are forcing the compiler to interpret both the arguments as "double", in which case "33" is seen as "33.0"

    Person p1("K", "C", 123);
    Person p2("Someone", "Else", 456);
    doMax(p1, p2);

    return 0;
}
