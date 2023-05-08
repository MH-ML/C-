#include <iostream>
using namespace std;


int main(){
    
    int num=0;
    std::cout << "Hi there! This averages your students' GPA." << endl;
    
    while(num<=0|| num>=255){
        std::cout << "HPlease enter the number of students." << endl;
        std::cin >> num;
        if (num<=0|| num>=255){
            std::cout << "Only numbers from 1 to 255 allowed. Try again." << endl;
        }
    }
    
    float* ptr = new float[num];
    float f_GPA_avg=0.0;
    
    for(int i=0; i<num; i++){
        
        std::cout << "GPA student no." << (i+1) <<": ";
        std::cin >> *(ptr+i);
        f_GPA_avg+=*(ptr+i);
    }
    
    f_GPA_avg/=num;
    
    std::cout << "Average GPA is: " << f_GPA_avg << endl;
    
}
    