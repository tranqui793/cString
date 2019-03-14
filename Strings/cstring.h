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
    char& char_at(size_t pos);
    char char_at(size_t pos)const;
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
    String substring(size_t off, size_t len) const;
    char& operator[](size_t pos);
    char operator[](size_t pos) const;
    bool operator==(const char *c) const;
    bool operator==(const String& str) const;
    bool operator!=(const char *c) const;
    bool operator!=(const String& str) const;
    String& operator=(const char *c);
    String& operator=(const String& str);
    String& operator+=(char c);
    String& operator+=(const char *c);
    String& operator+=(const String& str);
    friend String operator+(const String& lhs, const String& rhs);
    friend String operator+(const String& lhs, const char *rhs);
    friend String operator+(const char *lhs, const String& rhs);
    friend String operator+(const String& lhs, char c);
    friend String operator+(char c, const String& rhs);
    friend std::ostream& operator<<(std::ostream& os, const String& str);
    friend std::istream& operator>>(std::istream& is, String& s);
    String operator+(const String& lhs, const String& rhs);
    String operator+(const String& lhs, const char *rhs);
    String operator+(const char *lhs, const String& rhs);
    String operator+(const String& lhs, char c);
    String operator+(char c, const String& rhs);
    std::ostream& operator<<(std::ostream& os, const String& str);
    std::istream& operator>>(std::istream& is, String& s);
private:
    char* allocation_memoire(size_t nb);



private:
    char *chaine;

};

#endif /* CSTRING_H */

