#include <iostream>
using namespace std;

class boVector{
        double* arr_;
        int size;
public:
    //copy constructor:
    boVector(const boVector& input){
        size=input.size;
        arr_=new double[size];
        for(int i=0; i<size; i++){arr_[i]=input.arr_[i];}
    }
    boVector(boVector&& input){
        size=input.size;
        arr_=input.arr_;
        input.arr_=nullptr;
    }
};

void foo(boVector v);

boVector createBoVector();

void main(){
    boVector reusable = createBoVector();

    foo(reusable);

    foo(createBoVector());


}
