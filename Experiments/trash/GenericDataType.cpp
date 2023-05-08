#include <iostream>
using namespace std;

template <class T, class U>
U calc(T a, U b){
    return a+b;
}

int main(){
    float a=5.5;
    int b=21;
    
    //calc(a,b);
    
    std::cout << calc(a,b) << endl;
}