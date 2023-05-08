#include "Sally.h"
#include <iostream>
using namespace std;

Sally::Sally(int a, int b): 
regVar(a), constVar(b) {
    
}

void Sally::printSally(){
    std::cout << "Regular: " << regVar << ", constant: " << constVar << endl;
}



