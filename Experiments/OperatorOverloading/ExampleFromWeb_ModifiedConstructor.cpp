#include <iostream>
using namespace std;
// https://www.tutorialspoint.com/cplusplus/cpp_overloading.htm

/* 
Mein Fehler war hier, dass ich den DEFAULT CONSTRUCTOR nicht kreiert hatte.
Somit konnte beim Operator-Overloading keine Box erstellt werden, ohne dass ihr Parameter übergeben wurden.
Dadurch gab es einen Compile-Fehler in Zeile 10 bei der Klassen-deklaration: no parameters handed over.
*/

class Box {
    public:
        //Alternative: Box(){} 
        //Alternative 2: hier Konstruktor mit Parametern weglassen:
        Box(int l, int b, int h){
            length=l;
            breadth=b;
            height=h;
        }
        double getVolume(void) {
            return length * breadth * height;
        }
        /* Alternative 2:
        void setLength( double len ) {
            length = len;
        }
        void setBreadth( double bre ) {
            breadth = bre;
        }
        void setHeight( double hei ) {
            height = hei;
        }
        */

        // Overload + operator to add two Box objects.
        Box operator+(const Box& b) {
            Box box(0,0,0);
            //Alternative: Box box;
            box.length = this->length + b.length;
            box.breadth = this->breadth + b.breadth;
            box.height = this->height + b.height;
            return box;
        }

    private:
        double length;      // Length of a box
        double breadth;     // Breadth of a box
        double height;      // Height of a box
};

// Main function for the program
int main() {
   Box Box1(6,7,5);                // Declare Box1 of type Box
   Box Box2(12,13,10);                // Declare Box2 of type Box
   Box Box3(1,1,1);                // Declare Box3 of type Box,
   double volume = 0.0;     // Store the volume of a box here
   /* Alternative 2:
   Box Box1;                // Declare Box1 of type Box
   Box Box2;                // Declare Box2 of type Box
   Box Box3;                // Declare Box3 of type Box,
   
   // box 1 specification
   Box1.setLength(6.0); 
   Box1.setBreadth(7.0); 
   Box1.setHeight(5.0);
 
   // box 2 specification
   Box2.setLength(12.0); 
   Box2.setBreadth(13.0); 
   Box2.setHeight(10.0);
   */
 
   // volume of box 1
   volume = Box1.getVolume();
   cout << "Volume of Box1 : " << volume <<endl;
 
   // volume of box 2
   volume = Box2.getVolume();
   cout << "Volume of Box2 : " << volume <<endl;

   // Add two object as follows:
   //Alternative 2: getVolume und cout weglassen hier, sonst Fehler:
   volume = Box3.getVolume();
   cout << "Volume of Box3 : " << volume <<endl;
   Box3 = Box1 + Box2;

   // volume of box 3
   volume = Box3.getVolume();
   cout << "Volume of Box3 : " << volume <<endl;

   return 0;
}