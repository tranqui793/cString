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
#include <cstdlib>
#include <cstdio>
#include <iostream>

class String {
public:
    String();
    String(const String& orig);
    String(const char *c);
    String(char c);
    String(int integer);
    String(double d);
    String(bool b);
    ~String();
    size_t length()const;
    const char* toChar()const;
    char& charAt(size_t pos)const;
    bool equals(const char *c) const;
    bool equals(const String& str) const;
    String& assign(const char *c);
    String& assign(const String& str);
    String& append(char c);
    String& append(const char *c);
    String& append(const String& str);
    String concat(char c) const;
    String concat(const char *c) const;
    String concat(const String& str) const;
    String substring(int begin, size_t end = 0) const;
    char& operator[](size_t pos) const;
    bool operator==(const char *c) const;
    bool operator==(const String& str) const;
    bool operator!=(const char *c) const;
    bool operator!=(const String& str) const;
    String& operator=(const char *c);
    String& operator=(const String& str);
    String& operator+=(char c);
    String& operator+=(const char *c);
    String& operator+=(const String& str);
    String operator+(const String& rhs) const;
    String operator+(const char *rhs) const;
    String operator+(char c) const;
//    friend String operator+(const String& lhs, const String& rhs);
//    friend String operator+(const String& lhs, const char *rhs);
//    friend String operator+(const char *lhs, const String& rhs);
//    friend String operator+(char c, const String& rhs);
    friend std::ostream& operator<<(std::ostream& os, const String& str);
    friend std::istream& operator>>(std::istream& is, const String& str);
    
private:
    char* allocateMemory(size_t nb);

    char *chain;
    //size keeps the length of the string, \0 not included.
    size_t size;

};

#endif /* CSTRING_H */

