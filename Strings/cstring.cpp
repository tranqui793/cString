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


char* String::allocateMemory(size_t nb) {
    size = nb;
    char * tmp = new char[nb + 1];
    tmp[nb] = '\0';
    return tmp;
}

String::String() {
    chain = allocateMemory(0);
    std::cout << "empty cstr\n";
}

String::String(const String& orig) : String(orig.chain) {
    std::cout << "cpy cstr\n";
}

String::String(const char* c) {
    chain = allocateMemory(strlen(c));
    strcpy(chain, c);
    std::cout << "char* cstr\n";
}

String::String(char c) {
    chain = allocateMemory(1);
    chain[0] = c;
    std::cout << "char cstr\n";
}

String::String(bool b) {
    if (b) {
        chain = allocateMemory(4);
        sprintf(chain, "%s", "true");
    } else {
        chain = allocateMemory(5);
        sprintf(chain, "%s", "false");
    }
}

String::String(int integer){
    
    size_t size = snprintf(chain, 0, "%d", integer);
    chain = allocateMemory(size);
    snprintf(chain, size +1, "%d", integer);
    
}

String::String(double dbl){
    
    size_t size = snprintf(chain, 0, "%f", dbl);
    chain = allocateMemory(size);
    snprintf(chain, size +1, "%f", dbl);
}

String::~String() {
    delete[] chain;
}


size_t String::length() const {
    return size;
}

const char* String::toChar()const {
    return chain;
}
char& String::charAt(size_t pos)const {
    return chain[pos];
}
bool String::equals(const char *c) const {
    return *this == c;
}
bool String::equals(const String& str) const {
    return *this == str;
}
String& String::assign(const char *c) {
    return *this = c;
}
String& String::assign(const String& str) {
    return *this = str;
}
String& String::append(char c) {
    return *this += c;
}
String& String::append(const char *c) {
    return *this += c;
}
String& String::append(const String& str) {
    return *this += str;
}
String String::concat(char c) const {
    return *this + c;
}
String String::concat(const char *c) const {
    return *this + c;
}
String String::concat(const String& str) const {
    return *this + str;
}
String String::substring(int begin, size_t end) const {
    if (begin > size)
        throw std::out_of_range("begin > str len");
    if (0 == end)
        end = size;
    size_t newLen = end-begin;
    char subString[newLen+1];
    for(int k=0; k<newLen; k++)
        subString[k] = chain[k+begin];
    subString[newLen] = '\0';
    return String (subString);
}

char& String::operator[](size_t pos) const {
    if (pos > size)
        throw std::out_of_range("out of bounds");
    return *(chain + pos);
}


bool String::operator==(const char *c) const {
    return !strcmp(chain, c);
}
bool String::operator==(const String& str) const {
    return str == chain;
}
bool String::operator!=(const char *c) const {
    return ! (*this == c);
}
bool String::operator!=(const String& str) const {
    return ! (*this == str);
}
String& String::operator=(const char *c) {
    delete[] chain;
    allocateMemory(strlen(c));
    chain = strcpy(chain, c);
    return *this;
}
String& String::operator=(const String& str) {
    *this = str.chain;
    return *this;
}
String& String::operator+=(char c) {
    char* newChain = allocateMemory(size+1);
    strcpy(newChain, chain);
    newChain[size-1] = c;
    delete[] chain;
    chain = newChain;
    return *this;
}
String& String::operator+=(const char *c) {
    size_t oldSize = size;
    char* newChain = allocateMemory(size+strlen(c));
    strcpy(newChain, chain);
    strcpy(newChain+oldSize, c);
    delete[] chain;
    chain = newChain;
    return *this;
}
String& String::operator+=(const String& str) {
    *this += str.chain;
    return *this;
}

String String::operator+(const String& rhs) const {
    return *this + rhs.chain;
}
String String::operator+(const char *rhs) const {
    char* tmpChar = new char[size+strlen(rhs)+1];
    strcpy(tmpChar, chain);
    String tmpStr (strcat(tmpChar, rhs));
    delete[] tmpChar;
    return tmpStr;
}
String String::operator+(char c) const {
    char* tmpChar = new char[size+2];
    strcpy(tmpChar, chain);
    tmpChar[size] = c;
    String tmpStr (tmpChar);
    delete[] tmpChar;
    return tmpStr;
}




std::ostream& operator<<(std::ostream& os, const String& str) {

//   we don't do: os << str.chain; in case of \0 in the chain 
    for (size_t i = 0; i < str.size; i++ )
        os << str[i] ;
    return os;
}
