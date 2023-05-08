/*
Problem:
This code doesnt work.
The compiler gets confused about the various call possibilities and throws an error.

*/

class boVector{

    int size;
    double* arr_;

    public:
        //This is the COPY CONSTRUCTOR - makes a very costly DEEP COPY:
        boVector(const boVector& rhs){
            size=rhs.size;
            arr_=new double[size];
            for (int i=0; i=size; i++){arr_[i]=rhs.arr_[i];}
        }
        // MOVE CONSTRUCTOR - shallow copy:
        boVector(boVector&& rhs){
            size=rhs.size;
            arr_=rhs.arr_;
            //dereferencing old array to null is necessary, otherwise our arr_ (new array) will be deleted
            rhs.arr_=nullptr;
        }
        ~boVector(){delete arr_;}
};

void foo(boVector v);

boVector createBoVector();

int main(){

    boVector reusable = new createBoVector();

    //invokes copy constructor:
    foo(reusable);

    //r-value usage --> invokes the move constructor:
    foo(createBoVector());

    return 0;
}
