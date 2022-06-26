//
// Created by csk on 26/06/2022.
//

#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <algorithm>

int main(){
    vector<int> v{2, 7, 1, 6, 2, -2, 4, 0};
    
    int twos = 0;
    int const target = 2;
    for (size_t i = 0; i < v.size(); ++i) {
        if (v[i] == target){
            ++twos;
        }
    }
    cout << twos << endl;

    twos = std::count(v.begin(), v.end(), target);
    cout << twos << endl;
    twos = std::count(std::begin(v), std::end(v), target);
    cout << twos << endl;

    int odds = 0;
    for (auto ele : v) {
        if(ele % 2 != 0){
            ++odds;
        }
    }
    cout << odds << endl;

    odds = std::count_if(std::begin(v), std::end(v), [](auto ele){ return ele % 2 != 0; });

    return 0;
}