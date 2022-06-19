#include <iostream>

#include "Accum.h"
#include "Person.h"

using std::cout;
using std::endl;
using std::string;

int main(){

    Accum<int> integers(0);
    integers += 3;
    integers += 7;
    cout << integers << endl;

    Accum<string> strings("");
    strings += "Hello";
    strings += " ";
    strings += "world";
    cout << strings << endl;

    Person p1("C", "K", 123);
    Person p2("Someone", "Else", 456);
    Accum<Person> people(0);
    people += p1;
    people += p2;
    cout << people << endl;
    // to make the above code work, you can
    // implement "+" operator for "Person" in which case it becomes the feature of "Person" or
    // specialize the Accum template to handle "Person" class differently in which case the logic doesn't become a part of "Person", but rather becomes special knowledge possessed by "Accum" to deal with "Person"

    // Accumulating "Person" conceptually doesn't make sense, whatever needs to be done has more to do with the accumulation process which wants to interpret "Person" rather than what it means to be a "Person"
    // in this case, template specialization makes more sense than introducing the "+" operator in the "Person"
    return 0;
}
