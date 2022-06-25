//
// Created by csk on 25/06/2022.
//

#ifndef NOISE_H
#define NOISE_H

#include <iostream>
#include <string>

class Noise {
private:
    std::string soundIMake;
public:
    Noise(std::string sim) : soundIMake(sim){ std::cout << "Constructing noise " << soundIMake << std::endl; }
    ~Noise(){ std::cout << "Destructing noise " << soundIMake << std::endl; }
};

#endif // NOISE_H
