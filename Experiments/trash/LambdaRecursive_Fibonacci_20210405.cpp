#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <list>
#include <vector>
#include <algorithm> //this one includes e.g. for_each, filter, sort, etc.
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <sstream>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <cctype>
#include <functional>

using namespace std;

int main(){
    
    std::function<int(int)> Fib = [&Fib](int x){return( x<2 ? x : (Fib(x-1) + Fib(x-2)));};
    std::vector<int> i_ListOfFibs;
    
    for(int i=0; i<10; i++)
        i_ListOfFibs.push_back(Fib(i));
        
    for(auto val: i_ListOfFibs)
        std::cout << val << "\n";
    
    return 0;
    
}
