#include <iostream>
using namespace std;

class A{
    public:
        A(){}
        ~A(){}
        void foo(){ std::cout << "fooo!" << std::endl;}
};

class B1:virtual public A {
    public:
        B1(){}
        ~B1(){}
};

class B2:virtual public A {
    public:
        B2(){}
        ~B2(){}
};

class C:public B1, public B2 {
    public:
        C(){}
        ~C(){}
};

int main(){
    
    A a;
    a.foo();
    
}