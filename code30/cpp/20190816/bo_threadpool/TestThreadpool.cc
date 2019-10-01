 ///
 /// @file    TestThreadpool.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-08-15 16:17:30
 ///
 
#include "Threadpool.h"

#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::unique_ptr;

class Mytask
{
public:
	void process() 
	{
		::srand(::clock());
		//::srand(::time(nullptr));
		int number = ::rand() % 100;
		cout << "sub thread " << pthread_self() 
			 << ": produce a number = " << number << endl;
		//::sleep(1);
	}
};
 
int main(void)
{
	wd::Threadpool threadpool(4, 10);
	threadpool.start();

	unique_ptr<Mytask> task(new Mytask());
	int cnt = 20;
	while(cnt--) {
		threadpool.addTask(std::bind(&Mytask::process, task.get()));
		cout << ">> main thread : cnt = " << cnt << endl;
	}

	//threadpool.stop();

	return 0;
}
