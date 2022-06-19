#include <iostream>

using std::cout;
using std::endl;
using std::string;

int main(){

    const int ci = 10;
    cout << "ci: " << ci << endl;

    int i = 5;
    cout << "i: " << i << endl;

    int *pi = &i; // pointer to target
    *pi = 50;
    cout << "i(after pi): " << i << endl;
    cout << "pi: " << *pi << endl;
    /*
    *pi = &ci; // throws compilation error
    // as "pi" can point to only non-const targets, it can allow changes to the target
    // here "ci" cannot be changed, hence "pi" cannot point to "ci"
    */

    int * const cpi = &i; // const pointer to target
    *cpi = 500; // this is allowed coz the pointer "cpi" is constant meaning it cannot be reinitialized to something else but
    // the target "i" is non-const, meaning "i" can be modified via "cpi"
    cout << "i(after cpi): " << i << endl;
    cout << "cpi: " << *cpi << endl;
    /*
    cpi = &ci; // throws compilation error
    // as "cpi" is a constant, it cannot be changed
    // hence "cpi" cannot reinitialized to point to "ci"
    */

    int const * pci = &ci; // pointer to constant target
    cout << "pci(pointing to ci): " << *pci << endl;
    pci = &i; // using a pointer that points to a constant target on a non-const target will treat the non-const target as const target
    // treating a non-cost as const causes no harm, hence this is allowed
    /*
    *pci = 5; // throws compilation error
    // even if "pci" is pointing to a non-const "i", the "pci" itself is const, hence, you cannot modify "i" using "pci"
    // hence the error
    */
    cout << "pci(pointing to i): " << *pci << endl;

    int const * const cpci = &ci; // constant pointer to constant target
    cout << "cpci(pointing to ci): " << *cpci << endl;
    /*
    cpci = &ci; // throws compilation error
    // as "cpci" is a constant pointer, it cannot be reinitialized to point to another target irrespective of the target's const type
    // hence, the compilation error
    */
    return 0;
}
