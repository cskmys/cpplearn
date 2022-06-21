//
// Created by csk on 21/06/2022.
//
#include <vector>
using std::vector;

#include <algorithm>
#include <numeric>

int main(){
    vector<int> v;

    for(int i = 0; i < 5; ++i){
        v.push_back(i);
    }

    for (int i = 0; i < 5;) {
        v.push_back(i++);
    } // does the same thing as first loop but in a different way
    // combining styles like this makes code more error-prone, as one developer who uses one style modifies code written in another style
    // which would require you to closely read and examine the code

    int i = 0;
    std::generate_n(std::back_inserter(v), 5, [&](){ return i++; }); // this single line does the same thing as before
    // if you know what "generate_n" and "back_inserter" are, it is very easy to read this code

    // "generate_n" generates a certain number of elements and adds it to the collection
    // "5" tells the number of elements to be generated
    // "back_inserter" adds new elements at the back of the vector just like "push_back" does
    // "[&](){ return i++; }" gives the logic required to generate the current element ( "return i++;" is compiled as 2 instructions, "return i;" and "i += 1;", by the compiler)

    // hence, you can read the one line code as "generate at the back of 'v' 5 elements by loading current 'i' and then incrementing it each time"
    
    int total = 0;
    for (int i = 0; i < 5; ++i) {
        total += v[i];
    } // C style way to total container

    total = 0;
    for (auto elem : v){
        total += elem;
    } // better way to iterate a loop

    total = std::accumulate(std::begin(v), std::end(v), 0); // best way to total a container
    // this can be read as "total all the elements of v from beginning to end when the initial value of sum is 0"


    int cnt = 0;
    for(int i = 0; i < v.size(); ++i){
        if (v[i] == 3){
            cnt++;
        }
    }

    cnt = 0;
    for(auto it = std::begin(v); it != std::end(v); ++it){
        if (*it == 3){
            cnt++;
        }
    }

    cnt = std::count(std::begin(v), std::end(v), 3);
    // read as "count in 'v' from beginning to end the number of times '3' occurs"

    return 0;
}