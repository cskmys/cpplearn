//
// Created by csk on 25/06/2022.
//

#ifndef GLOBALCOFFEECFG_H
#define GLOBALCOFFEECFG_H

#include <map>
#include <string>

class GlobalCoffeeCfg {
private:
    std::map<std::string, std::string> coffeeState;
    GlobalCoffeeCfg(){} // private constructor makes sure that no one can instantiate this class
public:
    GlobalCoffeeCfg(GlobalCoffeeCfg const&) = delete; // delete copy constructor
    GlobalCoffeeCfg& operator=(GlobalCoffeeCfg const&) = delete; // delete copy assignment operator
    // to make sure that no copy of the object can be made
    static GlobalCoffeeCfg& get(){ // a "static" method for retrieving singleton instance
        // "static" otherwise not possible to call this without an object instance which is not possible to create as constructor is "private"
        static GlobalCoffeeCfg cfg;
        return cfg;
    }
    void SetState(std::string const& key, std::string const& value){
        coffeeState.insert(std::pair<std::string, std::string>(key, value));
    }
    std::string GetState(std::string const& key){
        auto it = coffeeState.find(key);
        return it->second;
    }
    // if this were used in a concurrent program a mutex would be needed to make sure that at any given point in time,
    // when a thread has access to "SetState" or "GetState", no other threads will have access to both
};

#endif // GLOBALCOFFEECFG_H
