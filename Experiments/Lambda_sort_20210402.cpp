
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <sstream>
#include <ctime>
#include <cmath>
#include <algorithm>
using namespace std;

std::vector<int> GenerateRandVec(int numOfNums,
        int min, int max);

std::vector<int> GenerateFibList(int maxNums);

void printVals(const vector<int> vecVals){

    for(auto val:vecVals)
        cout << val << "\n";
}

int main() {

    vector<int> vecVals= GenerateRandVec(10,1,50);

    printVals(vecVals);

    //sort:
    std::sort(vecVals.begin(), vecVals.end(),
         [](int x, int y) { return x<y;});

    printVals(vecVals);

    return 0;

}

std::vector<int> GenerateRandVec(int numOfNums,
        int min, int max){
    std::vector<int> vecValues;
    srand(time(NULL));
    int i = 0, randVal = 0;
    while(i < numOfNums){
        randVal = min + std::rand() % ((max + 1) - min);
        vecValues.push_back(randVal);
        i++;
    }
    return vecValues;
}
/*
// ----- PROBLEM GENERATE DYNAMIC VECTOR OF FIBS -----
std::vector<int> GenerateFibList(int maxNums){
    std::vector<int> listOfFibs;
    int i = 0;
    std::function<int(int)> Fib =
    [&Fib](int n) {return n < 2 ? n : Fib(n-1) + Fib(n-2);};
    while(i < maxNums){
        listOfFibs.push_back(Fib(i));
        i++;
    }
    return listOfFibs;
}
// ----- END PROBLEM GENERATE DYNAMIC VECTOR OF FIBS -----
*/
