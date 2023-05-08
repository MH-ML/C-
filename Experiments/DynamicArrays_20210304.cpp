#include <iostream>
using namespace std;

int SIZE=3;

int main(){
    
    //This way of declaration+definition is essentially the same as the form below:
    //int* dArray;
    //dArray= new int[SIZE];
    //is the same as:
    int* dArray= new int[SIZE];
    int a=10;
    int *aptr=&a;
    
    std::cout << "*aptr: " << *aptr << endl;
    std::cout << "aptr: " << aptr << endl;
    // std::cout << "*a: " << *a << endl; invalid type: a is not a pointer!
    std::cout << "a: " << a << endl;
    std::cout << "&a: "<< &a << endl;
    
    //for pointer array elements, do not use the * when assigning values:
    dArray[0]=10;
    dArray[1]=3;
    dArray[2]=2;
    
    for (int i=0; i<SIZE; i++){
        std::cout << dArray[i] << endl;
    }
    
    delete [] dArray;
    
    //return 0;
}
