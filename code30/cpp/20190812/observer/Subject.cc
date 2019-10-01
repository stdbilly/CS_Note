 ///
 /// @file    Subject.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-08-12 16:59:46
 ///
 
#include "Subject.h"
#include "Observer.h"
#include <iostream>
#include <algorithm>
using std::cout;
using std::endl;
 
void Ring::attach(Observer * obj)
{
	auto it = std::find(_obList.begin(), _obList.end(), obj);
	if(it == _obList.end()) {
		_obList.push_front(obj);
	}
}

void Ring::detach(Observer * obj)
{
	auto it = std::find(_obList.begin(), _obList.end(), obj);
	if(it != _obList.end()) {
		_obList.erase(it);
	}
}

void Ring::notify()
{
	for(auto & obj : _obList) {
		obj->update();
	}
}

void Ring::isPressed() 
{
	if(!_isAlarming) {
		_isAlarming = true;
		notify();
	}

	_isAlarming = false;
}


void Guest::knock(Ring & ring)
{
	cout << ">>> Guest " << _name << " is knocking at the door!" << endl;
	ring.isPressed();
}
