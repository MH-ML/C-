#include <iostream>
using namespace std;

extern "C"{
    void func(int i);
    void print(int i);
}

void func(int i){
    printf("%d", i);
}

void print(int i){
    printf("%d", 2*i);
}

int main()
{
   int i =10;
   func(i);
   print(i);
}