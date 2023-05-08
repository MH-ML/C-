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

using namespace std;

int main(){
    
    std::vector<int> vec1 = {1,2,3,4,5};
    std::vector<int> vec2 = {6,7,8,9,10};
    std::vector<int> vec3(5);
    
    transform(vec1.begin(), vec1.end(), vec2.begin(), vec3.begin(), [](int x, int y){ return x+y;});
            
    for(auto val: vec3)
        std::cout << "vec3 " << val << "\n";
    
    return 0;
    
}
