//
// Created by csk on 26/06/2022.
//

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <algorithm>
#include <sstream>

template<typename Iter>
string displayColl(Iter b, Iter e){
    std::stringstream ss;
    std::for_each(b, e, [&](typename Iter::value_type n){ ss << n << ", "; });
    string s = ss.str();
    return s;
}

template<typename T>
string displayColl(T v){
    return displayColl(std::begin(v), std::end(v));
}

int main(){
    vector<int> a{1, 2, 3, 4, 5};

    auto b = a;

    cout << "b: " << displayColl(b) << endl;
    for (auto it = std::begin(b); it != std::end(b); ++it) {
        *it = 0;
    }
    cout << "b: " << displayColl(b) << endl;
    cout << "a: " << displayColl(a) << endl;

    for(auto &i : b){
        i = 1;
    }
    cout << "b: " << displayColl(b) << endl;

    std::for_each(std::begin(b), std::end(b), [](int& ele){ ele = 2; }); // need the predicate to take reference if you want to change the element
    cout << "b: " << displayColl(b) << endl;

    b = a;
    cout << "b: " << displayColl(b) << endl;
    auto startAtThree = std::find(std::begin(b), std::end(b), 3);
    std::for_each(startAtThree, std::end(b), [](int& ele){ ele = 0; });
    cout << "b: " << displayColl(b) << endl;

    return 0;
}