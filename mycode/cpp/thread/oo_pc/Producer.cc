#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <iostream>
#include "Produceer.h"
#include "TaskQueue.h"
using std::cout;
using std::endl;

namespace wd {
Producer::Producer(TaskQueue& taskque) : _taskQue(taskque) {}

void Producer::run() {
    int cnt = 20;
    ::srand(::clock());
    while (cnt--) {
        int num = ::rand() % 100;
        _taskQue.push(num);
        cout << "producer thread " << pthread_self() << " num = " << num
             << endl;
        ::sleep(1);
    }
}
}  // namespace wd