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
int main(int argc, char **argv) {


    /* test 1 : constructeur d'une chaîne de caractères vide*/
    String s1;
    cout << "test 1 : s1 : " << s1 << endl;

    /* test 2 : constructeur d’une chaîne de caractères*/
    String s2("Strings ! ");
    cout << "test 2 : s2 : " << s2 << endl;

    /* test 3 : constructeur d’une instance de la classe String*/
    String s3(s2);
    cout << "test 3 : s3 : " << s3 << endl;

    /* test 4 : constructeur d’un caractère*/
    String s4('p');
    cout << "test 4 : s4 : " << s4 << endl;

    /* test 5 : constructeur d’un entier*/
    String s5(98);
    cout << "test 5 : s5 : " << s5 << endl;

    /* test 6 : constructeur d’un réél*/
    String s6(765.456);
    cout << "test 6 : s6 : " << s6 << endl;

    /* test 7 : constructeur d’un booléen*/
    String s7(true);
    cout << "test 7 : s7 : " << s7 << endl;

    /* autres méthodes tests

    /* test 8 : length test*/
    cout << "test 8 : " << s3.length() << endl;

    /* test 9 : toChar test */
    printf("test 9 : %s\n", s2.toChar());

    /* test 10 : modification du i-ème caractère*/
    s2.charAt(1) = 'e';
    cout << "test 10 : s2 : " << s2 << endl;

    /* test 10_1 : out_of_range test*/
    try {
        cout << "test 10.2 : " << s2.charAt(18) << endl;
    } catch (const std::out_of_range &e) {
        cout << e.what() << endl;
    }

    /*test 11 : récupération uniquement du i-ème caractère */
    const String s9("Test");
    cout << "test 11 : c = " << s9.charAt(1) << endl;

    /* test 11_1 :out_of_range test*/
    try {
        cout << "test 11_1 : " << s9.charAt(4) << endl;
    } catch (const std::out_of_range &e) {
        cout << e.what() << endl;
    }
    /*true or false test*/
    cout << boolalpha;

    /* test 12 : egalité test*/
    cout << "test 12 : " << s9.equals("Test") << endl;

    /* test 13 : égalité test*/
    String s10("Test");
    cout << "test 13 : " << s9.equals(s10) << endl;

    /* test 14 : assign  d'une chaîne de caractères*/
    s1.assign("Strings Lab");
    cout << "test 14 : " << s1 << endl;

    /* test 15 : assign d'un String*/
    s4.assign(s1);
    cout << "test 15 : " << s1 << endl;


    /* test 17 : append d'une chaîne de caractere*/
    s10.append("r main. ");
    cout << "test 17 : " << s10 << endl;

    /* test 18 :append d'une autre String*/
    s10.append(s3);
    cout << "test 18 : " << s10 << endl;

    /* test 20 : concat une chaine de caractères*/
    cout << "test 20 : " << s10.concat("Bonjour..") << endl;

    /* test 21 : concat une autre String*/
    cout << "test 21 : " << s10.concat(s1) << endl;

    /* test 22.1 : substring test*/
    cout << "test 22.1 : " << s10.substring(22, 29) << endl;

    /* test 22.2 : substring out_of_range test*/
    try {
        cout << "test 22.2 : indexDepart > indexArrivee : " << s10.substring(25, 21) << endl;
    } catch (const std::out_of_range &e) {
        cout << e.what() << endl;
    }

    /* test 22.3 : substring out_of_range test*/
    try {
        cout << "test 22.3 : indexArrivee > longueur string (qui vaut 40) : " << s10.substring(22, 41) << endl;
    } catch (const std::out_of_range &e) {
        cout << e.what() << endl;
    }



    return EXIT_SUCCESS;
}

