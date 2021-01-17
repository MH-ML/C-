/******************************************************************************

THIS PROGRAM READS A DATA FILE TO A VECTOR - COMPUTING THE DATA AVERAGE

*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>

int main(void)
{
    //connected a variable to a file for input:
    ifstream data_file("data.txt");
    
    //point to start and end of file via iterators:
    ifstream_iterator<int> start(data_file), end;
    
    //vector integer saves data, access variable via iterator for start and iterator for end:
    //this is a declaration AND auto-initialization of the vector:
    vector<int> data(start,end);
    
    int sum=0;
    //use the set iterators "start" and "end" and add another iterator "it" to loop over the sum:
    for(auto it=start; it!=end; ++it){
        sum+=*it;
    }
    
    //comute the average:
    float f_avg=0;
    f_avg=(1.0*sum)/data.size();
    
    //output:
    cout << "The data's average is: " << f_avg << ".";

    return 0;
}
