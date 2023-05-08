#include <iostream>
using namespace std;

//manages big array of doubles
class boVector {
    int size;
    double* arr_;

public:
    //COPY constructor with COSTLY DEEP copy:
    boVector(const boVector& rhs) {
        size=rhs.size;
        arr_=new double[size]; //new array
        for(int i=0; i<size; i++){arr_[i]=rhs.arr_[i];} //costly deep copy
    }
    //added MOVE constructor:
    boVector(boVector&& rhs){ // NOT const because we want bv to be changed
        size=rhs.size;
        arr_=rhs.arr_; //dereferencing
        rhs.arr_=nullptr; //
    }
    ~boVector(){delete arr_;}
};

//uses bv as argument:
void foo(boVector v);

//this function creates a new vector:
boVector createBoVector();


int main(){
    //create reusable = intended to be reused = new BoVector
    boVector reusable = createBoVector();
    //invoke copy constructor
    //expensive operation, but it's ok because content will be reused:
    foo(reusable);

    //this one will be NOT okay with usual copy constructor because we now pass an RVAL:
    //calls inexpensive MOVE constructor:
    foo(createBoVector());

    return 0;
}
