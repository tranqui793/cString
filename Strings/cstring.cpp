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

String::String() {
    chaine=new char[0];
    chaine[0]='\0';
}

String::String(const String& orig) {
}

String::~String() {
    delete[] chaine;
}

