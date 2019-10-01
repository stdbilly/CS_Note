 ///
 /// @file    Producer.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-08-15 14:35:18
 ///
 
#pragma once

#include "TaskQueue.h"

#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include <iostream>
using std::cout;
using std::endl;

namespace wd
{

class Producer
{
public:
	void produce(TaskQueue & taskque) 
	{
		::srand(::clock());
		int cnt = 20;

		while(cnt--) {
			int number = ::rand() % 100;
			taskque.push(number);

			cout << ">> producer thread " << pthread_self() 
				 << " produc a number = " << number << endl;
			//::sleep(1);
		}
	}
};
 
}//end of namespace wd
