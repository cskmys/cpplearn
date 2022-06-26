//
// Created by csk on 26/06/2022.
//

#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

class CoffeeMachine {
public:
    virtual CoffeeMachine* clone() = 0; // pure abstract class
    virtual void brew() = 0;
};

class SimpleCoffeeMachine : public CoffeeMachine {
public:
    CoffeeMachine* clone(){
        return new SimpleCoffeeMachine;
    }
    void brew(){
        std::cout << "Brewing simple coffee" << endl;
    }
};

class ComplexCoffeeMachine : public CoffeeMachine {
public:
    CoffeeMachine* clone(){
        return new ComplexCoffeeMachine;
    }
    void brew(){
        std::cout << "Brewing complex coffee" << endl;
    }
};

class EspressoCoffeeMachine : public CoffeeMachine {
public:
    CoffeeMachine* clone(){
        return new EspressoCoffeeMachine;
    }
    void brew(){
        std::cout << "Brewing espresso" << endl;
    }
};

// each of the derived classes implement clone and brew in their own way
// clone methods create an instance on the heap

class CoffeeMachineManager {
public:
    static CoffeeMachine* createMachine(int machineType){
        return machines[machineType]->clone();
    }
    ~CoffeeMachineManager(){}

private:
    static CoffeeMachine* machines[3];
};

CoffeeMachine* CoffeeMachineManager::machines[] = {
        new SimpleCoffeeMachine, new ComplexCoffeeMachine, new EspressoCoffeeMachine
};

int main(){
//    vector<CoffeeMachine*> myMachines[3];
//    CoffeeMachine* simpleMachine = CoffeeMachineManager::createMachine(0);
//    CoffeeMachine* complexMachine = CoffeeMachineManager::createMachine(1);
//    CoffeeMachine* espressoMachine = CoffeeMachineManager::createMachine(2);
//
//    myMachines->push_back(simpleMachine);
//    myMachines[1] = complexMachine;
//    myMachines[2] = espressoMachine;
//
//    for(auto curMachine : myMachines){
//        curMachinebrew();
//    }

}