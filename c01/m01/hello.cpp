#include <iostream> // preprocessor directive to add code from another file into your file
#include <string>

int main(){ // can leave parameters blank if there are no command line arguments
    std::cout << "Name?" << std::endl; // :: is a scope resolution operator
    // "std" standard as in standard library
    // "cout" console output, "<<" from, "endl" end line
    // "cin" console input, ">>" to
    std::string name;
    std::cin >> name;
    // line-oriented language where code is written as lines each of which is terminated by ";"
    std::cout << "Hello, " << name << std::endl;

    return 0; // for OS to know how the execution went
}
