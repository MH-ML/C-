#ifndef PEOPLE_H
#define PEOPLE_H
#include <string>
#include "birthday.h"
using namespace std;

class people{
    public:
        people(string x, birthday b);
    private:
        string name;
        birthday dateOfBirth;
};


#endif