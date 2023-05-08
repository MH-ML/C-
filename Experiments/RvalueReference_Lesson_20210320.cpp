/*
Problem:
This code doesnt work.
The compiler gets confused about the various call possibilities and throws an error.

*/

void printInt(i){ cout << ' i is an lvalue: ' << i << endl;}
void printInt(&i){ cout << ' i is an lvalue: ' << i << endl;}
void printInt(&&i){ cout << ' i is an rvalue: ' << i << endl;}

int main(){
    
    int a=5;
    
    printInt(a);
    printInt(6);
    
}