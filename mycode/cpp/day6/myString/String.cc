#include "String.h"
#include <string.h>
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

String::String():_pstr(nullptr) {
    cout<<"String()"<<endl;
}

String::~String() {
    if(_pstr) {
        delete [] _pstr;
    }
    cout<<"~String()"<<endl;
}

String::String(const char *pstr) 
    : _pstr(new char[strlen(pstr)+1]()) {
        strcpy(_pstr,pstr);
        cout<<"String(const char *)"<<endl;
    }

String::String(const String& rhs) 
    : _pstr(new char[strlen(rhs._pstr)+1]()) {
        strcpy(_pstr,rhs._pstr);
        cout<<"String(const String& rhs)"<<endl;
    }

String & String::operator=(const String &rhs) {
    if(this != &rhs) { //避免自复制
        delete [] _pstr; //回收左操作数空间
        _pstr = new char[strlen(rhs._pstr)+1](); //深拷贝
        strcpy(_pstr,rhs._pstr);
    }
    cout<<"String &operator=(const String &)"<<endl;
    return *this;
}

String & String::operator=(const char *pstr) {
    String temp(pstr);
    *this = temp;
    return *this;
}

String & String::operator+=(const String &rhs) {
    char* ptmp = new char[rhs.size() + size() + 1]();
    strcpy(ptmp, _pstr);
    strcat(ptmp, rhs._pstr);
    if(_pstr) delete [] _pstr;
    _pstr = ptmp;
    return *this;
}

String & String::operator+=(const char *pstr) {
    String tmp(pstr);
    *this += tmp;
    return *this;
}

char & String::operator[](std::size_t index) {
    if(index <= size()) {
        return _pstr[index];
    } else {
        static char nullchar = '\0';
        return nullchar;
    }
}

const char & String::operator[](std::size_t index) const {
    return _pstr[index];
}

size_t String::size() const {
    return strlen(_pstr);
}

const char* String::c_str() const {
    return _pstr;
}

bool operator==(const String &lhs, const String &rhs) {
    return strcmp(lhs.c_str(),rhs.c_str())==0 ? true : false;
}

bool operator!=(const String &lhs, const String &rhs) {
    return !(lhs==rhs);
}

bool operator<(const String &lhs, const String &rhs) {
    return strcmp(lhs.c_str(),rhs.c_str())<0 ? true : false;
}

bool operator>(const String &lhs, const String &rhs) {
    return strcmp(lhs.c_str(),rhs.c_str())>0 ? true : false;
}

bool operator<=(const String &lhs, const String &rhs) {
    return lhs < rhs || lhs == rhs;
}

bool operator>=(const String &lhs, const String &rhs) {
    return lhs > rhs || lhs == rhs;
}

std::ostream &operator<<(std::ostream &os, const String &s) {
    os << s._pstr;
    return os;
}

std::istream &operator>>(std::istream &is, String &rhs) {
    vector<char> buff;
    buff.reserve(1024);
    char ch;
    while((ch = is.get()) != '\n') {
        buff.push_back(ch);
    }
    rhs = &buff[0];
    return is;
}

String operator+(const String &lhs, const String &rhs) {
    char* pstr = new char[lhs.size() + rhs.size() + 1]();
    strcpy(pstr,lhs.c_str());
    strcat(pstr,rhs.c_str());
    String tmp(pstr);
    return tmp;
}

String operator+(const String &lhs, const char *pstr) {
    char* ptmp = new char[lhs.size() + strlen(pstr) + 1]();
    strcpy(ptmp,lhs.c_str());
    strcat(ptmp,pstr);
    String tmp(ptmp);
    return tmp;
}

String operator+(const char *pstr, const String &rhs) {
    char* ptmp = new char[rhs.size() + strlen(pstr) + 1]();
    strcpy(ptmp,pstr);
    strcat(ptmp,rhs.c_str());
    String tmp(ptmp);
    return tmp;
}
