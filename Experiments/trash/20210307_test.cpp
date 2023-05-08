#include <iostream>
using namespace std;

//prototypes:
int sum(int, int);
int sum(int, int, int);

int sum(int a, int b){
    
    a+=b;
    
    return a;
}

int sum(int a, int b, int c){
    
    a+=b;
    a+=c;
    
    return a;
}

int main(){
    
    /*
    //function overloading:
    int a=1, b=2, c=3;
    int res1=0, res2=0;
    
    res1=sum(a,b);
    res2=sum(a,b,c);
  
    std::cout << res1 << endl;
    std::cout << res2 << endl;
    */
    
}


