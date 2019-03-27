/**
 * @file main.cpp
 * @brief program entry point
 * @date 07.03.2019.
 * @author Oussama Lagha
 * @author Max Caduff
 */

#include "cstring.h"

using namespace std;

/*
 * programme de test
 */
int main(int argc, char **argv) {


    /* test 1 : constructeur par défaut (chaîne de caractères vide)*/
    String s1;
    cout << "test 1 : s1 : " << s1 << endl;

    /* test 2 : constructeur à partir d’une chaîne de caractères*/
    String s2("Strings !");
    cout << "test 2 : s2 : " << s2 << endl;

    /* test 3 : constructeur à partir d’une instance de la classe String*/
    String s3(s2);
    cout << "test 3 : s3 : " << s3 << endl;

    /* test 4 : constructeur à partir d’un caractère*/
    String s4('p');
    cout << "test 4 : s4 : " << s4 << endl;

    /* test 5 : constructeur à partir d’un entier*/
    String s5(98);
    cout << "test 5 : s5 : " << s5 << endl;

    /* test 6 : constructeur à partir d’un réél*/
    String s6(765.456);
    cout << "test 6 : s6 : " << s6 << endl;

    /* test 7 : constructeur à partir d’un booléen*/
    String s7(true);
    cout << "test 7 : s7 : " << s7 << endl;

    /* autres méthodes tests */

    /* test 8 : length test*/
    cout << "test 8 : s3 length = " << s3.length() << endl;

    /* test 9 : toChar test */
    printf("test 9 : s2: %s\n", s2.toChar());

    /* test 10 : modification du i-ème caractère*/
    s2.charAt(1) = 'p';
    cout << "test 10 : s2 : " << s2 << endl;

    /* test 10_1 : out_of_range test*/
    try {
        cout << "test 10.1 : " << s2.charAt(40) << endl;
    } catch (const std::out_of_range &e) {
        cout << e.what() << endl;
    }

    /*test 11 : récupération uniquement du i-ème caractère */
    const String s9("Test");
    cout << "test 11 : should be 'e' " << s9[1] << endl;

    /* test 11_1 :out_of_range test*/
    cout << "test 11.1 : ";
    try {
        cout << s9[4] << endl;
    } catch (const std::out_of_range &e) {
        cout << e.what() << endl;
    }
    /*true or false test*/
    cout << boolalpha;

    /* test 12 : egalité test*/
    cout << "test 12 : true: " << s9.equals("Test") << endl;

    /* test 13 : égalité test*/
    String s10("Test");
    cout << "test 13 : true: " << s9.equals(s10) << endl;

    /* test 14 : assign  d'une chaîne de caractères*/
    s1.assign("Strings Lab");
    cout << "test 14 : s1: " << s1 << " new length: " << s1.length() << endl;

    /* test 15 : assign d'un String*/
    s4.assign(s1);
    cout << "test 15 : s4: " << s4 << " new length: " << s4.length() << endl;

    /* test 17 : append d'une chaîne de caractere*/
    s10.append("er main. ");
    cout << "test 17 : s10: " << s10 << endl;

    /* test 18 :append d'une autre String*/
    s10.append(s3);
    cout << "test 18 : s10: " << s10 << endl;

    /* test 19 : concat une chaine de caractères*/
    cout << "test 19 : concat: " << s10.concat("Bonjour..") << endl;

    /* test 20 : concat une autre String*/
    cout << "test 20 : concat: " << s10.concat(s1) << endl;
    
    /* test 21 : concat returns a new string*/
    cout << "test 21 : s10 not modified: " << s10 << endl;

    /* test 22 : substring test*/
    cout << "test 22 substr. 'Strings !' : " << s10.substring(-9, 0) << endl;

    /* test 22.1 : substring invalid_argument test*/
    try {
        cout << "test 22.1 : begin > end : "
            << s10.substring(20, 10) << endl;
    } catch (const std::invalid_argument &e) {
        cout << e.what() << endl;
    }

    /* test 22.2 : substring out_of_range test*/
    try {
        cout << "test 22.2 : begin > string length: "
             << s10.substring(25, 0) << endl;
    } catch (const std::out_of_range &e) {
        cout << e.what() << endl;
    }
    
    /* test 23 : constructing a string from user input*/
    cout << "enter a string (spaces allowed):\n" ;
    cin >> s1;
    cout << "test 23 cin: " << s1 << endl;
    
    
    /*   TEST CONST    */
    
    const String s11 ("constant string");
    const String s12 ("other constant string");
    
    /* test 24 : length test*/
    cout << "test 24 : length = " << s11.length() << endl;
    
    /* test 25 : toChar test */
    printf("test 25 : s11: %s\n", s11.toChar());
    
    /* test 26 : affichage du 3ème caractère (n)*/
    cout << "test 26 : 3rd char (n): " << s11.charAt(2)  << endl;
    
    /* test 27 : egalité test*/
    cout << "test 27 : true " << s11.equals("constant string") << endl;
    
    /* test 28 : égalité + substring test*/
    cout << "test 28 : true " << s11.equals(s12.substring(6)) << endl;
    
    /* test 29 : assign d'un String const*/
    s4.assign(s11);
    cout << "test 29 : s4: " << s4 << " new length: " << s4.length() << endl;
    
    /* test 30 :append d'une autre String const*/
    s1.append(s11);
    cout << "test 30 : s1 = " << s1 << endl;

    /* test 31 : concat une chaine de caractères*/
    cout << "test 31 : concat: " << s11.concat("Bonjour") << endl;
    
    /* test 32 : concat une autre String*/
    cout << "test 32 : concat: " << s11.concat(s12) << endl;
    
    /* test 33 : inegalité test*/
    cout << "test 33 : true : " << (s11 != s12) << endl;
    
    


    return EXIT_SUCCESS;
}

