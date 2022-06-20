//
// Created by csk on 20/06/2022.
//

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <algorithm>
#include <memory>
#include "Resource.h"

int main(){
    vector<int> nums{ 2, 3, 4, -1 , 1 };

    int x = 0;
    int y = 9;

    {
        std::unique_ptr<Resource> pRsrc(new Resource(", ")); // constructing here, hence you should see output from constructor
        // auto pRsrc = std::make_unique<Resource>(", "); // a better way to initialize available from C++14
        string msg = "elements belonging to [";
        msg += std::to_string(x) + ", " + std::to_string(y) + "]: ";
        /*
        std::for_each(std::begin(nums), std::end(nums), [=, &msg](int n){ // throws compilation error here
            // you cannot copy a "unique_ptr" as the copy constructor and copy assignment operators are inaccessible in a "unique_ptr"
            // hence you get a compilation error
            if(n >= x && n <= y){
                msg += pRsrc->getName() + std::to_string(n);
            }
        });
        */
        std::for_each(std::begin(nums), std::end(nums), [=, &msg, &pRsrc](int n){ // now "unique_ptr" is taken by reference,
            // hence no copy constructor or copy assignment operators are executed
            // in "Resource" class copy constructor and copy assignment operator is implement to print a message when they get executed
            // here you see no such output from copy constructor and copy assignment operator being printed on the console
            if(n >= x && n <= y){
                msg += std::to_string(n) + pRsrc->getName();
            }
        });
        cout << msg << endl;
    } // destructing "pRsrc" here, hence you should see output from destructor
    // if you had passed the lambda which uses "pRsrc" to another thread, and if that thread tried to execute the lambda after "pRsrc" has gone out of scope in this thread,
    // your code will crash, as "pRsrc" is a dangling reference
    // hence to solve such a problem you'll need to do "move" capture


    {
        std::unique_ptr<Resource> pRsrc(new Resource(", ")); // resource constructed, hence you'll see output from constructor
        string msg = "elements belonging to [";
        msg += std::to_string(x) + ", " + std::to_string(y) + "]: ";
        /*
        std::for_each(std::begin(nums), std::end(nums), [=, &msg, p=std::move(pRsrc)](int n){ // ownership of the memory is now moved from "pRsrc" to "p"
            // hence, you can longer use "pRsrc", doing so will throw compilation error
            if(n >= x && n <= y){
                msg += std::to_string(n) + pRsrc->getName(); // throws compilation error
                // "pRsrc" is no longer owner
            }
        });
        */
        std::for_each(std::begin(nums), std::end(nums), [=, &msg, p=std::move(pRsrc)](int n){ // now as ownership is moved from "pRsrc" to "p", "pRsrc" is invalid
            if(n >= x && n <= y){
                msg += std::to_string(n) + p->getName(); // now, we are using the proper variable "p", who has the ownership
            }
        } // "p" goes out of scope, hence its destructor is called, and you can see the output from destructor
        );
        cout << msg << endl; // unlike before where the resource was alive while the "msg" was printed, now the resource is dead before printing "msg"
        // hence, this time you'll not see "msg" printed between constructor and destructor output like last time
    } // "pRsrc" goes out of scope, but it has no ownership of anything, hence nothing happens
    // if you had passed the lambda which to another thread, now as the lambda has the ownership of the resource and also has captured "x" and "y" by copy,
    // hence, if "x" and "y" go out of scope in this thread or even if this thread itself ends, the other thread can still execute the lambda anytime without any fear of code crash

    return 0;
}