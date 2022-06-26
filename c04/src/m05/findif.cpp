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
string displayVec(Iter b, Iter e){
    std::stringstream ss;
    std::for_each(b, e, [&](typename Iter::value_type n){ ss << n << ", "; });
    string s = ss.str();
    return s; // though you are returning a local variable, as it is movable, compiler moves it
}

template<typename T>
string displayVec(T v){
    return displayVec(std::begin(v), std::end(v));
}

int main(){
    vector<int> v{4, 2, 6, 6, 1, 3, -2, 0, 11, 2, 3, 2, 4, 4, 2, 4, 3};
    cout << "vector 'v' is: " << displayVec(v) << endl << endl;

    auto oddChk = [](int ele){return ele % 2 != 0;};
    auto res = std::find_if(std::begin(v), std::end(v), oddChk);
    cout << "the first odd value is: " << (res != std::end(v)  ? std::to_string(*res) : "") << endl << endl;

    res = std::find_if_not(res, std::end(v), oddChk);
    cout << "the first not an odd value after the first odd value is: " << (res != std::end(v)  ? std::to_string(*res) : "") << endl << endl;

    vector<int> primes{1, 2, 3, 5, 7, 11, 13};
    cout << "the sequence of 'primes' is: " << displayVec(primes) << endl;
    res = std::find_first_of(std::begin(v), std::end(v), std::begin(primes), std::end(primes));
    cout << "the first element found in 'v' that belongs to 'primes' is: " << (res != std::end(v)  ? std::to_string(*res) : "") << endl << endl;

    vector<int> subsequence{2, 4};
    cout << "the 'subsequence' is: " << displayVec(subsequence) << endl;
    res = std::search(std::begin(v), std::end(v), std::begin(subsequence), std::end(subsequence));
    // "res" is the iterator to the position where the first occurrence of "2, 4" was found
    cout << "'v' from the first 'subsequence' match is: " << displayVec(res, std::end(v)) << endl;
    res = std::find_end(std::begin(v), std::end(v), std::begin(subsequence), std::end(subsequence));
    cout << "'v' from the last 'subsequence' match is: " << displayVec(res, std::end(v)) << endl << endl;

    res = std::search_n(std::begin(v), std::end(v), 2, 4);
    cout << "'v' from the first point where there are 2 consecutive occurrences of '4' is: " << displayVec(res, std::end(v)) << endl << endl;

    res = std::adjacent_find(std::begin(v), std::end(v));
    cout << "'v' from the first point where there are 2 consecutive occurrences of same number is: " << displayVec(res, std::end(v)) << endl << endl;

    string s{"Hello I am a sentence"};
    cout << "string 's' is: " << s << endl << endl;

    string am = "am";
    cout << "string 'am' is: " << am << endl << endl;
    auto letter = std::search(std::begin(s), std::end(s), std::begin(am), std::end(am));
    cout << "'s' from the point of first match with 'am' is: " << displayVec(letter, s.end()) << endl;
    return 0;
}