// CAR CONFIGURATOR APP
/*
Which C++ features I want to include:
??? - enums not coded in numbers but in strings https://www.codeguru.com/cpp/cpp/cpp_mfc/article.php/c4067/Switch-on-Strings-in-C.htm
sort
filter
friend function
range-based for loop
function overloading
operator overloading (+,-, strings)
statics
externs
const functions, const classes
move semantics
abstract classes???
destructors
vectors
encapsulation & security
all kinds of casts (reinterpret_cast, dynamic_cast, static_cast)
pointer arithmetics
templates
templates: specialized method (https://www.youtube.com/watch?v=kRVjG3qb7RE from minute 10:00)

Done implementing:
Lambda
Inheritance
Virtual functions
Operator overloading (<<)
enums
mapping
for_each

What the app should do:
- user can choose car, year, model, name, engine, gearbox, cabin details (from "database"/file?)
- User can choose no. of cars to park into their garage
- car is being created then
- computation of fuel consumption, sales price, VIN, ...

*/
#include "car.h"
#include "lexus.h"

#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <list>
#include <vector>
#include <algorithm> //this one includes e.g. for_each, filter, sort, etc.
#include <cstdlib>

using namespace std;

enum model {LEXUS_IS = 1, CORVETTE = 2, FERRARI = 3, MINI_COOPER = 4};
enum category {SUBCOMPACT = 1, COMPACT_EXECUTIVE = 2, SPORTS_CAR = 3};

//template class, contains SPECIALIZED METHOD
//template<class T>

//Output: Read-in integer from keyboard, checked if within min/max borders
// validity criterion: i>=i_Min && i<=i_Max
//Input: minimum and maximum allowable value
int i_IntSelnLimd(const int& i_Min, const int& i_Max){
    
    std::string line;
    int i_choice=0;
    
    while(true){
        std::getline(std::cin, line);

        std::istringstream is(line);

        // First we attempt to extract an int from the streem
        // if successful, we jump all whitespce (using std::ws) and then try
        // to get a char. If that's successful we were given a string with chars
        // after the int, e.g. "67kg" or "99 red balloons".
        char dummy;
        if (!(is >> i_choice) || (is >> std::ws && is.get(dummy)) || !(i_choice>=i_Min&&i_choice<=i_Max)){
            std::cout << "Invalid input. Try again!\n";
        }
        else{
            break;
        }
        
    }
    
    return i_choice;
}

//OVERLOADING << FOR MODEL:
//uses feature MAP = associative STL container
std::ostream& operator<<(std::ostream& out, const model value){
    //create associative STL container:
    static std::map<model, std::string> strings;
    
    //why check for zero?
    if (strings.size() == 0){
    //what does the define do?
#define INSERT_ELEMENT(p) strings[p] = #p
        INSERT_ELEMENT(LEXUS_IS);     
        INSERT_ELEMENT(CORVETTE);     
        INSERT_ELEMENT(FERRARI);      
        INSERT_ELEMENT(MINI_COOPER);           
#undef INSERT_ELEMENT
    }   

    return out << strings[value];
}

//OVERLOADING << FOR CATEGORY:
//uses feature MAP = associative STL container
std::ostream& operator<<(std::ostream& out, const category value){
    //create associative STL container:
    static std::map<category, std::string> strings;
    
    //why check for zero?
    if (strings.size() == 0){
    //what does the define do?
#define INSERT_ELEMENT(p) strings[p] = #p
        INSERT_ELEMENT(SUBCOMPACT);     
        INSERT_ELEMENT(COMPACT_EXECUTIVE);     
        INSERT_ELEMENT(SPORTS_CAR);            
#undef INSERT_ELEMENT
    }   

    return out << strings[value];
}



/*
//SPECIALIZED METHOD:
//what it does: only used if the handed over type is <int>
//otherwise, other method of class car is used
template<>
double calcFuelConsumption<int>::car{
    
}

class car_modelInfo{
    public:
        car_modelInfo(){}
    private:
        string s_model;
        string s_mdlName;
        string s_manufPlant; //manufacturing location/plant
};


class powertrain: public car{
    public:
        powertrain(){}
    private:
        string s_engine;
        string s_gearbox;
        string s_axes;
        int i_horsePower;
        int i_maxTorque;
        int i_maxEngSpd;
};

class engine: public powertrain{
    public:
        engine(){}
    
};

class chassis: public car{
    public:
        chassis(){}
    private:
        int i_wheelSize;
        int i_length, i_width, i_height;
        string engPos; // front, middle , rear
};

class interior: public car{
    public:
        interior(){}
    private:
        int i_noOfSeats;
        bool b_airCond;
        int i_noOfDoors;
        string s_multimediaSys; // affordable, medium, premium
};
*/

//Function returning two floats:
//MPG-based and LP100KM-based lists
void FuelConsMPGandLP100km(){
    
    std::vector<float> f_MPG;
    std::vector<float> f_LP100km;
    
    for(float f=5; f<20; f+=1.0){
        f_LP100km.push_back(f);
    }
    
    std::for_each(f_LP100km.begin(), f_LP100km.end(), [&](float x){f_MPG.push_back(235/x);});
    
    std::cout << "\nThis is a table listing fuel consumption.\nLeft: L/100km, Right: MPG" << endl;
    
    for(int i=0; i<f_LP100km.size(); i++)
        std::cout << f_LP100km[i] << ", " << f_MPG[i] << endl;

}

int main(){
    
    cout << "*************** THIS IS MY CAR POOL APP ***************" << endl;
    
    car *c1ptr = new car();
    cout << "\nCurrent car model: " << c1ptr->e_carmodel << endl;
    cout << "Current car category: " << c1ptr->e_carCategory << endl;
    cout << "Current car fuel consumption: " << c1ptr->f_CalcFuelCons() << endl;
    FuelConsMPGandLP100km();
    
}