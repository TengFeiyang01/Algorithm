#include <iostream>
#include <cstring>
#include "myString.h"


void myString::dump() {
    std::cout << _str << std::endl;
}

myString::myString(const char *s) {
    if (s == nullptr) {
        _str = new char[1];
        *_str = '\0';
    } else {
        int len = strlen(s);
        _str = new char[len + 1];
        strcpy(_str, s);
    }
}

myString::~myString() {
    delete[]_str;
}

myString::myString(const myString &other) {
    _str = new char[strlen(other._str) + 1];
    strcpy(_str, other._str);
}

char *myString::c_str() {
    return _str;
}

char myString::at(int n) {
    return _str[n];
}

char myString::operator[](int n) {
    return _str[n];
}

myString &myString::operator=(const myString &other) {
    if (this == &other) {
        return *this;
    }
    delete[]_str;
    int len = strlen(other._str);
    _str = new char[len + 1];
    strcpy(_str, other._str);
    return *this;
}

myString &myString::operator+=(const myString &other) {
    int len = strlen(other._str) + strlen(_str);
    //realloc(void*, size_t)  C++更加安全 需要进行强制转换
    this->_str = static_cast<char *> (realloc(static_cast<void *>(this->_str), len + 1));
    strcat(this->_str, other._str);

    return *this;
}

myString myString::operator+(const myString &other) {
    int len = strlen(other._str) + strlen(this->_str);
    myString ms;

    delete[]ms._str;

    ms._str = new char[len + 1]{0};
    strcat(strcat(ms._str, this->_str), other._str);

    return ms;
}

bool myString::operator<(const myString &other) {
    return strcmp(this->_str, other._str) < 0;
}

bool myString::operator>(const myString &other) {
    return strcmp(this->_str, other._str) > 0;
}

bool myString::operator==(const myString &other) {
    return strcmp(this->_str, other._str) == 0;
}

bool myString::operator<=(const myString &other) {
    return strcmp(this->_str, other._str) <= 0;
}

bool myString::operator>=(const myString &other) {
    return strcmp(this->_str, other._str) >= 0;
}