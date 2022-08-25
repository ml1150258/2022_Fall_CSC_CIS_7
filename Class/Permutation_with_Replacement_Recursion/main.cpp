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
unsigned int nPrmRec(unsigned int,unsigned int);//Recursive n^m
unsigned int nPrmFor(unsigned int,unsigned int);//Recursive n^m

//Execution Starts Here
int main(int argc, char** argv){
    //Set Random Number Seed Here
    
    //Declare Variables - Known and Unknown, units, range, description
    unsigned int n,m;
    
    //Initialize Variables
    n=10;
    m=4;
    
    //Map inputs to outputs -> i.e. process the inputs
    cout<<"Recursive n Perm m = "<<nPrmRec(n,m)<<endl;
    cout<<"For-Loop  n Perm m = "<<nPrmFor(n,m)<<endl;
    cout<<"Math Lib  n Perm m = "<<pow(n,m)<<endl;
    
    //Display the outputs
    
    //Clean up - File closing, memory de-allocation, etc....

    //Exit Stage Right!
    return 0;
}

//Function Implementations
unsigned int nPrmFor(unsigned int n,unsigned int m){
    unsigned int ntom=1;
    for(unsigned int i=1;i<=m;i++){
        ntom*=n;
    }
    return ntom;
}

unsigned int nPrmRec(unsigned int n,unsigned int m){
    //Base Case
    if(m<=0)return 1;
    //Recursion
    return nPrmRec(n,m-1)*n;
}