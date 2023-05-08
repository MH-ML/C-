#include <iostream>
using namespace std;
//// Please write a function that
// * given an array with numbers
// * returns the second largest element of that array
// * without sorting the array

template<typename T>
T func(T a[], int length){
    
    T largest=(T)0, second=(T)0;
    
    for(int i=0; i<sizeof(a); i++){
        /*if(a[i]>largest){
            largest = a[i];
        }else if(a[i]>second){
            second = a[i];
        }*/
        
        if(a[i]>largest){
            second=largest;
            largest=a[i];
        }
    }
    
    return second;
    
}

class Person {
    
    private:
        
    
}​​;



int main(){
    
    int a={1,2,4};
    int length=3;
    
    Person kollegen[] = {​​...}​​
    
    std::cout << func(a,length);
}

/*

Merke:
a[4]=[...,...,...,...] geht, bei [] immer Länge angeben
a={...,...,...,...} --> keine Längenangabe notwendig
template<typename T>
T func(T a[], int length) --> hier hatte ich "T" vergessen (Eingangs-Datentyp)
Operator-Overloading wiederholen, wurde erwähnt
Größe eines Pointers ist IMMER 4 Byte, unabhängig vom Datentyp
.size() kann man nur auf Vektoren anwenden
sizeof(a) geht bei Arrays
Lambda-Funktionen wiederholen


*/