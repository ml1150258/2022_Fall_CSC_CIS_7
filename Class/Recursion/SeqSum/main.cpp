/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on April 20th, 2022, 10:15 AM
 * Purpose:  Sequence Sum
 */

//System Level Libraries
#include <iostream>   //I/O Library
#include <cmath>      //Math Library
using namespace std;  //Library Scope

//User Libraries

//Global Constants
//Science and Math, Conversions, Higher Dimensions const to follow

//Function Prototypes
float recSeq(float,float,float,int);
float forSeq(float,float,float,int);
float clsSeq(float,float,float,int);

//Execution Starts Here
int main(int argc, char** argv){
    //Set Random Number Seed Here
    
    //Declare Variables - Known and Unknown, units, range, description
    float p,c,d;
    int n;
    
    //Initialize Variables
    p=0;
    c=1.05f;
    d=10000.0f;
    n=50;
    
    //Map inputs to outputs -> i.e. process the inputs
    
    //Display the outputs
    cout<<"Recursive Seq f("<<p<<","<<c<<","<<d<<","<<n<<")  ="
            <<recSeq(p,c,d,n)<<endl;
    cout<<"For-Loop Seq f("<<p<<","<<c<<","<<d<<","<<n<<")   ="
            <<forSeq(p,c,d,n)<<endl;
    cout<<"Closed form Seq f("<<p<<","<<c<<","<<d<<","<<n<<")="
            <<clsSeq(p,c,d,n)<<endl;
    
    //Clean up - File closing, memory de-allocation, etc....

    //Exit Stage Right!
    return 0;
}

//Function Implementations

float recSeq(float p,float c,float d,int n){
    //Base Condition
    if(n<=0)return p;
    //Recursion
    return c*recSeq(p,c,d,n-1)+d;
}

float forSeq(float p,float c,float d,int n){
    float sum=p;
    for(int i=1;i<=n;i++){
        sum*=c;
        sum+=d;
    }
    return sum;
}

float clsSeq(float p,float c,float d,int n){
    if(c==1)return p+n*d;
    float cton=pow(c,n);
    float i=c-1;
    //return p*cton+d*(1-cton)/(1-c);
    return p*cton+d/i*(cton-1);
}