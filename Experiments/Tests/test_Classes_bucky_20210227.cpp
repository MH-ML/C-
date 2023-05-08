//https://www.youtube.com/watch?v=jTS7JTud1qQ&list=PLAE85DE8440AA6B83&index=13
//https://www.youtube.com/watch?v=_b7odUc7lg0&list=PLAE85DE8440AA6B83&index=14

#include <iostream>
#include <string>
using namespace std;

class MyClass{
    public:
        MyClass(string z){ name = z;}
        void SaveName(string extName){ name = extName;}
        void PrintName(){ cout << name << endl;}
        string getName(){
            //name = "other name";
            return name;
            }
    private:
        string name;
};

int main(){
    string name="This name";
    
    MyClass obj(name);
    
    //obj.SaveName(name);
    
    std::cout << obj.getName() <<endl;
}