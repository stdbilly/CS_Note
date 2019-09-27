 ///
 /// @file    TestThread.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-08-15 09:53:40
 ///
 
#include "Thread.h"

#include <unistd.h>
#include <time.h>
#include <stdlib.h>

#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::unique_ptr;
using namespace wd;

class Task 
{
public:
	void run() 
	{
		::srand(::clock());
		while(1) {
			int number = ::rand() % 100;
			cout << ">> number = " << number << endl;
			::sleep(1);
		}
	}
};


void process() 
{
	::srand(::clock());
	while(1) {
		int number = ::rand() % 100;
		cout << ">> number = " << number << endl;
		::sleep(1);
	}
}
 
int main(void)
{
	//unique_ptr<Thread> thread(new Thread(std::bind(&Task::run, Task())));
	//Task task;
	//unique_ptr<Thread> thread(new Thread(std::bind(&Task::run, &task)));
	cout << "bo thread test:" << endl;
	unique_ptr<Thread> thread(new Thread(process));
	thread->start();
	//thread->join();
	::sleep(10);
	return 0;
}
