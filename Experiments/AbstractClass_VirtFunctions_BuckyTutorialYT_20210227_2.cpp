//https://www.youtube.com/watch?v=ndz3EHpFEZc
//ABSTRACT CLASSES

/*

ABSTRACT CLASS = class including pure virtual function

Pure virtual function:
- does NOT give the option of inheriting from the BASE class
- do NOT have a body at all, just write =0;

Advantages:
- ASSURES that you write your specific function replacing the virtual one --> safety mechanism
Disadvantages:
- have to specify a function no matter what -> default behavior not available

*/
#include <iostream>
using namespace std;

class Enemy{
    public: 
        //pure virtual function: - PURE - has NO implementation/body  whatsoever  - it does not do ANYTHING at all
        //ATTENTION! Rule: Any derived class that has pure virtual function in it MUST OVERWRITE that virtual function - NO EXCEPTIONS ALLOWED!
        virtual void attack()=0;
};

class Ninja: public Enemy{
    public:
        void attack(){
            cout << "I am a Ninja! Attack!" << endl;
        }
};

class Monster: public Enemy{
    public:
        void attack(){
            cout << "I am a Monster! Attack!" << endl;
        }
        
};

int main(){
    Ninja n;
    Monster m;
    
    Enemy *enemy1 = &n;
    Enemy *enemy2 = &m;
    
    enemy1->attack();
    enemy2->attack();
}

