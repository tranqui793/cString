/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cstring.h
 * Author: oussama
 *
 * Created on 7. mars 2019, 12:49
 */

#ifndef CSTRING_H
#define CSTRING_H

class String {
public:
    String();
    String(const String& orig);
    virtual ~String();
    String(size_t taille);
    String(const char *c);
    String(char c);
    String(int entier);
    String(double d);
    String(bool b);
    size_t length()const;
    const char *to_char()const;
private:
    char *chaine;
    
};

#endif /* CSTRING_H */

