/******************************************************************************

OVERLOADING BINARY + USING A MEMBER FUNCTION:
How to overload an operator related to privates

*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <ostream>
using namespace std;

class point{
    
    public:
        // this operator adds a point "p2" to the point of class "point"
	// construct point:
	point(double x, double y) : x(x), y(y)	{}
	// don't forget to implement the default constructor again since otherwise C++ will think you don't need it anymore
	point() {}
	
	friend ostream& operator<<(ostream& os, const point& p) {
	    os << "(" << p.x << ',' << p.y << ')'; // will output (x,y)
	    return os;
	}
	
    // OVERLOADING BINARY + USING A MEMBER FUNCTION:
    point operator+(point p){ // n is the 2nd number in the addition
        return point(x+p.x, y+p.y); // equals (this->x+p2.x, ...)
    }
        
    // private numbers 
    private:
        //declaration and initialization of x and y:
        double x=1.1,y=2.2;
};

int main()
{
    // Create two new points:
    point *p1 = new point ();
    point *p2 = new point ();
    
    cout << "\nPoint coordinates: " << *p1 << " , " << *p2;    
    cout << "\nThe result of the addition is: "  << (*p1+*p2);
    
    return 0;
}
