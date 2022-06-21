//
// Created by csk on 21/06/2022.
//
#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <algorithm>
#include <numeric>

template<class T>
void displayVec(vector<T>(v)){
    std::for_each(std::begin(v), std::end(v), [](int n){ cout << n << ", "; });
    cout << endl;
}

int main(){
    vector<int> v;

    int i = 0;
    std::generate_n(std::back_inserter(v), 15, [&](){ int temp = i++ % 5; return temp; });

    displayVec<int>(v);

    /*
    auto v1 = v;
    for(auto i = 0; i < v1.size(); ++i){
        if(v1[i] == 3){ // can cause code crash
            v1.erase(v1.begin() + i);
        }
    }
    displayVec<int>(v1);
    // indexing over the very collection that you are modifying may cause code crash
    // but, sometimes it may not, maybe coz the vector didn't discard its internal array to create a smaller one
    // hence, wherever it was writing into beyond its size might still a valid location from OS point of view
    // but in any case just don't do it
    */

    /*
    auto v2 = v;
    for(auto it = std::begin(v2); it != std::end(v2); ++it){ // can cause code crash
        if (*it == 3){
            v2.erase(it);
        }
    }
    displayVec<int>(v2);
    // using iterators to modify the very collection that it is iterating may cause code crash
    // just don't do it
    */

    auto v3 = v;
    auto endV3 = std::remove_if(std::begin(v3), std::end(v3), [](int n){ return n == 3; });
    // moves all elements that needed to be removed to the end and returns the point from the end that needs to be erased
    v3.erase(endV3, std::end(v3)); // erase from that point to the end

    displayVec<int>(v3);

}