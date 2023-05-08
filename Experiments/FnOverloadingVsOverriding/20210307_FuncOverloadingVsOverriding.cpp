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

class base{
    public:
        base(){}
        void print(){
            std::cout << "Print base" << std::endl;
        }
};

class derived:public base {
    public:
        derived(){}
        void print(){
            std::cout << "Print derived" << std::endl;
        }
};
        

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
    
    //function overriding:
    derived objD;
    objD.print();
    
    base objB= derived();
    objB.print();
    
    base objB2;
    objB2.print();
    
}


