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

int main(){
    vector<int> v{2, 4, 6, 6, 1, 3, -2, 0, 11, 2, 3, 2, 4, 4, 2, 4};
    auto res = std::find(std::begin(v), std::end(v), 0);
    cout << "is there a 0?: " << (res != std::end(v)  ? "yes" : "no") << endl;

    res = std::find(res, std::end(v), 2);
    cout << "is there a 2 after a 0?: " << (res != std::end(v) ? "yes" : "no") << endl;

    string s{"Hello I am a sentence"};

    auto letter = std::find(std::begin(s), std::end(s), 'a');
    cout << "is there an occurrence of 'a'? " << (letter != std::end(s) ? "yes" : "no") << endl;

    return 0;
}