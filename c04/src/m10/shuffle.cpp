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
#include <random>

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
    std::random_device randDev; // creating a random device
    std::mt19937 gen(randDev()); // create a "Mersenne Twister" with 19937 bits in the "Mersenne Prime" to use as a generator
    // "mt19937" is one of the best generators, this should be your goto choice

    vector<int> v{4, 1, 1, -2, 3, 0, 7, -6, 2, -9, 9};
    std::sort(std::begin(v), std::end(v));
    cout << "sorted collection is: " << displayColl(v) << endl;
    std::shuffle(std::begin(v), std::end(v), gen);
    cout << "shuffled collection is: " << displayColl(v) << endl << endl;

    vector<Person> ppl{
            {"Sid", "Stark", 1000},
            {"Theo", "Von", 1000},
            {"Joe", "Rogan", 1000},
            {"George", "Carlin", 2000},
            {"Dave", "Chappelle", 2000},
    };
    std::sort(std::begin(ppl), std::end(ppl));
    cout << "The comedians performing tonight sorted in alphabetical order are: " << displayColl(ppl) << endl;
    std::shuffle(std::begin(ppl), std::end(ppl), gen);
    cout << "The comedians performing tonight sorted in shuffled order are: " << displayColl(ppl) << endl << endl;

    return 0;
}