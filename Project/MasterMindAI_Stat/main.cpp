/*
    Dr. Mark E. Lehr
    CSC 7 Template for Mastermind AI
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip>
using namespace std;

//Function Prototypes
string AI(char,char);
bool eval(string,string,char &,char &);
string set();
int **initStat(int,int);
void destroy(int **,int);
int prntStat(int **,int,int);
void sum(int **,int,int);

int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare variables
    string code,guess;  //code to break, and current guess
    char rr,rw;         //right digit in right place vs. wrong place
    int nGuess;         //number of guesses
    int **stat;         //Stat array
    
    //Initialize Values
    nGuess=0;
    code=set();
    rr=rw=0;
    int row=3,col=6;
    stat=initStat(row,col);
    
    for(int i=0;i<10000;i++){
        guess=AI(0,0);
        eval(code,guess,rr,rw);
        cout<<setw(5)<<code<<setw(5)<<guess
                <<setw(2)<<static_cast<int>(rr)
                <<setw(2)<<static_cast<int>(rw)
                <<setw(2)<<static_cast<int>(rr+rw)<<endl;
        sum(stat,rr,rw);
    }
    prntStat(stat,row,col);
    
    //Exit the program
    destroy(stat,row);
    return 0;
}

int **initStat(int row,int col){
    int **stat=new int*[row];
    for(int i=0;i<row;i++){
        stat[i]=new int[col];
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            stat[i][j]=0;
        }
    }
    return stat;
}
void destroy(int **stat,int row){
    for(int i=0;i<row;i++){
        delete []stat[i];
    }
    delete []stat;
}

void sum(int **stat,int rr,int rw){
    stat[0][rr]++;
    stat[1][rw]++;
    stat[2][rr+rw]++;
}

int prntStat(int **stat,int row,int col){
    //Heading
    cout<<"        ";
    for(int j=0;j<col;j++){
        cout<<setw(5)<<j;
    }
    cout<<endl<<"Correct ";
    for(int j=0;j<col;j++){
        cout<<setw(5)<<stat[0][j];
    }
    cout<<endl<<"WrongPos";
    for(int j=0;j<col;j++){
        cout<<setw(5)<<stat[1][j];
    }
    cout<<endl<<"Sum     ";
    for(int j=0;j<col;j++){
        cout<<setw(5)<<stat[2][j];
    }
}

string AI(char rr,char rw){
    //Define helper functions here
    void (*print)(string [],char [],char [],int,int)=
        [] (string g[],char r[],char w[],int nb,int ne){ 
            for(int i=nb;i<=ne;i++){
                cout<<g[i]<<" "
                    <<static_cast<int>(r[i])<<" "
                    <<static_cast<int>(w[i])<<endl;
            }
    };
    
    //Save the historical values of guesses and results
    static const int SIZE=10001;//How many guesses to save
    static string aGuess[SIZE]; //Save the guesses
    static char grr[SIZE];      //Save right guess in right spot
    static char grw[SIZE];      //Save right guess in wrong spot
    static int guess=0;         //Increment the guess number
    string sGuess="0000";       //Size the guest string
    
    //Store the results from the last guess
    grr[guess]=rr;
    grw[guess]=rw;
    
    //Test the helper function
    if(rr==4)print(aGuess,grr,grw,
            guess-10>0?guess-10:0,guess);
    
    //Calculate the guess
    int n1000=(guess-guess%1000)/1000;
    int n100=(guess-guess%100)/100-10*n1000;
    int n10=(guess%100-guess%10)/10;
    int n1=guess%10;
    sGuess[0]=n1000+'0';
    sGuess[1]=n100+'0';
    sGuess[2]=n10+'0';
    sGuess[3]=n1+'0';
    aGuess[++guess]=sGuess;//Save the result
    
    //Return the result
    return sGuess;
}

bool eval(string code,string guess,char &rr,char &rw){
    string check="    ";
    rr=0,rw=0;
    //Check how many are right place
    for(int i=0;i<code.length();i++){
        if(code[i]==guess[i]){
            rr++;
            check[i]='x';
            guess[i]='x';
        }
    }
    //Check how many are wrong place
    for(int j=0;j<code.length();j++){
        for(int i=0;i<code.length();i++){
            if((i!=j)&&(code[i]==guess[j])&&(check[i]==' ')){
                rw++;
                check[i]='x';
                break;
            }
        }
    }
    
    //Found or not
    if(rr==4)return false;
    return true;
}

string set(){
    string code="0000";
    for(int i=0;i<code.length();i++){
        code[i]=rand()%10+'0';
    }
    return code;
}