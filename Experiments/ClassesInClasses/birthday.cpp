#include <iostream>
#include <string>
#include "birthday.h" 
using namespace std;

birthday::birthday(int d, int m, int y): 
day(d), month(m), year(y){
}

void birthday::printDate(){
    cout << "Month: " << month << ", day: " << day << ", year: " << year << endl;
}