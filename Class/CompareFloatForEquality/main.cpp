/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on August 24, 2021, 6:51 AM
 * Purpose:  Proper way to compare a float
 */

//System Level Libraries
#include <iostream>   //I/O Library
#include <cmath>      //Math Library
#include <iomanip>    //Formatting Library
using namespace std;  //Library Scope

//User Libraries

//Global Constants
//Science and Math, Conversions, Higher Dimensions const to follow

//Function Prototypes

//Execution Starts Here
int main(int argc, char** argv){
    //Declare Variables - Known and Unknown, units, range, description
    float x,y,etol;
    bool equal;
    
    //Initialize Variables
    x=3.2e6f;
    y=3.2000003e6f;
    etol=pow(10,log10(x)-7);
    
    //Map inputs to outputs -> i.e. process the inputs
    equal=abs(x-y)<etol;
    
    //Display the outputs
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"x="<<x<<endl;
    cout<<"y="<<y<<endl;
    cout<<(equal?"x==y":"x!=y")<<endl;
    
    //Clean up - File closing, memory deallocation, etc....

    //Exit Stage Right!
    return 0;
}

//Function Implementations