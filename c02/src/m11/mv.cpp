//
// Created by csk on 23/06/2022.
//

#include<iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <chrono>
using std::chrono::system_clock;
using std::chrono::steady_clock;
using std::chrono::duration_cast;
using std::chrono::seconds;
using std::chrono::milliseconds;

#include <vector>
using std::vector;

#include <list>
using std::list;

#include <algorithm>
#include <cstdlib>

#include "Resource.h"

template<typename Func>
long long timFunc(Func f){
    auto begin = steady_clock::now();
    f();
    auto end = steady_clock::now();

    return duration_cast<milliseconds>(end - begin).count();
}

template<typename T>
void exercise(int size, string commonName){ // video 01:00
    T v;
    typename T::value_type res1("starting entry"); // if "T" is "vector<string>", its "value_type" is "string"
    v.push_back(res1); // pushing string to vector
    for (int i = 0; i < size; ++i) {
        int ss = static_cast<int>(rand()) % 100; // generating random number between 0-99
        string s;
        s.reserve(ss); // making space for "ss" number of characters in the string "s"
        std::generate_n(std::back_inserter(s), ss, [ss](){ return static_cast<char>('!' + ss / 2); }); // generating a character with ascii value "! + ss / 2", "ss" number of times
        // "!" is the first printable character right after "space" in the ascii code table
        typename T::value_type res(s); // create a string "res" from "s"
        bool inserted = false;
        for (auto it = std::begin(v); it != std::end(v); ++it){
            if (*it > res){ // if current string at "*it" in the vector "v" is greater than "res"
                v.insert(it, res); // insert it
                inserted = true;
                break;
            }
        }
        if(!inserted){
            v.push_back(res);
        }
    }
    auto it = std::max_element(std::begin(v), std::end(v));
    typename T::value_type maxV = *it;
    it = std::min_element(std::begin(v), std::end(v));
    typename T::value_type minV = *it;
    bool sorted = std::is_sorted(std::begin(v), std::end(v)); // checks if sorted in ascending order

    cout << sorted << endl;
}

int main(){
    int const size = 10000;

    cout << "default" << endl;
    auto vecMs = timFunc([&](){ exercise<vector<ResourceR0>>(size, "vector"); });
    cout << vecMs << endl;
    auto lstMs = timFunc([&](){ exercise<list<ResourceR0>>(size, "list"); });
    cout << lstMs << endl;

    cout << "copy" << endl;
    vecMs = timFunc([&](){ exercise<vector<ResourceR3>>(size, "vector"); });
    cout << vecMs << endl;
    lstMs = timFunc([&](){ exercise<list<ResourceR3>>(size, "list"); });
    cout << lstMs << endl;

    cout << "copy and move" << endl;
    vecMs = timFunc([&](){ exercise<vector<ResourceR5>>(size, "vector"); });
    cout << vecMs << endl;
    lstMs = timFunc([&](){ exercise<list<ResourceR5>>(size, "list"); });
    cout << lstMs << endl;

    // for "vector": "rule of zero" provides better performance
    // for "list": "rule of five" provides better performance
    // but preferably, don't try to write anything manually
    // so just try both "vector" and "list" with "rule of zero" and pick whichever is the best in your case
    // if, by any chance, you really need to squeeze out the very last bit of performance,
    // then you can try both "vector" and "list" with both "rule of zero" and "rule of five" and pick the best


    /*
    cout << "move" << endl;
    vecMs = timFunc([&](){ exercise<vector<ResourceWMv>>(size, "vector"); }); // throws compilation error coz "v.push_back" is trying to do copy when we have actually (implicitly) deleted it
    cout << vecMs << endl;
    lstMs = timFunc([&](){ exercise<list<ResourceWMv>>(size, "list"); }); // throws compilation error
    cout << lstMs << endl;
    */
}