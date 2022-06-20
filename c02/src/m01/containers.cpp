#include <iostream>
#include <vector>

#include "Resource.h"

using std::cout;
using std::endl;
using std::vector;

int main(){
    vector<int> nbs{0, 1, 2}; // in C++17, compilers have class template type deduction, which can do type inference, hence you don't need "<int>"
    // but for C++14, you'll need that
    nbs.push_back(-2);
    nbs[0] = 3; // can use it like square bracket array as well

    int n = nbs[2];

    for(int i : nbs){ // for each loop
        cout << i << endl;
    }

    Resource r("local"); // constructing "local"
    {
        cout << "------------------" << endl;
        vector<Resource> rsrcs;
        rsrcs.push_back(r); // passing "r" by value, hence a copy happens, and as we have a copy constructor, that is executed
        // hence, in "rsrcs" a copy of "r" is constructed via the copy constructor
        cout << "------------------" << endl;
        rsrcs.push_back(Resource("first")); // constructing a temporary "first", then while passing it to "rsrcs"
        // vector realizes that its current size is 1, and to push one more needs to make more space
        // vector always doubles in its size, so it creates an array of size 2 inside and
        // then copies existing elements to it, in this case: "r".
        // then it constructs a copy of "first" in the new array
        // after pushing all the elements to new array, it destructs the previous array which in turn destructs the existing elements: "r"
        // finally the temporary copy of the "first" that we created in the beginning destructs
        cout << "------------------" << endl;
        rsrcs.push_back(Resource("second")); // now internal array size is 2 to push "second", it will internally expand to size 4
        // to do this, the same mechanism explained above happens.
        cout << "------------------" << endl;
    } // destructing "rsrcs" and all its elements: "local", "first", "second"

} // destructing "local"