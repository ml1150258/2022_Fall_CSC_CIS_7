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
    int cntWin,cntLose,nGames;
    
    //Initialize Variables
    nGames=1000000;
    cntWin=cntLose=0;
    
    for(int game=1;game<=nGames;game++){
        stay=rand()%3+1;//[1,2,3]
        prize=rand()%3+1;//[1,2,3]

        //Map the inputs/known to the outputs
        do{
            dr2Opn=rand()%3+1;//[1,2,3]
        }while(dr2Opn==stay || dr2Opn==prize);

        do{
            swich=rand()%3+1;//[1,2,3]
        }while(swich==stay || dr2Opn==swich);
        
        if(stay==prize)cntWin++;
        else if(swich==prize) cntLose++;
    }
    
    //Display the outputs
    cout<<"Number of Games played   = "<<nGames<<endl;
    cout<<"Percent won by Staying   = "<<100.0f*cntWin/nGames<<"%"<<endl;
    cout<<"Percent won by Switching = "<<100.0f*cntLose/nGames<<"%"<<endl;
    cout<<"Number of Games played   = "<<cntWin+cntLose<<endl;

    //Exit the program
    return 0;
}