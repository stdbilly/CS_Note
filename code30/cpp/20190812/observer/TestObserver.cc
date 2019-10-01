 ///
 /// @file    TestObserver.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-08-12 17:17:19
 ///
 
#include "Subject.h"
#include "Observer.h"

#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::unique_ptr;
 
int main(void)
{
	unique_ptr<Observer> baby1(new Baby("大宝"));	
	unique_ptr<Observer> baby2(new Baby("小宝"));	
	unique_ptr<Observer> nurse1(new Nurse("小丽"));
	unique_ptr<Observer> nurse2(new Nurse("小美"));

	Ring ring;
	ring.attach(baby1.get());
	ring.attach(baby2.get());
	ring.attach(nurse1.get());
	ring.attach(nurse2.get());

	Guest guest("小明");
	
	guest.knock(ring);
	ring.detach(nurse2.get());
	cout << ">> " << endl;
	guest.knock(ring);

	return 0;
}
