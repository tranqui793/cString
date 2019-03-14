/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cstring.cpp
 * Author: oussama
 * 
 * Created on 7. mars 2019, 12:49
 */

#include "cstring.h"
#include <cstring>
#include <stdio.h>
String::allocation_memoire(size_t nb){
    return new char[nb+1];
}
String::String() {
    chaine=allocation_memoire(0);
    chaine[0]='\0';
}

String::String(const String& orig) :String(orig.chaine){
}

String::~String() {
    delete[] chaine;
}

String::String(const char* c){
    chaine=allocation_memoire(strlen(c));
    strcpy(chaine,c);
}
String::String(char c) {
    chaine=allocation_memoire(1);
    sprintf(chaine,"%c",c);
}
size_t String::length() const {
    return strlen(chaine);
}