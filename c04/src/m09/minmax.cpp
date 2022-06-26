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
    vector<int> v{4, 1, 1, -2, 3, 0, 7, -6, 2, -9, 9};
    cout << "collection is: " << displayColl(v) << endl << endl;

    auto highIt = std::max_element(std::begin(v), std::end(v));
    cout << "max element in unsorted collection is: " << *highIt << endl;

    auto lowIt = std::min_element(std::begin(v), std::end(v));
    cout << "min element in unsorted collection is: " << *lowIt << endl << endl;

    auto v2 = v;
    std::sort(std::begin(v2), std::end(v2));
    cout << "sorted collection is: " << displayColl(v2) << endl << endl;

    cout << "max element in sorted collection is: " << *std::begin(v2) << endl;
    cout << "min element in sorted collection is: " << *(std::end(v2)-1) << endl;

    int n = 0;
    auto gtIt = std::upper_bound(std::begin(v2), std::end(v2), n);
    // go from beginning to end of v2 and find the first number that is greater than 0
    cout << "sorted collection upto the first element which is greater than " << n << " is : " << displayColl(std::begin(v2),gtIt) << endl;
    auto ltIt = std::lower_bound(std::begin(v2), std::end(v2), n);
    cout << "sorted collection starting from the first element which is not less than(meaning greater than or equal to) " << n << " is : " << displayColl(ltIt,std::end(v2)) << endl << endl;

    vector<Person> ppl{
            {"Sid", "Stark", 1000},
            {"Theo", "Von", 1000},
            {"Joe", "Rogan", 1000},
            {"George", "Carlin", 2000},
            {"Dave", "Chappelle", 2000},
    };
    cout << "The comedians performing tonight are: " << displayColl(ppl) << endl;

    std::sort(std::begin(ppl), std::end(ppl));
    cout << "The comedians performing tonight sorted in alphabetical order are: " << displayColl(ppl) << endl;
    /*
    auto p = std::lower_bound(std::begin(ppl), std::end(ppl), "Sid Stark"); // throws compilation error
    // predicate is "[](item_type i, n_type n){return i < n;}", here "item_type" is "Person" and "n_type" is "string"(or "const char*" to be specific)
    // we don't have an overload of operator "<" between "Person" and "String"
    // hence, the compilation error
    */
    string name = "Sid";
    auto p = std::lower_bound(std::begin(ppl), std::end(ppl), name, [](Person p, string n){return p.getName() < n;});
    cout << "The comedians performing tonight sorted in alphabetical order until " << name << " are: " << displayColl(std::begin(ppl), p) << endl;
    return 0;
}