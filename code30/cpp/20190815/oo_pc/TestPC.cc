 ///
 /// @file    TestPC.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-08-15 11:39:00
 ///

#include "TaskQueue.h"
#include "Producer.h"
#include "Consumer.h"

#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::unique_ptr;
using namespace wd;
 
int main(void)
{
	TaskQueue taskque(10);

	unique_ptr<Thread> producer(new Producer(taskque));
	unique_ptr<Thread> consumer(new Consumer(taskque));

	producer->start();
	consumer->start();

	producer->join();
	consumer->join();
 
	return 0;
}
