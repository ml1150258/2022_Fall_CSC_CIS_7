/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on August 24, 2021, 7:51 AM
 * Purpose:  How to compare real/float values for an equality
 */

//System Level Libraries
#include <iostream>   //I/O Library
#include <cmath>      //Math Library
#include <iomanip>    //Format Library
using namespace std;  //Library Scope

//User Libraries

//Global Constants
//Science and Math, Conversions, Higher Dimensions const to follow

//Function Prototypes

//Execution Starts Here
int main(int argc, char** argv){
    //Set Random Number Seed Here
    
    //Declare Variables - Known and Unknown, units, range, description
    float L,a8,a7,epsilon;//Universal, Existential, Conditional variables
    bool equal;           //Test for equality
    int places=7;         //Number of significant digits
    
    //Initialize Variables
    L=3.2e6f;       //3.2 million
    a8=3.2000003e6f;//Close to 3.2 million 8 SD
    a7=3.200003e6f; //Close to 3.2 million 7 SD
    epsilon=pow(10,log10(L)-places);//Float within 7 significant digits

    //Map inputs to outputs -> i.e. process the inputs
    equal=(-epsilon < a8-L) && (a8-L < epsilon);
    //equal=abs(a8-L)<epsilon;
    
    //Display the outputs
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"Are these equivalent to "<<places<<" decimal places?"<<endl;
    cout<<"L="<<L<<endl;
    cout<<"a8="<<a8<<endl;
    cout<<(equal?"Yes -> L==a8":"No -> L!=a8")<<endl;
    cout<<endl;
    
    //Map inputs to outputs -> i.e. process the inputs
    //equal=(-epsilon < a7-L) && (a7-L < epsilon);
    equal=abs(a7-L)<epsilon;
    
    //Display the outputs
    cout<<"Are these equivalent to "<<places<<" decimal places?"<<endl;
    cout<<"L="<<L<<endl;
    cout<<"a7="<<a7<<endl;
    cout<<(equal?"Yes -> L==a7":"No -> L!=a7")<<endl;
    
    //Clean up - File closing, memory deallocation, etc....

    //Exit Stage Right!
    return 0;
}

//Function Implementations