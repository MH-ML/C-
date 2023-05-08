#ifndef BIRTHDAY_H
#define BIRTHDAY_H
using namespace std;

class birthday{
    public:
        birthday(int d, int m, int y);
        void printDate();
    private:
        int day, month, year;
};


#endif