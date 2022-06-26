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

#include "Person.h"

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
    cout << "collection is: " << displayColl(v) << endl;
    std::sort(std::begin(v), std::end(v), [](int ele1, int ele2){ return ele1 > ele2; });
    std::stable_sort(std::begin(v), std::end(v), [](int ele1, int ele2){ return abs(ele1) > abs(ele2); });
    cout << "sorting collection by descending order of their absolute value: " << displayColl(v) << endl;

    auto sorted = std::is_sorted(std::begin(v), std::end(v));
    cout << "is collection sorted by ascending order: " << sorted << endl;
    sorted = std::is_sorted(std::begin(v), std::end(v), [](int ele1, int ele2){ return ele1 > ele2; });
    cout << "is collection sorted in descending order: " << sorted << endl;
    sorted = std::is_sorted(std::begin(v), std::end(v), [](int ele1, int ele2){ return abs(ele1) > abs(ele2); });
    cout << "is collection sorted in descending order by taking absolute value of elements: " << sorted << endl;
    sorted = std::is_sorted(std::begin(v), std::end(v), [](int ele1, int ele2){ return (abs(ele1) >= abs(ele2)) && (ele1 > ele2); });
    cout << "is collection sorted by descending order of their absolute value: " << sorted << endl << endl;

    vector<Person> ppl{
        {"Sid", "Stark", 1000},
        {"Theo", "Von", 1000},
        {"Joe", "Rogan", 1000},
        {"George", "Carlin", 2000},
        {"Dave", "Chappelle", 2000},
    };
    cout << "The comedians performing tonight are: " << displayColl(ppl) << endl;

    std::sort(std::begin(ppl), std::end(ppl), [](Person p1, Person p2){ return p1.getName() > p2.getName(); });
    std::stable_sort(std::begin(ppl), std::end(ppl), [](Person p1, Person p2){ return p1.getNb() > p2.getNb(); });
    cout << "The comedians performing tonight sorted by number and name, both in descending order are: " << displayColl(ppl) << endl;

    sorted = std::is_sorted(std::begin(ppl), std::end(ppl));
    cout << "are comedians performing tonight sorted by ascending order of their names: " << sorted << endl;
    sorted = std::is_sorted(std::begin(ppl), std::end(ppl), [](Person p1, Person p2){ return ((p1.getNb() >= p2.getNb()) && (!(p1 < p2))); });
    cout << "are comedians performing tonight sorted by descending order of both their numbers and names: " << sorted << endl << endl;

    return 0;
}