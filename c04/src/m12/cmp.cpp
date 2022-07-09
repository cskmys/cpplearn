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
    vector<int> a{1, 2, 3, 4, 5};
    vector<int> b{1, 2, 0, 4};

    bool same = a.size() == b.size();
    for (unsigned int i = 0; i < a.size() && same; ++i) {
        if(a[i] != b[i]){
            same = false;
        }
    }
    cout << same << endl;

    same = std::equal(std::begin(a), std::end(a), std::begin(b));
    cout << same << endl;

    auto firstChange = std::mismatch(std::begin(a), std::end(a), std::begin(b));
    cout << *(firstChange.first) << " " << *(firstChange.second) << endl;
    auto nbSameEle = firstChange.first - std::begin(a);
    cout << nbSameEle << endl;

    return 0;
}