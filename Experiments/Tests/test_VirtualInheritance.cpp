#include <iostream>

class D {
public:
    void foo() {
        std::cout << "Foooooo" << std::endl;
    }
};

/* incorrect
class C:  public D {
};
*/
class C: virtual public D {
};

/*incorrect
class B:  public D {
};
*/
class B: virtual public D {
};

class A: public B, public C {
};

int main(int argc, const char * argv[]) {
    A a;
    a.foo();
}