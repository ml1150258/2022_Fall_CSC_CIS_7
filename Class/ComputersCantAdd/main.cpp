/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on February 24, 2021, 11:51 AM
 * Purpose:  C++ Template
 */

//System Level Libraries
#include <iostream>   //I/O Library
#include <cmath>      //Math Library
using namespace std;  //Library Scope

//User Libraries

//Global Constants
//Science and Math, Conversions, Higher Dimensions
//const to follow

//Function Prototypes

//Execution Starts Here
int main(int argc, char** argv){
    //Set Random Number Seed Here
    
    //Declare Variables - Known and Unknown, units, range, description
    float sum,frac,appXact,error;
    int nLoops;
    
    //Initialize Variables
    sum=0;
    frac=0.1f;
    nLoops=10000000;
    
    //Map inputs to outputs -> i.e. process the inputs
    for(int i=1;i<=nLoops;i++){
        sum+=frac;
    }
    appXact=nLoops*frac;
    error=(appXact-sum)/appXact*100;
    
    //Display the outputs
    cout<<"The exact sum       = "<<appXact<<endl;
    cout<<"The approximate sum = "<<sum<<endl;
    cout<<"The error           = "<<error<<"%"<<endl;
    
    
    //Clean up - File closing, memory deallocation, etc....

    //Exit Stage Right!
    return 0;
}

//Function Implementations