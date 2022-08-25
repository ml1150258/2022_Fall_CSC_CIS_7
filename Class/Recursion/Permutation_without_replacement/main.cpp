/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on April 20th, 2022, 10:15 AM
 * Purpose:  Recursive Product or Factorial
 */

//System Level Libraries
#include <iostream>   //I/O Library
#include <cmath>      //Math Library
using namespace std;  //Library Scope

//User Libraries

//Global Constants
//Science and Math, Conversions, Higher Dimensions const to follow

//Function Prototypes
unsigned int recFact(unsigned int);
unsigned int forFact(unsigned int);
unsigned int nPrmRec(unsigned int,unsigned int);

//Execution Starts Here
int main(int argc, char** argv){
    //Set Random Number Seed Here
    
    //Declare Variables - Known and Unknown, units, range, description
    unsigned int n,m;
    
    //Initialize Variables
    n=10;
    m=4;
    
    //Map inputs to outputs -> i.e. process the inputs
    
    //Display the outputs
    cout<<"Recursive Product/Factorial f("<<n<<")="<<recFact(n)<<endl;
    cout<<"For-Loop  Product/Factorial f("<<n<<")="<<forFact(n)<<endl;
    cout<<"Recursive n Permuted m      f("<<n<<","<<m<<")="
            <<nPrmRec(n,m)<<endl;
    
    //Clean up - File closing, memory de-allocation, etc....

    //Exit Stage Right!
    return 0;
}

//Function Implementations
unsigned int nPrmRec(unsigned int n,unsigned int m){
    return recFact(n)/recFact(n-m);
}

unsigned int recFact(unsigned int n){
    //Base Condition
    if(n<=1)return 1;
    //Recursion
    return recFact(n-1)*n;
}

unsigned int forFact(unsigned int n){
    unsigned int prod=1;
    for(int i=1;i<=n;i++){
        prod*=i;
    }
    return prod;
}
