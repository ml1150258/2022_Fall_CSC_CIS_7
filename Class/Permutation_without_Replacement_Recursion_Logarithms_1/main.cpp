/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on April 25th, 2022, 11:25 AM
 * Purpose:  Permutation with Replacement
 */

//System Level Libraries
#include <iostream>   //I/O Library
#include <cmath>      //Math Library
using namespace std;  //Library Scope

//User Libraries

//Global Constants
//Science and Math, Conversions, Higher Dimensions const to follow

//Function Prototypes
float nPrm(unsigned int,unsigned int);//Recursive n^m
int display(float,float &);

//Execution Starts Here
int main(int argc, char** argv){
    //Set Random Number Seed Here
    
    //Declare Variables - Known and Unknown, units, range, description
    unsigned int n,m;
    
    //Initialize Variables
    n=10;
    m=4;
    
    //Map inputs to outputs -> i.e. process the inputs
    cout<<"e^Recursive n Perm m = e^"<<nPrm(n,m)<<endl;
    float fraction;
    int powr10=display(nPrm(n,m),fraction);
    cout<<"Recursive   n Perm m =  f("<<n<<","<<m<<")="
            <<pow(10,fraction)<<"x10^"<<powr10<<endl;
    
    //Display the outputs
    
    //Clean up - File closing, memory de-allocation, etc....

    //Exit Stage Right!
    return 0;
}

//Function Implementations
int display(float logRep,float &mantissa){
    //Convert to Base 10
    float base10=logRep/log(10.0f);
    //Divide the integer and fraction -> characteristic and mantissa
    int iBs10=base10;
    mantissa=base10-iBs10;
    return iBs10;
}

float nPrm(unsigned int n,unsigned int m){
    float ntom=0;
    for(unsigned int i=n-m+1;i<=n;i++){
        ntom+=log(i);
    }
    return ntom;
}