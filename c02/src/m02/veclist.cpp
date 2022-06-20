//
// Created by csk on 20/06/2022.
//

#include<iostream>
using std::cout;
using std::endl;

#include <chrono>
using std::chrono::system_clock;
using std::chrono::steady_clock;
using std::chrono::duration_cast;
using std::chrono::seconds;
using std::chrono::milliseconds;

#include <vector>
#include <list>
#include <cstdlib>

using std::vector;
using std::list;

template<typename Func>
long long timFunc(Func f){
    auto begin = steady_clock::now();
    f();
    auto end = steady_clock::now();

    return duration_cast<milliseconds>(end - begin).count();
}

void mkVec(int const& size, vector<int>& v){
    for (int i = 0; i < size; ++i) {
        int r = static_cast<int>(rand()); // random number generator function
        bool inserted = false;
        for (auto it = std::begin(v); it != std::end(v); ++it){ // to find where to insert the random number
            if (*it > r){ // if current value bigger than whatever has been currently generated
                v.insert(it, r); // insert it at the current position, and move to the current element to the next position
                inserted = true;
                break;
            }
        }
        if (!inserted){
            v.push_back(r);
        }
    }
}

void mkLst(int const& size, list<int>& l){
    for (int i = 0; i < size; ++i) {
        int r = static_cast<int>(rand());
        bool inserted = false;
        for (auto it = std::begin(l); it != std::end(l); ++it){ // iterators are used to traverse the container
            if (*it > r){ // dereferencing the iterator to get the element
                l.insert(it, r);
                inserted = true;
                break;
            }
        }
        if (!inserted){
            l.push_back(r);
        }
    }
}

int main(){
    int const size = 10'000;

    vector<int> v;
    v.push_back(0);

    list<int> l;
    l.push_back(0);

    auto vTimMs = timFunc([&](){ mkVec(size, v);});
    auto lTimMs = timFunc([&](){ mkLst(size, l);});

    cout << "vTimMs " << vTimMs << endl;
    cout << "lTimMs " << lTimMs << endl;

    // tried "size" of 1000, 10000, 100000
    // vector was faster than list
    // but still we can't just conclude that this is the case always
    // this exercise just illustrates a performance test
    // if we were inserting values in the middle, the result might not be the same
    // hence, instead of simply assuming, you'll need to run a test and compare the performance in your particular application
}
