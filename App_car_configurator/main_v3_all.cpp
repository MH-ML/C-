// CAR CONFIGURATOR APP
/*
Which C++ features I want to include:
Interfaces, pure virtual function
??? - enums not coded in numbers but in strings https://www.codeguru.com/cpp/cpp/cpp_mfc/article.php/c4067/Switch-on-Strings-in-C.htm
sort
filter
friend function
range-based for loop
function overloading
operator overloading (+,-, strings)
externs
const functions, const classes
move semantics
abstract classes???
destructors
vectors
all kinds of casts (reinterpret_cast, dynamic_cast, static_cast)
pointer arithmetics
templates
templates: specialized method (https://www.youtube.com/watch?v=kRVjG3qb7RE from minute 10:00)
templates & rvalue reference https://www.youtube.com/watch?v=0xcCNnWEMgs

Done implementing:
shared pointers
Lambda
Inheritance
PURE Virtual functions
Operator overloading (<<)
enums
mapping
for_each
static/static const
encapsulation & security - via private members - accessible only via public member functions
std::reference_wrapper (is a class template that wraps a reference in a copyable, assignable object. It is frequently used as a mechanism to store references inside standard containers (like std::vector) which cannot normally hold references. ) (needs header "functional")

What the app should do:
- user can choose car, year, model, name, engine, gearbox, cabin details (from "database"/file?)
- User can choose no. of cars to park into their garage
- car is being created then
- computation of fuel consumption, sales price, VIN, ...


LEARNINGS:
- Im Programmablauf zuerst die Klasse, dann die member functions --> sonst Fehler
- fehlt der default constructor, kann das zu Fehlern führen
- es gibt KEIN prototyping für member functions außerhalb von Klassen, stattdessen werden diese innerhalb der Klasse prototypisch deklariert.
-inline static member sind ab c++17 verfügbar. Vorher mussten sie außerhalb extra definiert werden.
-switch/case vergleicht bzw. erkennt nicht von selbst strings. Es können aber enum-Werte mit <enum-typ>::<enum-name> ausgewertet werden.
- Enums können nicht einfach ausgegeben werden. es braucht ein spezielles Mapping, wie hier.

*/
//#include "car.h"
//#include "lexusIS.h"

#include <iostream>
#include <map> // mapping algo
#include <string>
#include <sstream>
#include <list>
#include <vector>
#include <algorithm> //this one includes e.g. for_each, filter, sort, etc.
#include <cstdlib>
#include <memory> //shared pointers
#include <functional> //std::reference_wrapper

using namespace std;

enum model {LEXUS_IS = 1, CORVETTE = 2, FERRARI = 3, MINI_COOPER = 4};
enum category {SUBCOMPACT = 1, COMPACT_EXECUTIVE = 2, SPORTS_CAR = 3};

//This is the model the user has to choose:
model m_ChosenModel;


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

//template class, contains SPECIALIZED METHOD
//template<class T>


//PERFECT FORWARDING:
//Reads-in integer input and assures it is between two limits
//Output: Read-in integer from keyboard, checked if within min/max borders
// validity criterion: i>=i_Min && i<=i_Max
//Input: minimum and maximum allowable value
int i_IntSelnLimd(int i_Min, int i_Max){
    
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

//PERFECT FORWARDING:
//passing lvalues and also rvalues works due to perfect forwarding:
template<typename T>
int anyType_IntSelnLimd(T&& arg1, T&& arg2){
    
	int i_Res;
    i_Res=i_IntSelnLimd(std::forward<T>(arg1), std::forward<T>(arg2));
    return i_Res;
}

//PERFECT FORWARDING:
template<class T>
T&& forward(typename remove_reference<T>::type& arg){
	return static_cast<T&&>(arg);
}

//Function for selecting car model:
void ChooseCarMdl(){
    
    //min and max borders for valid choice:
    int i_Min=1, i_Max=4, i_choice=0;
    
    cout << "Car model? \nType-in the numeric value: \nLEXUS_IS (1)\nCORVETTE (2) \nFERRARI (3) \nMINI_COOPER (4)" << endl;

    //get keyboard integer input value within limits:
    i_choice=anyType_IntSelnLimd(i_Min, i_Max);
    
    //set the model member:
    switch (i_choice) {
        case 1: 
            m_ChosenModel=model::LEXUS_IS;
            cout << "Chosen car model: LEXUS_IS" << endl;
            break;
        case 2:
            m_ChosenModel=model::CORVETTE;
            cout << "Chosen car model: CORVETTE" << endl;
            break;
        case 3:
            m_ChosenModel=model::FERRARI;
            cout << "Chosen car model: FERRARI" << endl;
            break;
        case 4:
            m_ChosenModel=model::MINI_COOPER;
            cout << "Chosen car model: MINI_COOPER" << endl;
            break;
        }

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



//Complete car pool
//sets number of garages
class carPool{
    public:
        carPool(){
            
            set_carPool();

        }
        int get_gargCount();
    private:
        inline static int i_TotValCarPool_Dollars; // Total value of car pool in dollars
        inline static int i_GargCount; //Number of garages worldwide
        void set_carPool();
        void set_gargCount();
};

void carPool::set_carPool(){
    
    //Setting the number of garages:
    //Accessing FRIEND's member function using nullpointer of type garages:
    //gargPtr->set_garages();
    //int i=1;
   //gargPtr->createGarage(i);
    
    //Creating all garages:
    //Accessing FRIEND's member function using nullpointer of type garages:
    set_gargCount();
    
    //carPool* gargPtr=nullptr;
    //for (int i=0; i<i_GargCount; i++) {gargPtr = new garages();}
    //for (int i=0; i<gargPtr->i_GargCount; i++) std::cout << "\ntest" <<std::endl;
    
}

//PERFECT FORWARDING:
//read-in garages count:
void carPool::set_gargCount(){
    
    cout << "\nHow many garages do you want? (1 to 3)" << endl;
    //perfect forwarding: can pass rvalue to function
    i_GargCount = anyType_IntSelnLimd(1, 3);
    
}

int carPool::get_gargCount(){
    
    return i_GargCount;
    
}

class garages{
    public: 
        garages(int i){
            createGarage(i);
        }
        
        //Function to choose no of garages:
        friend class carPool;
        //print a list of all garages:
        void printGargNames();
    private:

        std::string s_GargName; // Name of the current garage
        int i_CarCountGarg=0;   // Number of cars in current garage
        //inline static int i_GargCount;   // Number of garages totally worldwide
        //VECTORS:
        inline static vector<std::string> sv_GargNames; // Vector with names of the garage
        //void set_gargCount();
        void createGarage(int i);

        
};

/*
void garages::set_garages(){
    
    //Choose number of garages - PERFECT FORWARDING:
    //set_gargCount();
    
    //Creating all garages:
    for (int i=0; i<i_GargCount; i++) createGarage(i);
    
    //Finally, print a list of all garages:
    
    
}*/


/*
//PERFECT FORWARDING:
//VECTORS:
//PASS-BY-REFERENCE-TO-CONST
//Creates a new garage name, inserts into garages vector, counts up garage count
void garages::createGarage(int i){
    
    //Read-in new garage name:
    cout << "Enter the name of new garage no." << i+1 << " (up to 16 characters):" <<endl;
    std::getline(std::cin, s_GargName);
    //Insert new garage into vector containing all garage names:
    sv_GargNames.push_back(s_GargName);
    
    cout << "How many cars do you want for this garage? (1 to 5)" <<endl;
    int i_Min=1, i_Max=5;
    //perfect forwarding: can also pass lvalue to function:
    i_CarCountGarg = anyType_IntSelnLimd(i_Min, i_Max);
    
    std::vector<std::reference_wrapper<car>> sv_cars(i_CarCountGarg);
    
    //for(auto i_car: sv_cars){}
        
    
        
    //Model selection process:
    ChooseCarMdl();
    car *carptr = nullptr;
    
    //Object creation depending on selected model:
    switch (m_ChosenModel){
        
        case(model::LEXUS_IS):
            carptr = new lexusIS();
            break;
            
        case(model::CORVETTE):
            carptr= new corvette();
            break;
            
        case(model::FERRARI):
            carptr= new ferrari();
            break;
            
        case(model::MINI_COOPER):
            carptr= new mini_cooper();
            break;
    }
    
    
}*/

/*
//VECTORS
//RANGE BASED FOR:
//print a list of all garages:
void garages::printGargNames(){
    
    std::cout << "\nComplete garages list:" << std::endl;
    //RANGE BASED FOR:
    for(auto s: sv_GargNames){
        std::cout << s << std::endl;
        
    }
}
*/

class car{
    public:
        //no default constructor here since we ALWAYS need to create a car and set the model and category
        car(){set_CarModel();}
        //default constructor, which is actually not needed:
        //car(){}
        
        //VIRTUAL function calculating fuel consumption:
        virtual float f_CalcFuelCons();
        
        //function setting the model by user-choice
        void set_CarModel();
        
        //function setting the category corresponding to the model choice
        virtual void set_CarCategory();
        
        category e_carCategory; // {SUBCOMPACT = 1, COMPACT_EXECUTIVE = 2, SPORTS_CAR = 3};
        model e_carmodel; //{LEXUS_IS = 1, CORVETTE = 2, FERRARI = 3, MINI_COOPER = 4};
    //private:
        //assign corresponding category of car:

        
        //double calcFuelConsumption(){}; //usual method -- takes care of ANY OTHER datatype than <int>
        
        //const int i_yearBuilt;
        //int i_salesPrice;
        //const int i_manufPrice;
        //const int i_vecIdentNo; // Vehicle Identification Number

        
        
};


void car::set_CarCategory(){
    
    //Object creation depending on selected model:
    switch (e_carmodel){
        
        case(model::LEXUS_IS):
            // Lexus IS
            e_carCategory=COMPACT_EXECUTIVE;
            break;
        case(model::CORVETTE):
            //Corvette
            e_carCategory=SPORTS_CAR;
            break;
        case(model::FERRARI):
            //Ferrari
            e_carCategory=SPORTS_CAR;
            break;
        case(model::MINI_COOPER):
            //Mini Cooper
            e_carCategory=SUBCOMPACT;
            break;
    }
    
}

//Function for setting the chosen car model to the created car model:
void car::set_CarModel(){

    //set the model member:
    e_carmodel=m_ChosenModel;
    //set category:
    set_CarCategory();
    
    
    
}

float car::f_CalcFuelCons(){            
    //use integers only in order to keep calculation accuracy high:
    int i_EngFuelCons=10; // Engine only fuel consumption, in 1E-1 L/100km
    int i_ChassisMass=1000; // Chassis only mass (w/o engine and gearbox) in kg
    int i_Gbx_Mass=100; // Gearbox only mass in kg
    int i_ChassisCW=35; // Air resistance coefficient, unit 1E-2
    float f_CarFuelCons =0.0;  // CAR Low speed fuel consumption, in L/100km

    f_CarFuelCons=((i_ChassisMass+i_Gbx_Mass)*i_EngFuelCons*i_ChassisCW)/100000.0;

    return f_CarFuelCons;
}


class lexusIS:public car{
    public:
        lexusIS(){set_lexusIS();}
        void set_lexusIS();

        float f_CalcFuelCons(int i_EngFuelCons, int i_ChasMass, int i_GbxMass, int i_ChasCW);
    private:
        //int i_EngFuelCons;
        
        std::string get_lexusIS_engine();
        void put_lexusIS_engine(int i_EngType);
        
        std::string get_lexusIS_chassis();
        void put_lexusIS_chassis(int i_ChasType);
        
        std::string get_lexusIS_gbx();
        void put_lexusIS_gbx(int i_GbxType);
        
        
        int i_EngFuelCons;
        int i_ChasMass;
        int i_GbxMass;
        int i_ChasCW;
        
        std::string s_EngType;
        std::string s_ChasType;
        std::string s_GbxType;
        
        inline static const std::string s_EngType_Gas3cyl="Gasoline inline 3 cylinder"; //This is INDEX 1
        inline static const std::string s_EngType_GasV8cyl="Gasoline V8"; //This is INDEX 2
        inline static const std::string s_ChasType_BigChas="Big Chassis"; //This is INDEX 1
        inline static const std::string s_ChasType_SmallChas="Smaller Chassis"; //This is INDEX 2
        inline static const std::string s_GbxType_HeavyGbx="8-gear automatic transmission"; //This is INDEX 1
        inline static const std::string s_GbxType_LightGbx="6-gear manual transmission"; //This is INDEX 2
        
        inline static const int i_EngFuelCons_Gas3cyl = 10; // Engine only fuel consumption, in 1E-1 L/100km
        inline static const int i_EngFuelCons_GasV8cyl = 20; // Engine only fuel consumption, in 1E-1 L/100km
        inline static const int i_ChasMass_BigChas=1000; // Chassis only mass (w/o engine and gearbox) in kg
        inline static const int i_ChasMass_SmallChas=800; // Chassis only mass (w/o engine and gearbox) in kg
        inline static const int i_ChasCW_BigChas=50; // Air resistance coefficient, unit 1E-2
        inline static const int i_ChasCW_SmallChas=35; // Air resistance coefficient, unit 1E-2
        inline static const int i_GbxMass_HeavyGbx=150; // Gearbox only mass in kg
        inline static const int i_GbxMass_LightGbx=100; // Gearbox only mass in kg
        
};




void lexusIS::set_lexusIS(){
 
    cout << "Select your LEXUS IS preferences." << endl;
    
    cout << "Select engine: \nGasoline inline 3 cylinder (1)\nGasoline V8 (2)" << endl;

    //min and max borders for valid choice:
    int i_Min=0, i_Max=2, i_choice=0;
    //get keyboard integer input value within limits:
    i_choice=anyType_IntSelnLimd(i_Min, i_Max);
    
    //set the ENGINE members:
    put_lexusIS_engine(i_choice);
    cout << "Chosen engine: " << get_lexusIS_engine() << endl;
    
    
    
    cout << "Select chassis: \nBig chassis (1)\nSmaller chassis (2)" << endl;

    //min and max borders for valid choice:
    i_choice=0;
    //get keyboard integer input value within limits:
    i_choice=anyType_IntSelnLimd(i_Min, i_Max);
    
    //set the CHASSIS members:
    put_lexusIS_chassis(i_choice);
    cout << "Chosen chassis: " << get_lexusIS_chassis() << endl;
    
    
    
    cout << "Select gearbox: \n8-gear automatic transmission (1)\n6-gear manual transmission (2)" << endl;

    //min and max borders for valid choice:
    i_choice=0;
    //get keyboard integer input value within limits:
    i_choice=anyType_IntSelnLimd(i_Min, i_Max);
    
    //set the CHASSIS members:
    put_lexusIS_gbx(i_choice);
    cout << "Chosen gearbox: " << get_lexusIS_gbx() << endl;
    
}

void lexusIS::put_lexusIS_gbx(int i_GbxType){
    
    //set the GEARBOX type:
    switch (i_GbxType) {
        case 1:
            s_GbxType=s_GbxType_HeavyGbx;
            break;
        case 2:
            s_GbxType=s_GbxType_LightGbx;
        }
}

std::string lexusIS::get_lexusIS_gbx(){
    //cout << s_GbxType << endl;
    
    return s_GbxType;
}

void lexusIS::put_lexusIS_chassis(int i_ChasType){
    
    //set the CHASSIS type:
    switch (i_ChasType) {
        case 1:
            s_ChasType=s_ChasType_BigChas;
            break;
        case 2:
            s_ChasType=s_ChasType_SmallChas;
        }
}

std::string lexusIS::get_lexusIS_chassis(){
    //cout << s_ChasType << endl;
    
    return s_ChasType;
}

void lexusIS::put_lexusIS_engine(int i_EngType){
    
    //set the ENGINE type:
    switch (i_EngType) {
        case 1:
            s_EngType=s_EngType_Gas3cyl;
            break;
        case 2:
            s_EngType=s_EngType_GasV8cyl;
        }
}

std::string lexusIS::get_lexusIS_engine(){
    //cout << s_EngType << endl;
    
    return s_EngType;
}

float lexusIS::f_CalcFuelCons(int i_EngFuelCons, int i_ChassisMass, int i_Gbx_Mass, int i_ChassisCW){
    
    float f_CarFuelCons =0.0;  // CAR Low speed fuel consumption, in L/100km
    //use integers only in order to keep calculation accuracy high
    f_CarFuelCons=((i_ChassisMass+i_Gbx_Mass)*i_EngFuelCons*i_ChassisCW)/100000.0;
    
    return f_CarFuelCons;
}




class corvette:public car{
    public:
        corvette(){set_corvette();}
        void set_corvette();

        float f_CalcFuelCons(int i_EngFuelCons, int i_ChasMass, int i_GbxMass, int i_ChasCW);
    private:
        //int i_EngFuelCons;
        
        std::string get_corvette_engine();
        void put_corvette_engine(int i_EngType);
        
        std::string get_corvette_chassis();
        void put_corvette_chassis(int i_ChasType);
        
        std::string get_corvette_gbx();
        void put_corvette_gbx(int i_GbxType);
        
        
        int i_EngFuelCons;
        int i_ChasMass;
        int i_GbxMass;
        int i_ChasCW;
        
        std::string s_EngType;
        std::string s_ChasType;
        std::string s_GbxType;
        
        inline static const std::string s_EngType_Gas3cyl="Gasoline inline 3 cylinder"; //This is INDEX 1
        inline static const std::string s_EngType_GasV8cyl="Gasoline V8"; //This is INDEX 2
        inline static const std::string s_ChasType_BigChas="Big Chassis"; //This is INDEX 1
        inline static const std::string s_ChasType_SmallChas="Smaller Chassis"; //This is INDEX 2
        inline static const std::string s_GbxType_HeavyGbx="8-gear automatic transmission"; //This is INDEX 1
        inline static const std::string s_GbxType_LightGbx="6-gear manual transmission"; //This is INDEX 2
        
        inline static const int i_EngFuelCons_Gas3cyl = 10; // Engine only fuel consumption, in 1E-1 L/100km
        inline static const int i_EngFuelCons_GasV8cyl = 20; // Engine only fuel consumption, in 1E-1 L/100km
        inline static const int i_ChasMass_BigChas=1000; // Chassis only mass (w/o engine and gearbox) in kg
        inline static const int i_ChasMass_SmallChas=800; // Chassis only mass (w/o engine and gearbox) in kg
        inline static const int i_ChasCW_BigChas=50; // Air resistance coefficient, unit 1E-2
        inline static const int i_ChasCW_SmallChas=35; // Air resistance coefficient, unit 1E-2
        inline static const int i_GbxMass_HeavyGbx=150; // Gearbox only mass in kg
        inline static const int i_GbxMass_LightGbx=100; // Gearbox only mass in kg
        
};




void corvette::set_corvette(){
 
    cout << "Select your CORVETTE preferences." << endl;
    
    cout << "Select engine: \n???????? (1)\n????????? (2)" << endl;

    //min and max borders for valid choice:
    int i_Min=0, i_Max=2, i_choice=0;
    //get keyboard integer input value within limits:
    i_choice=anyType_IntSelnLimd(i_Min, i_Max);
    
    //set the ENGINE members:
    put_corvette_engine(i_choice);
    cout << "Chosen engine: " << get_corvette_engine() << endl;
    
    
    
    cout << "Select chassis: \nBig chassis (1)\nSmaller chassis (2)" << endl;

    //min and max borders for valid choice:
    i_choice=0;
    //get keyboard integer input value within limits:
    i_choice=anyType_IntSelnLimd(i_Min, i_Max);
    
    //set the CHASSIS members:
    put_corvette_chassis(i_choice);
    cout << "Chosen chassis: " << get_corvette_chassis() << endl;
    
    
    
    cout << "Select gearbox: \n8-gear automatic transmission (1)\n6-gear manual transmission (2)" << endl;

    //min and max borders for valid choice:
    i_choice=0;
    //get keyboard integer input value within limits:
    i_choice=anyType_IntSelnLimd(i_Min, i_Max);
    
    //set the CHASSIS members:
    put_corvette_gbx(i_choice);
    cout << "Chosen gearbox: " << get_corvette_gbx() << endl;
    
}

void corvette::put_corvette_gbx(int i_GbxType){
    
    //set the GEARBOX type:
    switch (i_GbxType) {
        case 1:
            s_GbxType=s_GbxType_HeavyGbx;
            break;
        case 2:
            s_GbxType=s_GbxType_LightGbx;
        }
}

std::string corvette::get_corvette_gbx(){
    //cout << s_GbxType << endl;
    
    return s_GbxType;
}

void corvette::put_corvette_chassis(int i_ChasType){
    
    //set the CHASSIS type:
    switch (i_ChasType) {
        case 1:
            s_ChasType=s_ChasType_BigChas;
            break;
        case 2:
            s_ChasType=s_ChasType_SmallChas;
        }
}

std::string corvette::get_corvette_chassis(){
    //cout << s_ChasType << endl;
    
    return s_ChasType;
}

void corvette::put_corvette_engine(int i_EngType){
    
    //set the ENGINE type:
    switch (i_EngType) {
        case 1:
            s_EngType=s_EngType_Gas3cyl;
            break;
        case 2:
            s_EngType=s_EngType_GasV8cyl;
        }
}

std::string corvette::get_corvette_engine(){
    //cout << s_EngType << endl;
    
    return s_EngType;
}

float corvette::f_CalcFuelCons(int i_EngFuelCons, int i_ChassisMass, int i_Gbx_Mass, int i_ChassisCW){
    float f_CarFuelCons =0.0;  // CAR Low speed fuel consumption, in L/100km
    //use integers only in order to keep calculation accuracy high
    f_CarFuelCons=((i_ChassisMass+i_Gbx_Mass)*i_EngFuelCons*i_ChassisCW)/100000.0;
    
    return f_CarFuelCons;
}





class ferrari:public car{
    public:
        ferrari(){set_ferrari();}
        void set_ferrari();

        float f_CalcFuelCons(int i_EngFuelCons, int i_ChasMass, int i_GbxMass, int i_ChasCW);
    private:
        //int i_EngFuelCons;
        
        std::string get_ferrari_engine();
        void put_ferrari_engine(int i_EngType);
        
        std::string get_ferrari_chassis();
        void put_ferrari_chassis(int i_ChasType);
        
        std::string get_ferrari_gbx();
        void put_ferrari_gbx(int i_GbxType);
        
        
        int i_EngFuelCons;
        int i_ChasMass;
        int i_GbxMass;
        int i_ChasCW;
        
        std::string s_EngType;
        std::string s_ChasType;
        std::string s_GbxType;
        
        inline static const std::string s_EngType_Gas3cyl="Gasoline inline 3 cylinder"; //This is INDEX 1
        inline static const std::string s_EngType_GasV8cyl="Gasoline V8"; //This is INDEX 2
        inline static const std::string s_ChasType_BigChas="Big Chassis"; //This is INDEX 1
        inline static const std::string s_ChasType_SmallChas="Smaller Chassis"; //This is INDEX 2
        inline static const std::string s_GbxType_HeavyGbx="8-gear automatic transmission"; //This is INDEX 1
        inline static const std::string s_GbxType_LightGbx="6-gear manual transmission"; //This is INDEX 2
        
        inline static const int i_EngFuelCons_Gas3cyl = 10; // Engine only fuel consumption, in 1E-1 L/100km
        inline static const int i_EngFuelCons_GasV8cyl = 20; // Engine only fuel consumption, in 1E-1 L/100km
        inline static const int i_ChasMass_BigChas=1000; // Chassis only mass (w/o engine and gearbox) in kg
        inline static const int i_ChasMass_SmallChas=800; // Chassis only mass (w/o engine and gearbox) in kg
        inline static const int i_ChasCW_BigChas=50; // Air resistance coefficient, unit 1E-2
        inline static const int i_ChasCW_SmallChas=35; // Air resistance coefficient, unit 1E-2
        inline static const int i_GbxMass_HeavyGbx=150; // Gearbox only mass in kg
        inline static const int i_GbxMass_LightGbx=100; // Gearbox only mass in kg*/
        
};




void ferrari::set_ferrari(){
 
    cout << "Select your FERRARI preferences." << endl;
    
    cout << "Select engine: \n???????? (1)\n????????? (2)" << endl;

    //min and max borders for valid choice:
    int i_Min=0, i_Max=2, i_choice=0;
    //get keyboard integer input value within limits:
    i_choice=anyType_IntSelnLimd(i_Min, i_Max);
    
    //set the ENGINE members:
    put_ferrari_engine(i_choice);
    cout << "Chosen engine: " << get_ferrari_engine() << endl;
    
    
    
    cout << "Select chassis: \nBig chassis (1)\nSmaller chassis (2)" << endl;

    //min and max borders for valid choice:
    i_choice=0;
    //get keyboard integer input value within limits:
    i_choice=anyType_IntSelnLimd(i_Min, i_Max);
    
    //set the CHASSIS members:
    put_ferrari_chassis(i_choice);
    cout << "Chosen chassis: " << get_ferrari_chassis() << endl;
    
    
    
    cout << "Select gearbox: \n8-gear automatic transmission (1)\n6-gear manual transmission (2)" << endl;

    //min and max borders for valid choice:
    i_choice=0;
    //get keyboard integer input value within limits:
    i_choice=anyType_IntSelnLimd(i_Min, i_Max);
    
    //set the CHASSIS members:
    put_ferrari_gbx(i_choice);
    cout << "Chosen gearbox: " << get_ferrari_gbx() << endl;
    
}

void ferrari::put_ferrari_gbx(int i_GbxType){
    
    //set the GEARBOX type:
    switch (i_GbxType) {
        case 1:
            s_GbxType=s_GbxType_HeavyGbx;
            break;
        case 2:
            s_GbxType=s_GbxType_LightGbx;
        }
}

std::string ferrari::get_ferrari_gbx(){
    //cout << s_GbxType << endl;
    
    return s_GbxType;
}

void ferrari::put_ferrari_chassis(int i_ChasType){
    
    //set the CHASSIS type:
    switch (i_ChasType) {
        case 1:
            s_ChasType=s_ChasType_BigChas;
            break;
        case 2:
            s_ChasType=s_ChasType_SmallChas;
        }
}

std::string ferrari::get_ferrari_chassis(){
    //cout << s_ChasType << endl;
    
    return s_ChasType;
}

void ferrari::put_ferrari_engine(int i_EngType){
    
    //set the ENGINE type:
    switch (i_EngType) {
        case 1:
            s_EngType=s_EngType_Gas3cyl;
            break;
        case 2:
            s_EngType=s_EngType_GasV8cyl;
        }
}

std::string ferrari::get_ferrari_engine(){
    //cout << s_EngType << endl;
    
    return s_EngType;
}

float ferrari::f_CalcFuelCons(int i_EngFuelCons, int i_ChassisMass, int i_Gbx_Mass, int i_ChassisCW){
    float f_CarFuelCons =0.0;  // CAR Low speed fuel consumption, in L/100km
    //use integers only in order to keep calculation accuracy high
    f_CarFuelCons=((i_ChassisMass+i_Gbx_Mass)*i_EngFuelCons*i_ChassisCW)/100000.0;
    
    return f_CarFuelCons;
}





class mini_cooper:public car{
    public:
        mini_cooper(){set_mini_cooper();}
        void set_mini_cooper();

        float f_CalcFuelCons(int i_EngFuelCons, int i_ChasMass, int i_GbxMass, int i_ChasCW);
    private:
        //int i_EngFuelCons;
        
        std::string get_mini_cooper_engine();
        void put_mini_cooper_engine(int i_EngType);
        
        std::string get_mini_cooper_chassis();
        void put_mini_cooper_chassis(int i_ChasType);
        
        std::string get_mini_cooper_gbx();
        void put_mini_cooper_gbx(int i_GbxType);
        
        
        int i_EngFuelCons;
        int i_ChasMass;
        int i_GbxMass;
        int i_ChasCW;
        
        std::string s_EngType;
        std::string s_ChasType;
        std::string s_GbxType;
        
        inline static const std::string s_EngType_Gas3cyl="Gasoline inline 3 cylinder"; //This is INDEX 1
        inline static const std::string s_EngType_GasV8cyl="Gasoline V8"; //This is INDEX 2
        inline static const std::string s_ChasType_BigChas="Big Chassis"; //This is INDEX 1
        inline static const std::string s_ChasType_SmallChas="Smaller Chassis"; //This is INDEX 2
        inline static const std::string s_GbxType_HeavyGbx="8-gear automatic transmission"; //This is INDEX 1
        inline static const std::string s_GbxType_LightGbx="6-gear manual transmission"; //This is INDEX 2
        
        inline static const int i_EngFuelCons_Gas3cyl = 10; // Engine only fuel consumption, in 1E-1 L/100km
        inline static const int i_EngFuelCons_GasV8cyl = 20; // Engine only fuel consumption, in 1E-1 L/100km
        inline static const int i_ChasMass_BigChas=1000; // Chassis only mass (w/o engine and gearbox) in kg
        inline static const int i_ChasMass_SmallChas=800; // Chassis only mass (w/o engine and gearbox) in kg
        inline static const int i_ChasCW_BigChas=50; // Air resistance coefficient, unit 1E-2
        inline static const int i_ChasCW_SmallChas=35; // Air resistance coefficient, unit 1E-2
        inline static const int i_GbxMass_HeavyGbx=150; // Gearbox only mass in kg
        inline static const int i_GbxMass_LightGbx=100; // Gearbox only mass in kg*/
        
};




void mini_cooper::set_mini_cooper(){
 
    cout << "Select your MINI COOPER preferences." << endl;
    
    cout << "Select engine: \n???????? (1)\n????????? (2)" << endl;

    //min and max borders for valid choice:
    int i_Min=0, i_Max=2, i_choice=0;
    //get keyboard integer input value within limits:
    //i_choice=anyType_IntSelnLimd(i_Min, i_Max);anyType_IntSelnLimd
    i_choice=anyType_IntSelnLimd(i_Min, i_Max);
    
    //set the ENGINE members:
    put_mini_cooper_engine(i_choice);
    cout << "Chosen engine: " << get_mini_cooper_engine() << endl;
    
    
    
    cout << "Select chassis: \nBig chassis (1)\nSmaller chassis (2)" << endl;

    //min and max borders for valid choice:
    i_choice=0;
    //get keyboard integer input value within limits:
    //i_choice=anyType_IntSelnLimd(i_Min, i_Max);
    i_choice=anyType_IntSelnLimd(i_Min, i_Max);
    
    //set the CHASSIS members:
    put_mini_cooper_chassis(i_choice);
    cout << "Chosen chassis: " << get_mini_cooper_chassis() << endl;
    
    
    
    cout << "Select gearbox: \n8-gear automatic transmission (1)\n6-gear manual transmission (2)" << endl;

    //min and max borders for valid choice:
    i_choice=0;
    //get keyboard integer input value within limits:
    //i_choice=anyType_IntSelnLimd(i_Min, i_Max);
    i_choice=anyType_IntSelnLimd(i_Min, i_Max);
    
    //set the CHASSIS members:
    put_mini_cooper_gbx(i_choice);
    cout << "Chosen gearbox: " << get_mini_cooper_gbx() << endl;
    
}

void mini_cooper::put_mini_cooper_gbx(int i_GbxType){
    
    //set the GEARBOX type:
    switch (i_GbxType) {
        case 1:
            s_GbxType=s_GbxType_HeavyGbx;
            break;
        case 2:
            s_GbxType=s_GbxType_LightGbx;
        }
}

std::string mini_cooper::get_mini_cooper_gbx(){
    //cout << s_GbxType << endl;
    
    return s_GbxType;
}

void mini_cooper::put_mini_cooper_chassis(int i_ChasType){
    
    //set the CHASSIS type:
    switch (i_ChasType) {
        case 1:
            s_ChasType=s_ChasType_BigChas;
            break;
        case 2:
            s_ChasType=s_ChasType_SmallChas;
        }
}

std::string mini_cooper::get_mini_cooper_chassis(){
    //cout << s_ChasType << endl;
    
    return s_ChasType;
}

void mini_cooper::put_mini_cooper_engine(int i_EngType){
    
    //set the ENGINE type:
    switch (i_EngType) {
        case 1:
            s_EngType=s_EngType_Gas3cyl;
            break;
        case 2:
            s_EngType=s_EngType_GasV8cyl;
        }
}

std::string mini_cooper::get_mini_cooper_engine(){
    //cout << s_EngType << endl;
    
    return s_EngType;
}

float mini_cooper::f_CalcFuelCons(int i_EngFuelCons, int i_ChassisMass, int i_Gbx_Mass, int i_ChassisCW){
    float f_CarFuelCons =0.0;  // CAR Low speed fuel consumption, in L/100km
    //use integers only in order to keep calculation accuracy high
    f_CarFuelCons=((i_ChassisMass+i_Gbx_Mass)*i_EngFuelCons*i_ChassisCW)/100000.0;
    
    return f_CarFuelCons;
}

//PERFECT FORWARDING:
//VECTORS:
//PASS-BY-REFERENCE-TO-CONST
//Creates a new garage name, inserts into garages vector, counts up garage count
void garages::createGarage(int i){
    
    //Read-in new garage name:
    cout << "Enter the name of new garage no." << i+1 << " (up to 16 characters):" <<endl;
    std::getline(std::cin, s_GargName);
    //Insert new garage into vector containing all garage names:
    sv_GargNames.push_back(s_GargName);
    
    cout << "How many cars do you want for this garage? (1 to 5)" <<endl;
    int i_Min=1, i_Max=5;
    //perfect forwarding: can also pass lvalue to function:
    i_CarCountGarg = anyType_IntSelnLimd(i_Min, i_Max);
    
    std::vector<int> sv_cars(i_CarCountGarg);
    
    //for(auto i_car: sv_cars){}
        
    
        /*
    //Model selection process:
    ChooseCarMdl();
    car *carptr = nullptr;
    
    //Object creation depending on selected model:
    switch (m_ChosenModel){
        
        case(model::LEXUS_IS):
            carptr = new lexusIS();
            break;
            
        case(model::CORVETTE):
            carptr= new corvette();
            break;
            
        case(model::FERRARI):
            carptr= new ferrari();
            break;
            
        case(model::MINI_COOPER):
            carptr= new mini_cooper();
            break;
    }
    */
    
}

//VECTORS
//RANGE BASED FOR:
//print a list of all garages:
void garages::printGargNames(){
    
    std::cout << "\nComplete garages list:" << std::endl;
    //RANGE BASED FOR:
    for(auto s: sv_GargNames){
        std::cout << s << std::endl;
        
    }
}

//SHARED POINTERS:
int main(){
    
    cout << "*************** THIS IS MY CAR POOL APP ***************" << endl;
    
    //car pool building process:
    
    //provide an empty pointer to the FIRST garage:
    //garages* gargPtr=nullptr;
    //garages* gargPtr=new garages();
    
    //create and fill car pool pointer:
    carPool* carPoolPtr = new carPool();
    shared_ptr<garages> gargPtr;
    
    int i=0;
    do{
        gargPtr = make_shared<garages>(i);
        i++;
    }
    while (i<carPoolPtr->get_gargCount());
    
    gargPtr->printGargNames();
    
    /*
    //Model selection process:
    ChooseCarMdl();
    car *carptr = nullptr;
    
    //Object creation depending on selected model:
    switch (m_ChosenModel){
        
        case(model::LEXUS_IS):
            carptr = new lexusIS();
            break;
            
        case(model::CORVETTE):
            carptr= new corvette();
            break;
            
        case(model::FERRARI):
            carptr= new ferrari();
            break;
            
        case(model::MINI_COOPER):
            carptr= new mini_cooper();
            break;
    }
    */
    
    //cout << "\nCurrent car model: " << c1ptr->e_carmodel << endl;
    //cout << "Current car category: " << c1ptr->e_carCategory << endl;
    //cout << "Current car fuel consumption: " << c1ptr->f_CalcFuelCons() << endl;
    //FuelConsMPGandLP100km();
    
}