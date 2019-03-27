/**
 * @file cstring.cpp
 * @brief implementation of String methods
 * @date 07.03.2019.
 * @author Oussama Lagha
 * @author Max Caduff
 */

#include "cstring.h"
#include <cstring>


char *String::allocateMemory(const size_t nb) {
    size = nb;
    char *tmp = new char[nb + 1];
    tmp[nb] = '\0';
    return tmp;
}

String::String() {
    chain = allocateMemory(0);
}

String::String(const String &orig) : String(orig.chain) {}

String::String(const char *c) {
    chain = allocateMemory(strlen(c));
    strcpy(chain, c);
}

String::String(char c) {
    chain = allocateMemory(1);
    chain[0] = c;
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

String::String(int integer) {

    size_t size = snprintf(chain, 0, "%d", integer);
    chain = allocateMemory(size);
    snprintf(chain, size + 1, "%d", integer);

}

String::String(double dbl) {

    size_t size = snprintf(chain, 0, "%f", dbl);
    chain = allocateMemory(size);
    snprintf(chain, size + 1, "%f", dbl);
}

String::~String() {
    delete[] chain;
}

size_t String::length() const {
    return size;
}

const char *String::toChar() const {
    return chain;
}

char &String::charAt(const size_t pos) const {
    return (*this)[pos];
}

bool String::equals(const char *c) const {
    return *this == c;
}

bool String::equals(const String &str) const {
    return *this == str;
}

String &String::assign(const char *c) {
    return *this = c;
}

String &String::assign(const String &str) {
    return *this = str;
}


String &String::append(const char *c) {
    return *this += c;
}

String &String::append(const String &str) {
    return *this += str;
}


String String::concat(const char *c) const {
    return *this + c;
}

String String::concat(const String &str) const {
    return *this + str;
}

String String::substring(int begin, size_t end) const {
    // we could also send an empty str begin out of bounds.
    if (begin > (int) size || begin < int(0 - size))
        throw std::out_of_range("begin out of bounds");
   
    if (0 == end || end > size)
        end = size;

    if (begin >= (int) end)
        throw std::invalid_argument("begin >= end");

    if (begin < 0)
        begin = (int) size + begin;

    size_t newLen = end - begin;
    char subString[newLen];
    for (int k = 0; k < newLen; k++)
        subString[k] = chain[k + begin];
    subString[newLen] = '\0';
    return String(subString);
}

char &String::operator[](const size_t pos) const {
    if (pos >= size)
        throw std::out_of_range("out of bounds");
    return *(chain + pos);
}


bool String::operator==(const char *c) const {
    return !strcmp(chain, c);
}

bool String::operator==(const String &str) const {
    return str == chain;
}

bool String::operator!=(const char *c) const {
    return !(*this == c);
}

bool String::operator!=(const String &str) const {
    return !(*this == str);
}

String &String::operator=(const char *c) {
    delete[] chain;
    chain = allocateMemory(strlen(c));
    chain = strcpy(chain, c);
    return *this;
}

String &String::operator=(const String &str) {
    return *this = str.chain;
}

String &String::operator+=(const char *c) {
    size_t oldSize = size;
    char *newChain = allocateMemory(oldSize + strlen(c));
    strcpy(newChain, chain);
    strcpy(newChain + oldSize, c);
    delete[] chain;
    chain = newChain;
    return *this;
}

String &String::operator+=(const String &str) {
    return *this += str.chain;
}

String String::operator+(const String &str) const {
    return *this + str.chain;
}

String String::operator+(const char *str) const {
    char tmpChar[size + strlen(str)];
    strcpy(tmpChar, chain);
    return String(strcat(tmpChar, str));

}

String operator+(const char *lhs, const String &rhs) {
    char tmpChar[rhs.size + strlen(lhs)];
    strcpy(tmpChar, lhs);
    return String(strcat(tmpChar, rhs.chain));
}

String operator+(const char c, const String &rhs) {
    char tmpChar[rhs.size + 1];
    tmpChar[0] = c;
    strcpy(tmpChar + 1, rhs.chain);
    return String(tmpChar);
}


std::ostream &operator<<(std::ostream &os, const String &str) {

//   we don't do: os << str.chain; in case of \0 in the chain 
    for (size_t i = 0; i < str.size; i++)
        os << str[i];
    return os;
}

std::istream &operator>>(std::istream &is, String &str) {

    char tmp[1000];
    std::cin.getline(tmp, 1000);
    delete[] str.chain;
    str.chain = str.allocateMemory(std::min((int) strlen(tmp), 1000));
    strncpy(str.chain, tmp, 1000);

    return is;

}

