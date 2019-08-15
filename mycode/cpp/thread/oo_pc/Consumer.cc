#include "Consumer.h"
#include <iostream>
#include "TaskQueue.h"
using std::cout;
using std::endl;

namespace wd {
Consumer::Consumer(TaskQueue& taskque) : _taskQue(taskque) {}

void Consumer::run() {
    int cnt = 20;
    while (cnt--) {
        int num = _taskQue.pop();
        cout << "consumer thread " << pthread_self() << " num = " << num
             << endl;
    }
}
}  // namespace wd