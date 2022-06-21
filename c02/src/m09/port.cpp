//
// Created by csk on 21/06/2022.
//
#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <list>
using std::list;

#include <algorithm>
#include <numeric>

int main(){
    vector<int> v;
    int i = 0;
    std::generate_n(std::back_inserter(v), 15, [&](){ int temp = i++ % 5; return temp; });

    int total = 0;
    for (int i = 0; i < 5; ++i) {
        total += v[i];
    }

    total = std::accumulate(std::begin(v), std::end(v), 0);
    cout << total << endl;

    list<int> l;
    i = 0;
    std::generate_n(std::back_inserter(l), 15, [&](){ int temp = i++ % 5; return temp; }); // directly portable from vector as STL algorithm is used

    /*
    total = 0;
    for (int i = 0; i < 5; ++i) {
        total += l[i]; // will throw a compilation error
    }
    // a "list" is not stored in continuous memory location, hence it cannot be indexed using "[]"
    */

    total = std::accumulate(std::begin(l), std::end(l), 0); // directly portable from vector as STL algorithm is used
    cout << total << endl;
    return 0;
}