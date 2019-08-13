#include "Subject.h"
#include "Observer.h"
#include <iostream>
#include <algorithm>
using std::cout;
using std::endl;
using std::find;

void Ring::attach(Observer* obs) {
    auto it = find(_obList.begin(), _obList.end(), obs);
    if(it == _obList.end()) {
        _obList.push_front(obs);
    }
}

void Ring::detach(Observer* obs) {
    auto it = find(_obList.begin(), _obList.end(), obs);
    if(it != _obList.end()) {
        _obList.erase(it);
    }
}

void Ring::notify() {
    for(auto& obs : _obList) {
        obs->update();
    }
}

void Ring::isPressed() {
    if(!_isAlarming) {
        _isAlarming = true;
        notify();
    }

    _isAlarming = false;
}

