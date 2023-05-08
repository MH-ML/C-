#include <iostream>
using namespace std;

// Overloading only works with int& and int&&, if you add int then it won't work anymore:
void printInt(int&& a){ cout << "R value " << endl;}
void printInt(int& a){ cout << "L value " << endl;}

int main(){

int a=5;

printInt(a);
printInt(6);

}
