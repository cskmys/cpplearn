#include "CoffeeBuilder.h"

CoffeeBuilder Coffee::Create(std::string requestorName){ // this will return the instance of a "CoffeeBuilder" which implements the step-by-step workflow required to create the "Coffee"
    return CoffeeBuilder(requestorName);
}