/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: mlehr
 *
 * Created on October 7, 2021, 10:53 AM
 */

#include <iostream>
using namespace std;
int main(int argc, char** argv) {
    const char *s  = u8"\u274C";
    const char *r  = u8"\u2705";
    cout << s << endl;
    cout << r << endl;
    char x=65;//Ascii 65 = 'A'
    const char *A=&x;
    cout<<*A<<endl;
    return 0;
}

