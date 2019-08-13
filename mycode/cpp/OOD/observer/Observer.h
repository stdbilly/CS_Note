#pragma once
#include "Subject.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

class Observer {
public:
    virtual void update() = 0;
    virtual ~Observer() { cout << "~Observer()" << endl; }
};

class Baby : public Observer {
public:
    Baby(const string& name) 
        : _name(name) {}

    void update() {
        ::srand(::clock());
        int num = ::rand() % 100;
        if(num < 70) {
            cout << "Baby " << _name << " is sleeping" << endl;
        } else {
            cout << "Baby " << _name << " is crying" << endl;
        }
    }
private:
    string _name;
};

class Nurse : public Observer {
public:
    Nurse(const string& name) 
        : _name(name) {}

    void update() {
        ::srand(::clock());
        int num = ::rand() % 100;
        if(num < 70) {
            cout << "Nurse " << _name << " is running to open the door" << endl;
        } else {
            cout << "Nurse " << _name << " is sleeping" << endl;
        }
    }
private:
    string _name;
};

