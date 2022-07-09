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
#include <numeric>

int main(){
    vector<int> a{1, 2, 3, 4, 5};

    int total = 0;
    for(auto i : a){
        total += i;
    }
    cout << total << endl;

    total = std::accumulate(std::begin(a), std::end(a), 0);
    cout << total << endl;

    auto evenTotal = std::accumulate(std::begin(a), std::end(a), 0, [](int total, int i){ return (i % 2 == 0) ? (total + i) : total; });
    cout << evenTotal << endl;

    auto prod = std::accumulate(std::begin(a), std::end(a), 1, [](int total, int i){ return total * i; } );
    cout << prod << endl;

    vector<string> words{"one", "two", "three"};
    auto allWords = std::accumulate(std::begin(words), std::end(words), string{});
    cout << allWords << endl;

    allWords = std::accumulate(std::begin(words), std::end(words), string{"words:"}, [](const string& total, const string& s){ return total + " " + s + ","; } );
    cout << allWords << endl;

    auto nbString = std::accumulate(std::begin(a), std::end(a), string{"The numbers are:"}, [](const string& total, int i){ return total + " " + std::to_string(i); } );
    cout << nbString << endl;

    return 0;
}