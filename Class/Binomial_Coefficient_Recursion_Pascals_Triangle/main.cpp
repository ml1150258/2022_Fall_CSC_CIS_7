/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on April 25th, 2022, 12:15 PM
 * Purpose:  Pascals Recursion
 */

//System Level Libraries
#include <iostream>   //I/O Library
#include <iomanip>    //Format Library
#include <cmath>      //Math Library
using namespace std;  //Library Scope

//User Libraries

//Global Constants
//Science and Math, Conversions, Higher Dimensions const to follow

//Function Prototypes
int bCoeff(int,int);

//Execution Starts Here
int main(int argc, char** argv){
    //Set Random Number Seed Here
    
    //Declare Variables - Known and Unknown, units, range, description
    int n;
    
    //Initialize Variables
    n=8;
    
    //Map inputs to outputs -> i.e. process the inputs
    cout<<"                                nCm "<<endl;
    cout<<"                              Column"<<endl;
    cout<<" Row";
    for(int i=0;i<=n;i++){
        cout<<setw(5)<<i<<" ";
    }
    cout<<endl;
    for(int row=0;row<=n;row++){
        cout<<setw(4)<<row;
        for(int col=0;col<=row;col++){
            cout<<setw(5)<<bCoeff(row,col)<<" ";
        }
        cout<<endl;
    }
    
    //Display the outputs
    
    //Clean up - File closing, memory deallocation, etc....

    //Exit Stage Right!
    return 0;
}

//Function Implementations
int bCoeff(int n,int m){
    //Base Condition
    if(m==0)return 1;
    if(n==m)return 1;
    //Recursion like fibonacci
    return bCoeff(n-1,m-1)+bCoeff(n-1,m);
}