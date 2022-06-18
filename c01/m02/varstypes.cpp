#include <iostream>

int main(){
    int i1 = 1; // declaration and initialization at same place
    std::cout << "i1= " << i1 << std::endl;

    int i2; // only declaration, so variable is uninitialized, meaning they can have a junk value as unlike other languages CPP doesn't put a default value for uninitialized variables
    std::cout << "uninitialized i2= " << i2 << std::endl;
    i2 = 2; // initialization
    std::cout << "i2= " << i2 << std::endl;

    int i3(3); // this type mostly initialization of objects
    std::cout << "i3= " << i3 << std::endl;

    int i4{4}; // this type mostly initialization of collections, but you can use it (with a lil bit of care) for a single value
    std::cout << "i4= " << i4 << std::endl;


    double d1 = 2.2;
    double d2 = i1; // there is no loss of precision by putting integer into double
    int i5 = d1; // you have a loss of precision by putting double into a integer, hence a warning

    std::cout << "d1= " << d1 << std::endl;
    std::cout << "d2= " << d2 << std::endl;
    std::cout << "i5= " << i5 << std::endl; // 2.2 truncated as 2

    char c1 = 'a';
    std::cout << "c1= " << c1 << std::endl;

    /*
    char c2 = "b"; // will throw compilation error
    // "b" is a c-style string which is a collection of 2 characters 'b' and '\0'(null character to terminate the string),
    // not a single character which is the type of variable
    */

    bool flag = false;
    std::cout << "flag= " << flag << std::endl;

    flag = i1; // int converted to bool, 0 -> false, otherwise -> true
    std::cout << "flag= " << flag << std::endl;

    flag = d1; // you have a loss of precision as it converts double to bool(0.0 -> false, otherwise -> true), so you have a warning
    std::cout << "flag= " << flag << std::endl;

    flag = 0.8;
    std::cout << "flag= " << flag << std::endl;

    flag = 0.0;
    std::cout << "flag= " << flag << std::endl;

    // auto
    auto a1 = 1; // int, short could have also been used but the type inference system just prefer integer
    auto a2 = 2.2; // double, float could have also been used but the type inference system prefers double
    auto a3 = 'c'; // character
    auto a4 = "s"; // const char* which is a c-style string
    auto a5 = true; // bool
    auto a6 = 3l; // literal 'l' to force type inference to pick long instead of int
    auto a7 = 1'000'000'000'000; // long, digit separators introduced in C++14
    auto a8 = 0xff; // int
    auto a9 = 0b111; // int, binary literal introduced in C++14
    auto a10 = 1u; // literal 'u' to force type inference to pick unsigned int instead of regular (signed) int
    auto a11 = 1.1f; // literal 'f' required to force type inference to pick float instead of double

    unsigned char n1 = 128; // unsigned can hold 0 to 255
    char n2 = 128; // signed char can hold -128 to 127, hence the warning
    std::cout << "n1= " << n1 << std::endl;
    std::cout << "n2= " << n2 << std::endl; // 128 is 0b 1000 0000, hence its interpreted as -128

    n1 = 254;
    n2 = 254; // 254 is 1b 1111 1110, hence its interpreted as -2
    std::cout << "n1= " << n1 << std::endl;
    std::cout << "n2= " << n2 << std::endl;

    n1 = 300; // can hold only 0 to 255, hence the warning
    n2 = 300;
    std::cout << "n1= " << n1 << std::endl; // 300 is 0b 1 0010 1000, hence anything more than first 8 bits are truncated and interpreted as unsigned char i.e. 44
    std::cout << "n2= " << n2 << std::endl; // 300 is 0b 1 0010 1000, hence anything more than first 8 bits are truncated and interpreted as char i.e. 44


}