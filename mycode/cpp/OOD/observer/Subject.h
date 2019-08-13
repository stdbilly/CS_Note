#pragma once
#include <iostream>
#include <string>
#include <list>
using std::cout;
using std::endl;
using std::string;
using std::list;

class Observer;

class Subject {
protected:
    virtual void attach(Observer* obs) = 0;
    virtual void detach(Observer* obs) = 0;
    virtual void notify() = 0;
    virtual ~Subject() { cout << "~Subject()" << endl; }
};

class Ring : public Subject {
public:
    Ring() 
        : _isAlarming(false) {}

    void isPressed();
    void attach(Observer* obs);
    void detach(Observer* obs);
    void notify();
private:
    list<Observer*> _obList;
    bool _isAlarming;
};
