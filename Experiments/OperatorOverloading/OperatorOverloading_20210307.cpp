#include <iostream>
using namespace std;

class Box{
    public:
        Box(int l, int h, int w){
            length=l;
            height=h;
            width=w;
        }
        Box operator+(const Box& b){
            //for returning an object, create a new one:
            //an old one could be also used, but then you'd overwrite the attributes of the existing object...
            Box Box;
            //new length = length of left-side operand + length of right-side operand:
            Box.length = this->length + b.length;
            Box.width = this->width + b.width;
            Box.height = this->height + b.height;
            return box;
        }
      
        int length;
        int width;
        int height;
};

int main(){
    
    Box a(1,2,3);
    Box b(4,5,6);
    Box c=a+b;
    
    std::cout << "a.length: " << a.length << ", a.width: " << a.width << ", a.height: " << a.height << std::endl;
    std::cout << "b.length: " << b.length << ", b.width: " << b.width << ", b.height: " << b.height << std::endl;
    std::cout << "c.length: " << c.length << ", c.width: " << c.width << ", c.height: " << c.height << std::endl;
    
}
    