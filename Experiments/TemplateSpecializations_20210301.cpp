//Template specializations
#include <iostream>
using namespace std;

template <class T>
class Example{
    public:
        Example(T x){
            cout << x << " is not a char."  << endl;
};

template <>
class Example<char>{
    public:
        Example(char x){
            cout << x << " is INDEED a char. " << endl;
        }
};

int main(){
    Example <int> a(1);
    Example <double> b(3.4);
    Example <char> c('x');
    return 0;
}