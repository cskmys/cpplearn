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
    vector<int> v{4, 1, 0, 1, -2, 3, 7, -6, 2, 0, 0, -9, 9};
    cout << "collection is: " << displayColl(v) << endl << endl;

    auto v2 = v;
    std::sort(std::begin(v2), std::end(v2));
    cout << "sorting collection in ascending order: " << displayColl(v2) << endl << endl;

    std::sort(std::begin(v2), std::end(v2), [](int ele1, int ele2){ return ele1 > ele2; });
    cout << "sorting collection in descending order: " << displayColl(v2) << endl << endl;

    std::sort(std::begin(v2), std::end(v2), [](int ele1, int ele2){ return abs(ele1) > abs(ele2); });
    cout << "sorting collection in descending order by taking absolute value of elements: " << displayColl(v2) << endl << endl;

    cout << "original collection is: " << displayColl(v) << endl << endl;

    return 0;
}