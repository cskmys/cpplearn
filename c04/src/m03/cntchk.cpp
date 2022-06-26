//
// Created by csk on 26/06/2022.
//

#include <iostream>
using std::cout;
using std::endl;

#include <list>
using std::list;

#include <map>
using std::map;

#include <algorithm>

int main(){
    list<int> v{2, 7, 1, 6, 2, -2, 4, 0};

    int odds = 0;
    for (auto ele : v) {
        if(ele % 2 != 0){
            ++odds;
        }
    }
    cout << odds << endl;

    bool all = odds == v.size();
    bool none = odds == 0;
    bool any = odds > 0;
    cout << all << none << any << endl;

    auto oddChk = [](int ele){return ele % 2 != 0;};
    // just using the right api does everything, you don't have to do a conditional check
    all = std::all_of(std::begin(v), std::end(v), oddChk);
    none = std::none_of(std::begin(v), std::end(v), oddChk);
    any = std::any_of(std::begin(v), std::end(v), oddChk);
    cout << all << none << any << endl;

}