/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on April 20th, 2022, 10:15 AM
 * Purpose:  Recursive Sum
 */

//System Level Libraries
#include <iostream>   //I/O Library
#include <cmath>      //Math Library
using namespace std;  //Library Scope

//User Libraries

//Global Constants
//Science and Math, Conversions, Higher Dimensions const to follow

//Function Prototypes
int recSum(int);//Recursive Sum
int forSum(int);//For-Loop Sum
int clsSum(int);//Closed form solution of the incremental sum

//Execution Starts Here
int main(int argc, char** argv){
    //Set Random Number Seed Here
    
    //Declare Variables - Known and Unknown, units, range, description
    int n;
    
    //Initialize Variables
    n=10;
    
    //Map inputs to outputs -> i.e. process the inputs
    
    //Display the outputs
    cout<<"Recursive Sum f("<<n<<")="<<recSum(n)<<endl;
    cout<<"For-Loop Sum f("<<n<<")="<<forSum(n)<<endl;
    cout<<"Closed Form Sum f("<<n<<")="<<clsSum(n)<<endl;
    
    //Clean up - File closing, memory de-allocation, etc....

    //Exit Stage Right!
    return 0;
}

//Function Implementations

int recSum(int n){
    //Base Condition
    if(n<=1)return 1;
    //Recursion
    return recSum(n-1)+n;
}

int forSum(int n){
    int sum=0;
    for(int i=1;i<=n;i++){
        sum+=i;
    }
    return sum;
}

int clsSum(int n){
    return n*(n+1)/2;
}