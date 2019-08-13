#pragma once
#include "Subject.h"
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

class Guest {
public:
    Guest(const string& name) 
        : _name(name) {}

    void knock(Ring& ring) {
        cout << "Guest " << _name << " is knocking the door" << endl;
        ring.isPressed();
    }
private:
    string _name;
};

