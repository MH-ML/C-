#include <iostream>
using namespace std;

class Base {
    virtual void method() {std::cout << "from Base" << std::endl;}
public:
    virtual ~Base(){method();}
    void baseMethod() {method();}
};

class A : public Base {
    void method() {std::cout << "from A" << std::endl;}
public:
    A(){}
    ~A(){method();}
};

int main(void) {
    Base* bptr = new A();
    bptr->baseMethod(); // prints from A, subsequently A is destroyed, prints again from A
    delete bptr; //prints from Base
}