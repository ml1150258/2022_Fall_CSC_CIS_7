/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on May 11th, 2022, 11:30 AM
 * Purpose:  All Projects start by using the CPP Template
 *           It shows where to place/code your projects
 */

//System Level Libraries
#include <iostream>  //Input-Output Library
#include <cstdlib>
#include <ctime>
using namespace std;

//User Defined Libraries

//Global Constants, not Global Variables
//These are recognized constants from the sciences
//Physics/Chemistry/Engineering and Conversions between
//systems of units!

//Function Prototypes

//Execution begins here!
int main(int argc, char** argv) {
    //Initialize Random Seed once here!
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    int stay,swich,dr2Opn,prize;
    
    //Initialize Variables
    stay=rand()%3+1;//[1,2,3]
    prize=rand()%3+1;//[1,2,3]
    
    //Map the inputs/known to the outputs
    do{
        dr2Opn=rand()%3+1;//[1,2,3]
    }while(dr2Opn==stay || dr2Opn==prize);
    
    do{
        swich=rand()%3+1;//[1,2,3]
    }while(swich==stay || dr2Opn==swich);
    
    //Display the outputs
    cout<<"The door I choose  = "<<stay<<endl;
    cout<<"The door to open   = "<<dr2Opn<<endl;
    cout<<"The door to switch = "<<swich<<endl;
    cout<<"Where the prize is = "<<prize<<endl;

    //Exit the program
    return 0;
}