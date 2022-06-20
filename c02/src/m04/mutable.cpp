//
// Created by csk on 20/06/2022.
//

#include <iostream>
using std::cout;
using std::endl;

int main(){

    int x = 5;
    auto lamb = [x]() { return x + 5; }; // "x" captured by value, hence a copy is made.
    // the capture as "immutable", hence the internal copy cannot be changed and behaves as "const"
    // hence everytime you execute the lambda you get the same result

    int y = lamb();
    cout << "x(reset): " << x << ", y(lambda): " << y << endl;
    x = 20;
    y = lamb();
    cout << "x: " << x << ", y(lambda): " << y << endl; // even if you change the outside "x", the "x" captured by lambda is unaffected as it is captured by copy, and hence you get the same result

    x = 5;
    /*
    auto lambMut = [x]() { int y = x + 5; x += 1; return y; }; // throws compilation error
    // as the "mutable" keyword is not used, "x" cannot be changed
    */
    auto lambMut = [x]() mutable { int y = x + 5; x += 1; return y; }; // now as "mutable" keyword can be used  the internal copy of the "x" can be changed

    y = lambMut();
    cout << "x(reset): " << x << ", y(lambdaMut): " << y << endl;
    x = 20;
    y = lambMut();
    cout << "x: " << x << ", y(lambdaMut): " << y << endl; // even after doing "mutable" outside "x" doesn't impact inside as it is captured by copy

    cout << "------------------------" << endl;

    x = 5;
    cout << "x(reset): " << x << endl;
    auto lambRef = [&x]() { return x += 5; }; // "x" captured by reference, hence no copy is made.
    // the capture as "immutable", as there is no internal copy, whether the "mutable" keyword is used or not, doesn't matter

    y = lambRef();
    cout << "x(lambdaRef): " << x << ", y(lambdaRef): " << y << endl;
    x = 20; // now as "x" is modified outside, the change will also be visible on the inside of the lambda
    y = lambRef(); // now inside the lambda modified "x" is used
    cout << "x(lambdaRef): " << x << ", y(lambdaRef): " << y << endl;

    x = 5;
    cout << "x(reset): " << x << endl;
    auto lambRefMut = [&x]() mutable { return x += 5; }; // as mentioned above "mutable" keyword is irrelevant

    y = lambRefMut();
    cout << "x(lambdaRefMut): " << x << ", y(lambdaRefMut): " << y << endl;
    x = 20;
    y = lambRefMut();
    cout << "x(lambdaRefMut): " << x << ", y(lambdaRefMut): " << y << endl;

    // in conclusion, "mutable" keyword is only relevant for capture by value

    return 0;
}