#include <iostream>
using namespace std;

class Something {
public:
    Something() {
        topSecretValue = 42;
    }
    bool somePublicBool;
    int somePublicInt;
    std::string somePublicString;
private:
    int topSecretValue;
};

class SomethingReplica {
public:
    int returnSecretValue(){ return topSecretValue;};
    bool somePublicBool;
    int somePublicInt;
    std::string somePublicString;
private:
    int topSecretValue;
};

int main(){
    Something a;
    SomethingReplica* b= reinterpret_cast<SomethingReplica*> (&a);
    
    std::cout << b->returnSecretValue();
    
}