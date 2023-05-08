//https://www.youtube.com/watch?v=DudHooleNVg
//VIRTUAL FUNCTIONS
#include <iostream>
using namespace std;

class Enemy{
    public: 
        //virtual keyword --> function knows it's going to be used polymorphically
        virtual void attack(){}
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

