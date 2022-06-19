#include <iostream>

int main(){
    double d1 = 2.2;
    int i5 = static_cast<int>(d1); // casting done c++ style, never use the unsafe c-style round bracket casting

    std::cout << "d1= " << d1 << std::endl;
    std::cout << "i5= " << i5 << std::endl;

    bool flag = false;
    std::cout << "flag= " << flag << std::endl;

    flag = static_cast<bool>(d1);
    std::cout << "flag= " << flag << std::endl;
}