/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on August 30, 2022, 11:30 AM
 * Purpose:  Proper Comparison of 2 floating Point Values
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
    float exact,eapprox,tol,delta,x;
    int nTerms;
    
    //Initialize Variables
    tol=1e-7f;   //7 significant digit accuracy
    x=2;
    exact=exp(x);//e^1
    eapprox=1;   //Start the sequence at 1
    delta=1;
    nTerms=15;
    
    //Map inputs to outputs -> i.e. process the inputs
    for(int term=1;term<=nTerms;term++){
        delta*=x/term;
        eapprox+=delta;
    }
    float diff=exact-eapprox;
    
    //Display the outputs
    //cout<<fixed<<setprecision(16)<<showpoint;
    cout<<"Exact Value of exp("<<x<<")="<<exact<<endl;
    cout<<"Approx Value of exp("<<x<<")="<<eapprox<<" with "
            <<nTerms<<" terms"<<endl;
    cout<<"The tolerance for comparing the equivalence is = "<<tol<<endl;
    cout<<"The difference is = "<<diff<<endl;
    if(-tol<diff && diff<tol){
        cout<<"The answers are the same"<<endl;
    }else{
        cout<<"The answers are different"<<endl;
    }
    
    //Clean up - File closing, memory deallocation, etc....

    //Exit Stage Right!
    return 0;
}

//Function Implementations