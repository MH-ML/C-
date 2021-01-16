/******************************************************************************

This function shall create a vector sized as desired by the user.
Then, the vector shall be initialized via a for-loop constructor including iterator.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <vector>

int main()
{
    int i_NumDat=0, i_DatPt=0;
    
    std::cout << "VECTOR CREATION w. INITIALIZATION \n\nHow many data points do you want to create? ";
    //read-in point-count:
    std::cin >> i_NumDat;
    //create vector:
    std::vector<int> data(i_NumDat);
    
    int i_cnt=0;
    //read-in values from user input:
    for(std::vector<int>::iterator it=data.begin(); it!=data.end(); ++it){
        std::cout << "Please enter data point " << i_cnt << " data: ";
        std::cin >> *it; // iterator = pointer with more functions
        i_cnt++;
    }
    
    //print out the whole vector:
    std::cout << "\nYour vector is:\n";
    for(std::vector<int>::iterator  it=data.begin(); it!=data.end(); ++it){
        std::cout << *it << " "; 
    }
    
    return 0;
}
