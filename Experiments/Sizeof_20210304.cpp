#include <iostream>
using namespace std;

int main (){
    
    char c;
    int i;
    short s;
    long l;
    double d;
    size_t sz;
    double d_a[8];
    
    cout << "size of char: " << sizeof(c) << "[byte]" << endl;
    cout << "size of int: " << sizeof(i) << "[byte]" << endl;
    cout << "size of short: " << sizeof(s) << "[byte]" << endl;
    cout << "size of long: " << sizeof(l) << "[byte]" << endl;
    cout << "size of double: " << sizeof(d) << "[byte]" << endl;
    cout << "size of size_t: " << sizeof(sz) << "[byte]" << endl;
    
    cout << "size of double d_a[8]: " << sizeof(d_a) / sizeof(d_a[0]) << "elements" << endl;
    cout << "size of double d_a[8]: " << sizeof(d_a) << "[byte]" << endl;
    
}