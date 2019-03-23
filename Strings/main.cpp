/**
 * @file main.cpp
 * @brief program entry point
 * @date 07.03.2018.
 * @author Oussama Lagha
 * @author Max Caduff
 */

#include "cstring.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    
    String dbl (4.56);
    String intg (8279341);
    // test de mettre un \0 au milieu de la chaine
    intg[2] = '\0';
    
    // tst copy cstr
    String copy (dbl);

    cout << dbl << "  " << intg << " " << copy << "\n";
    
    // test += char et char*
    dbl += 'X';
    dbl += "this is a test." ;
    cout << dbl << '\n';
    
    // test + char*
    cout << dbl + "add\n";
    // vérif que dbl n'a pas changé
    cout << dbl << endl;
    String test = dbl.substring(-7, 250);
    cout << test << endl;
    
    cin >> test;
    cout << endl << "result: " << 'a' + test << "\nbye."+test ;
    
    return 0;
}

