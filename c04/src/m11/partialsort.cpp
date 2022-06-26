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
    auto v2 = v;
    cout << "the collection is: " << displayColl(v) << endl;
    int n = 3;
    auto mid_n = find(std::begin(v), std::end(v), n);
    std::partial_sort(std::begin(v), mid_n, std::end(v));
    // the elements between "first" and "last" are partially sorted until the pre-sort position of "middle"
    cout << "partially sorted collection until the pre-sort position of " << n << " is: " << displayColl(v) << endl;
    auto sort_lim = std::is_sorted_until(std::begin(v), std::end(v));
    cout << "partially sorted collection is: " << displayColl(std::begin(v), sort_lim) << endl;

    mid_n = find(std::begin(v2), std::end(v2), n);
    vector<int> v3;
    /*
    v3.reserve((mid_n - std::begin(v2))); // "partial_sort_copy" doesn't work
    // "reserve" internally expand the array but as the vector is still not filled, "size()" will return 0
    // "partial_sort_copy" uses "size()" to figure out how many elements to partially sort
    // therefore, with "reserve", you'll get "size()" as "0", and "partial_sort_copy" does nothing
    // hence, do not use "reserve" here, use "resize" coz it not only does "reserve" but also fills in the default values
    // now, "size()" will return non-zero value and "partial_sort_copy" will do partial sorting
    */
    v3.resize((mid_n - std::begin(v2)));
    std::partial_sort_copy(std::begin(v2), std::end(v2), std::begin(v3), std::end(v3));
    cout << "a sorted collection until the pre-sort position of " << n << " in " << displayColl(v2) <<" is: " << displayColl(v3) << endl; // "v2" not modified

    mid_n = find(std::begin(v2), std::end(v2), n);
    std::nth_element(std::begin(v2), mid_n, std::end(v2));
    cout << "roughly partitioned collection at the pre-sort position of " << n << " : " << displayColl(v2) << endl << endl;

    vector<Person> ppl{
            {"Sid", "Stark", 1000},
            {"Theo", "Von", 1000},
            {"Joe", "Rogan", 1000},
            {"George", "Carlin", 2000},
            {"Dave", "Chappelle", 2000},
    };
    auto ppl2 = ppl;
    cout << "The comedians performing tonight are: " << displayColl(ppl) << endl;
    string name = "Joe Rogan";
    auto mid_name = find_if(std::begin(ppl), std::end(ppl), [name](Person p){ return p.getName() == name;});
    std::partial_sort(std::begin(ppl), mid_name, std::end(ppl));
    cout << "The comedians performing tonight sorted in alphabetical order until the pre-sort position of " << name << " are: " << displayColl(ppl) << endl;
    auto sort_till = std::is_sorted_until(std::begin(ppl), std::end(ppl));
    cout << "The comedians performing tonight who are sorted in alphabetical order are: " << displayColl(std::begin(ppl), sort_till) << endl;

    mid_name = find_if(std::begin(ppl2), std::end(ppl2), [name](Person p){ return p.getName() == name; });
    vector<Person> ppl3;
    ppl3.resize((mid_name - std::begin(ppl2)));
    std::partial_sort_copy(std::begin(ppl2), std::end(ppl2), std::begin(ppl3), std::end(ppl3));
    cout << "a sorted collection until the pre-sort position of " << name << " in " << displayColl(ppl2) <<" is: " << displayColl(ppl3) << endl;

    mid_name = find_if(std::begin(ppl2), std::end(ppl2), [name](Person p){ return p.getName() == name; });
    std::nth_element(std::begin(ppl2), mid_name, std::end(ppl2));
    cout << "comedians performing tonight roughly partitioned at the pre-sort position of " << name << " : " << displayColl(ppl2) << endl << endl;

    return 0;
}