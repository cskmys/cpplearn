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

    odds = std::count_if(std::begin(v), std::end(v), [](int ele){ return ele % 2 != 0; });
    cout << odds << endl;

    map<int, int> monthLen{ {1, 31}, {2, 28}, {3, 31}, {4, 30}, {5, 31}, {6, 30},
                            {7, 31}, {8, 31}, {9, 30}, {10, 31}, {11, 30}, {12, 31}};
    int longMonths = std::count_if(std::begin(monthLen), std::end(monthLen), [](std::pair<int, int> ele){ return ele.second == 31;});
    cout << longMonths << endl;

    return 0;
}