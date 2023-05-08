#include <iostream>
#include <string>
#include "birthday.h"
#include "people.h"
using namespace std;

//IMPORTANT!!! Everytime we refer to a class inside another class we need to use the member initializer list:
people::people(string x, birthday b):
name(x), dateOfBirth(b)
{
    
}

void people::printInfo(){
    cout << name << " was born on ";
    dateOfBirth.printDate();
}