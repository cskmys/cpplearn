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

    vector<Person> ppl{
        {"Sid", "Stark", 1000},
        {"Theo", "Von", 1000},
        {"Joe", "Rogan", 1000},
        {"George", "Carlin", 2000},
        {"Dave", "Chappelle", 2000},
    };
    cout << "The comedians performing tonight are: " << displayColl(ppl) << endl;

    auto ppl2 = ppl;
    std::sort(std::begin(ppl2), std::end(ppl2));
    cout << "The comedians performing tonight sorted in alphabetical order are: " << displayColl(ppl2) << endl;
    std::sort(std::begin(ppl2), std::end(ppl2), [](Person p1, Person p2){ return p1.getName() > p2.getName(); });
    cout << "The comedians performing tonight sorted in reverse alphabetical order are: " << displayColl(ppl2) << endl;

    std::sort(std::begin(ppl2), std::end(ppl2), [](Person p1, Person p2){ return p1.getNb() > p2.getNb(); });
    cout << "The comedians performing tonight sorted by number are: " << displayColl(ppl2) << endl;

    std::sort(std::begin(ppl2), std::end(ppl2));
    std::stable_sort(std::begin(ppl2), std::end(ppl2), [](Person p1, Person p2){ return p1.getNb() < p2.getNb(); });
    cout << "The comedians performing tonight sorted by number and name are: " << displayColl(ppl2) << endl;

    std::sort(std::begin(ppl2), std::end(ppl2), [](Person p1, Person p2){ return p1.getName() > p2.getName(); });
    std::stable_sort(std::begin(ppl2), std::end(ppl2), [](Person p1, Person p2){ return p1.getNb() < p2.getNb(); });
    cout << "The comedians performing tonight sorted by number in ascending order and name in descending order are: " << displayColl(ppl2) << endl;

    std::sort(std::begin(ppl2), std::end(ppl2));
    std::stable_sort(std::begin(ppl2), std::end(ppl2), [](Person p1, Person p2){ return p1.getNb() > p2.getNb(); });
    cout << "The comedians performing tonight sorted by number in descending order and name are: " << displayColl(ppl2) << endl;

    std::sort(std::begin(ppl2), std::end(ppl2), [](Person p1, Person p2){ return p1.getName() > p2.getName(); });
    std::stable_sort(std::begin(ppl2), std::end(ppl2), [](Person p1, Person p2){ return p1.getNb() > p2.getNb(); });
    cout << "The comedians performing tonight sorted by number and name, both in descending order are: " << displayColl(ppl2) << endl;

    return 0;
}