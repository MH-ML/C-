#include <iostream>
using namespace std;

int main(){
int a[5]={1,2,3,4,5};
    int i =3;
    int *ptr = a;
    std::cout << "*ptr: " << *ptr <<endl; // output: 1
    std::cout << "ptr: " << ptr <<endl; // output: <memCellAddress of element 0>
    std::cout << "a: " << a <<endl; // output: <memCellAddress of element 0>
    std::cout << "*a: " << *a <<endl; // output: 1
    std::cout << "&a: " << &a <<endl; // output: <memCellAddress of element 0>
    std::cout << "*(a+i): " << *(a+i) <<endl; // output: 3 = i-th element
    std::cout << "i[a]: " << i[a] <<endl; // output: 3
    std::cout << "a[i]: " << a[i] <<endl; // output: 3
}