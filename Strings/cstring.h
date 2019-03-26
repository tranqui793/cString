/**
 * @file cstring.h
 * @brief header of String methods
 * @date 07.03.2019.
 * @author Oussama Lagha
 * @author Max Caduff
 */

#ifndef CSTRING_H
#define CSTRING_H

#include <cstdlib>
#include <cstdio>
#include <iostream>

class String {

public:
    /**
     * Constructeur sans arguments, créé juste un \0.
     */
    String();

    /**
     * Constructeur de String à partir d'une autre String. (copie)
     * @param orig la String à partir de laquelle construire cette String
     */
    String(const String &orig);

    /**
     * Constructeur de String à partir d'un tableau de char. (finissant par \0)
     * @param c le tableau de caractère à partir duquel construire cette String.
     */
    explicit String(const char *c);

    /**
     * Constructeur de String à partir d'un caractère.
     * @param c le caractère à partir duquel construire cette String.
     */
    explicit String(char c);

    /**
     * Constructeur de String à partir d'un entier.
     * Calcule la longueur de la chaîne de caractères pouvant contenir le nombre i
     * à partir de la valeur de retour de la fonction snprintf.
     * @param i le nombre entier à partir duquel construire cette String.
     */
    explicit String(int integer);

    /**
     * Constructeur de String à partir d'un double.
     * Calcule la longueur de la chaîne de caractères pouvant contenir le nombre d
     * à partir de la valeur de retour de la fonction snprintf.
     * @param d le double à partir duquel contstruire cette String.
     */
    explicit String(double d);

    /**
     * Constructeur de String à partir d'un booléen.
     * Construit une String contenant "true" si b est vrai, "false" sinon.
     * @param b le booléen à partir duquel construire cette String.
     */
    explicit String(bool b);

    /**
     * Destructeur
     */
    ~String();

    /**
     * Renvoie la longueur du tableau de caractères String, sans le \0 final.
     * @return la longueur de cette String.
     */
    size_t length() const;

    /**
     * Renvoie une référence immuable vers la chaîne de caractères
     * contenue par cette String.
     * @return un pointeur sur la chaîne de caractères associée à cette String.
     */
    const char *toChar() const;

    /**
     * paraphrase de l'opérateur [].
     * @throw out_of_range si l'index n'est pas valide.
     * @param pos l'index du caractère.
     * @return une référence sur le caractère à l'index pos de cette String.
     */
    char &charAt(size_t pos) const;

    /**
     * paraphrase de l'opérateur ==.
     * @param c la chaîne de caractères avec laquelle comparer cette String.
     * @return vrai si cette String est identique à s, faux sinon.
     */
    bool equals(const char *c) const;

    /**
     * paraphrase de l'opérateur ==.
     * @param str la String avec laquelle comparer cette String.
     * @return vrai si les deux String sont identiques, faux sinon.
     */
    bool equals(const String &str) const;

    /**
     * paraphrase de l'opérateur =
     * @param c le tableau de char à copier dans cette String, doit finir par \0
     * @return une référence sur cette String modifiée.
     */
    String &assign(const char *c);

    /**
     * paraphrase de l'opérateur =
     * @param str la String à copier dans cette String.
     * @return une référence sur cette String modifiée.
     */
    String &assign(const String &str);


    /**
     * paraphrase de l'opérateur +=
     * @param c le tableau de char à concaténer à cette String.
     * @return une référence sur cette String modifiée.
     */
    String &append(const char *c);

    /**
     * paraphrase de l'opérateur +=
     * @param str la String à concaténer à cette String.
     * @return une référence sur cette String modifiée.
     */
    String &append(const String &str);

    /**
     * paraphrase de l'opérateur +
     * @param str la String à ajouter.
     * @return la concaténation des deux éléments dans une nouvelle String.
     */
    String concat(const String &str) const;

    /**
     * paraphrase de l'opérateur +
     * @param str le tableau de char à ajouter. (doit finir par \0)
     * @return la concaténation des deux éléments dans une nouvelle String.
     */
    String concat(const char *c) const;


    /**
     * Renvoie une sous-chaîne de cette String comprise entre les indices begin
     * et end. begin peut être négatif, on part alors de la fin de la String. Si
     * end > size ou end == 0, alors end = size.
     * @throw out_of_range si begin est en dehors des bornes de la String:
     * (-size <= begin < size)
     * @throw invalid_argument si begin >= end
     * @param begin le début de la sous-chaîne de caractères. (begin inclus)
     * @param end la fin de la sous-chaîne de caractères (end exclu).
     * @return une nouvelle String composée de la sous-chaîne de caractères 
     * comprise entre les indices begin et end de cette String.
     */
    String substring(int begin, size_t end = 0) const;

    /**
     * Renvoie une référence au n-ième caractère de cette String. [0; size-1]
     * @throw out_of_range si l'index n'est pas valide.
     * @param pos l'index du caractère.
     * @return une référence sur le caractère à l'index pos de cette String.
     */
    char &operator[](size_t pos) const;

    /**
     * Compare cette String avec une chaîne de caractères.
     * @param c la chaîne de caractères avec laquelle comparer cette String.
     * @return vrai si cette String est identique à c, faux sinon.
     */
    bool operator==(const char *c) const;

    /**
     * Compare cette String avec une autre
     * @param str la String avec laquelle comparer cette String.
     * @return vrai si les deux String sont identiques, faux sinon.
     */
    bool operator==(const String &str) const;

    /**
     * Compare cette String avec une chaîne de caractères.
     * @param c la chaîne de caractères avec laquelle comparer cette String.
     * @return faux si cette String est identique à c, vrai sinon.
     */
    bool operator!=(const char *c) const;

    /**
     * Compare cette String avec une autre
     * @param str la String avec laquelle comparer cette String.
     * @return faux si les deux String sont identiques, vrai sinon.
     */
    bool operator!=(const String &str) const;

    /**
     * Surcharge de l'opérateur = pour permettre l'affectation à la String
     * @param c le tableau de char à copier dans cette String, doit finir par \0
     * @return une référence sur cette String.
     */
    String &operator=(const char *c);

    /**
     * Surcharge de l'opérateur = pour permettre l'affectation à la String
     * @param str la String à copier dans cette String.
     * @return une référence sur cette String modifiée.
     */
    String &operator=(const String &str);


    /**
     * Surcharge de l'opérateur += pour permettre la concaténation de cette
     * String avec un tableau de char. (qui doit finir par \0)
     * @param c le tableau de char à concaténer à cette String.
     * @return une référence sur cette String modifiée.
     */
    String &operator+=(const char *c);

    /**
     * Surcharge de l'opérateur += pour permettre la concaténation de cette
     * String avec une autre String.
     * @param str l'autre String à concaténer à cette String.
     * @return une référence sur cette String modifiée.
     */
    String &operator+=(const String &str);

    /**
     * Surcharge de l'opérateur + pour permettre la concaténation de cette
     * String avec une autre dans une nouvelle String.
     * @param str la String à ajouter.
     * @return la concaténation des deux éléments dans une nouvelle String.
     */
    String operator+(const String &str) const;

    /**
     * Surcharge de l'opérateur + pour permettre la concaténation de cette
     * String avec un tableau de char dans une nouvelle String.
     * @param str le tableau de char à ajouter. (doit finir par \0)
     * @return la concaténation des deux éléments dans une nouvelle String.
     */
    String operator+(const char *str) const;


    /**
     * Surcharge de l'opérateur + de char* pour permettre la concaténation d'un
     * char* avec une string.
     * @param lhs le char* de gauche.
     * @param rhs la string à ajouter.
     * @return la concaténation des deux éléments dans une nouvelle String.
     */
    friend String operator+(const char *lhs, const String &rhs);

    /**
     * Surcharge de l'opérateur + de char pour permettre la concaténation d'un
     * char avec une string.
     * @param lhs le char de gauche.
     * @param rhs la string à ajouter.
     * @return la concaténation des deux éléments dans une nouvelle String.
     */
    friend String operator+(const char c, const String &rhs);

    /**
     * Surcharge de l'opérateur << pour envoyer une string sur un flux.
     * @param os le stream sur lequel envoyer la string.
     * @param rhs la string à afficher.
     * @return une référence sur le flux pour permettre le chainage.
     */
    friend std::ostream &operator<<(std::ostream &os, const String &str);

    /**
     * Surcharge de l'opérateur >> pour lire une string depuis un flux.
     * @param is le stream depuis lequel lire la string.
     * @param rhs la string à populer avec la lecture.
     * @return une référence sur le flux pour permettre le chainage.
     */
    friend std::istream &operator>>(std::istream &is, String &str);

private:

    /**
     * alloue la mémoire pour les nouvelles strings, et stocke la taille.
     * @param nb le nombre de cases mémoire à réserver, '\0' non inclus.
     * @return un pointeur sur la zone réservée.
     */
    char *allocateMemory(size_t nb);

    // représentation du texte sour forme de char*
    char *chain;
    // size keeps the length of the string, \0 not included.
    size_t size;

};

#endif /* CSTRING_H */

