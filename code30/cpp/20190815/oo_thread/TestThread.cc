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

class Mythread
: public Thread
{
	void run() override
	{
		::srand(::clock());
		while(1) {
			int number = ::rand() % 100;
			cout << ">> number = " << number << endl;
			::sleep(1);
		}
	}
};
 
int main(void)
{
	Mythread thread1;
	//Mythread thread2 = thread1;//error 禁止复制

	unique_ptr<Thread> thread(new Mythread());
	thread->start();//产生子线程
	thread->join();
	//::sleep(10);
	return 0;
}
