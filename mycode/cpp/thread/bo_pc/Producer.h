#pragma once
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <iostream>
#include "TaskQueue.h"
using std::cout;
using std::endl;
#include "Thread.h"

namespace wd {
class TaskQueue;

class Producer {
public:
    void produce(TaskQueue& taskque) {
        int cnt = 20;
        ::srand(::clock());
        while (cnt--) {
            int num = ::rand() % 100;
            taskque.push(num);
            cout << "producer thread " << pthread_self() << " num = " << num
                << endl;
            ::sleep(1);
        }
    }
};
}
