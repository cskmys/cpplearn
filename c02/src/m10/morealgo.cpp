//
// Created by csk on 21/06/2022.
//
#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <algorithm>

template<class T>
void displayVec(vector<T>(v)){
    std::for_each(std::begin(v), std::end(v), [](int n){ cout << n << ", "; });
    cout << endl;
}

int main(){
    vector<int> v;
    int i = 0;
    std::generate_n(std::back_inserter(v), 15, [&](){ int temp = i++ % 5; return temp; });

    auto v3 = v;
    auto endV3 = std::remove_if(std::begin(v3), std::end(v3), [](int n){ return n == 3; });
    v3.erase(endV3, std::end(v3));

    std::generate_n(std::back_inserter(v3), 4, [&](){ return (rand() % 9) * (rand() % 2 == 0 ? 1 : -1); });

    displayVec(v3);

    std::sort(std::begin(v3), std::end(v3));
    // std::sort(v3); // from C++20 onwards
    displayVec(v3);

    // check if all the elements in the container match a particular condition
    bool allPos = std::all_of(std::begin(v3), std::end(v3), [](int n){ return n >= 0; });
    cout << allPos << endl;

    // the "std::string" itself is a collection of "char"
    string s{ "Hello I am a sentence" };
    // find the occurrence of something in the container
    auto letterIt = std::find(std::begin(s), std::end(s), 'a'); // what you get is an iterator to the first occurrence of 'a'
    // printing out the rest of the sentence from the first occurrence of 'a'
    std::for_each(letterIt, std::end(s), [](char c){ cout << c; }); // passing the iterator pointing to first occurrence of 'a' as the starting point
    cout << endl;

    // find the number of occurrences of something in the container
    auto caps = std::count_if(std::begin(s), std::end(s), [](char c){ return (c != ' ') && (toupper(c) == c); }); // predicate is "not a whitespace" and "an uppercase letter"
    cout << caps << endl;

    // now you can focus on what you want to achieve rather than how to achieve it

    return 0;
}