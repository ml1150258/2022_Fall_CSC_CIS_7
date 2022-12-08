/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on November 10,2022 11:30 AM
 * Purpose:  Lottery Hash
 */

//System Level Libraries
#include <iostream>   //I/O Library
#include <cstdlib>    //Random Library
#include <cmath>      //Math Library
#include <ctime>      //Random Library
using namespace std;  //Library Scope

//User Libraries

//Global Constants
//Science and Math, Conversions, Higher Dimensions const to follow

//Function Prototypes
unsigned int mrkRand(void);

//Execution Starts Here
int main(int argc, char** argv){
    //Set Random Number Seed Here
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables - Known and Unknown, units, range, description
    unsigned int plays,tcktSld;
    const int depth=20;
    unsigned int stats[depth]={};
    
    //Initialize Variables
    //plays=69*68*67*66*65/5/4/3/2*26;
    plays=32768;
    tcktSld=plays;//400000000;
    
    //Map inputs to outputs -> i.e. process the inputs
    /*unsigned int min,max;
    min=max=rand();
    for(unsigned int i=1;i<4000000000;i++){
        unsigned int temp=mrkRand();
        if(min>temp)min=temp;
        if(max<temp)max=temp;
    }
    cout<<"Max Rand = "<<max<<endl;
    cout<<"Min Rand = "<<min<<endl;*/
    
    //Allocate the memory for all possible combinations
    unsigned char *array=new unsigned char[plays];
    for(int i=0;i<plays;i++){
        array[i]=0;
    }
    
    //Randomly Purchase Tickets
    for(int i=1;i<=tcktSld;i++){
        array[mrkRand()%plays]++;
    }
    
    //Take the statistics 
    for(int i=0;i<plays;i++){
        stats[array[i]]++;
    }
    
    //Output the statistics
    for(int i=0;i<depth;i++){
        cout<<i<<" -> "<<stats[i]<<" -> "<<100.0f*stats[i]/plays<<"%"<<endl;
    }
    
    //Display the outputs
    cout<<"Number of ways to play Powerball = "<<plays<<endl;
    cout<<"Number of tickets sold = "<<tcktSld<<endl;
    
    
    //Clean up - File closing, memory deallocation, etc....
    delete []array;
    
    //Exit Stage Right!
    return 0;
}

//Function Implementations
unsigned int mrkRand(void){
    unsigned int temp1=rand();
    temp1<<=15;
    unsigned int mask=0x00007FFF;
    unsigned int temp2=mask&rand();
    return temp1+temp2;
}