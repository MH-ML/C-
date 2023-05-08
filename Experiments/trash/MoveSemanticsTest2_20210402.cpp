using namespace std;

class boVector{
    int size;
    double* arr_; // pointer to heap array

public:
    boVector(const boVector& input){
        size=input.size;
        arr_=new double[size]; //new heap array
        for (int i=0; i<size; i++){
            arr_[i]=input.arr_[i];
        }
    }
    boVector(boVector&& input){
        size=input.size; //size
        arr_=input.arr_; //dereferencing pointer to heap array
        input.arr_=nullptr;
    }
    ~boVector(){ delete arr_;}

};

void foo(boVector v);

boVector createBoVector();

void main(){

    boVector reusable = createBoVector();

    //copy constructor:
    foo(reusable);
    //move constructor:
    foo(createBoVector());


}
