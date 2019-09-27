 ///
 /// @file    Subject.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-08-12 16:55:29
 ///
 
#pragma once
#include <iostream>
#include <list>
#include <string>
using std::cout;
using std::endl;
using std::list;
using std::string;
 
class Observer;

class Subject
{
public:
	virtual void attach(Observer * obj)=0;
	virtual void detach(Observer * obj)=0;
	virtual void notify()=0;

	virtual ~Subject() {	cout << "~Subject()" << endl;	}
};

class Ring
: public Subject
{
public:
	Ring()
	: _isAlarming(false)
	{}

	void isPressed();

	virtual void attach(Observer * obj);
	virtual void detach(Observer * obj);
	virtual void notify();

private:
	list<Observer*> _obList;
	//可以对观察者进行分类, 根据业务需求来定
	//list<Observer*> _goldenUserList;
	//list<Observer*> _silverUserList;
	bool _isAlarming;
};

class Guest
{
public:
	Guest(const string & name)
	: _name(name)
	{}

	void knock(Ring & ring);

private:
	string _name;
};
