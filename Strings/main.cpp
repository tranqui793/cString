/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: oussama
 *
 * Created on 7. mars 2019, 12:49
 */

#include "cstring.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    
    String dbl (4.56);
    String intg (8279341);
    intg[2] = '\0';
    cout << dbl << "  " << intg << "\n";
    
    dbl += "this is a test." ;
    dbl += 'X';
    cout << dbl << '\n';
    
    cout << dbl + 'a';
    cout << '\n' << dbl << endl;
    
    String test = dbl.substring(5,12);
    cout << test;
    
    return 0;
}

