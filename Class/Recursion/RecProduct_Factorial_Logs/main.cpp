/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on April 20th, 2022, 10:15 AM
 * Purpose:  Recursive Product or Factorial
 *           using logs
 */

//System Level Libraries
#include <iostream>   //I/O Library
#include <cmath>      //Math Library
using namespace std;  //Library Scope

//User Libraries

//Global Constants
//Science and Math, Conversions, Higher Dimensions const to follow

//Function Prototypes
float recProd(float);
float forProd(float);
int display(float,float &);

//Execution Starts Here
int main(int argc, char** argv){
    //Set Random Number Seed Here
    
    //Declare Variables - Known and Unknown, units, range, description
    int n;
    
    //Initialize Variables
    n=10000;
    
    //Map inputs to outputs -> i.e. process the inputs
    
    //Display the outputs
    float fraction;
    int powr10=display(recProd(n),fraction);
    cout<<"Recursive Product/Factorial f("<<n<<")="
            <<pow(10,fraction)<<"x10^"<<powr10<<endl;
    powr10=display(forProd(n),fraction);
    cout<<"For-Loop  Product/Factorial f("<<n<<")="
            <<pow(10,fraction)<<"x10^"<<powr10<<endl;

    
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

float recProd(float n){
    //Base Condition
    if(n<=1)return 0;
    //Recursion
    return recProd(n-1)+log(n);
}

float forProd(float n){
    float prod=0;
    for(int i=1;i<=n;i++){
        prod+=log(i);
    }
    return prod;
}