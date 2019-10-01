 ///
 /// @file    TestPC.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-08-15 14:34:23
 ///
 
#include "Thread.h"
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
	
	unique_ptr<Thread> producer(new Thread(
		std::bind(&Producer::produce,Producer(), std::ref(taskque))			
	));

	unique_ptr<Thread> consumer(new Thread(
		std::bind(&Consumer::consume,Consumer(), std::ref(taskque))			
	));

	producer->start();
	consumer->start();
	producer->join();
	consumer->join();
	
	return 0;
}

