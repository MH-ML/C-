#include <iostream>
using namespace std;

class Something {
public:
    Something() {
        topSecretValue = 42;
    }
    int returnValue(){ return topSecretValue;}
    bool somePublicBool;
    int somePublicInt;
    std::string somePublicString;
private:
    int topSecretValue;
};
/*
class SomethingReplica {
public:
    int ReturnValue () { return topSecretValue;}
    bool somePublicBool;
    int somePublicInt;
    std::string somePublicString;
private:
    int topSecretValue;
};*/

int main(){
    Something a;
    /*
    SomethingReplica* b = reinterpret_cast<SomethingReplica*> (&a);
    std::cout << b->ReturnValue();*/
    std::cout << a.returnValue();
}