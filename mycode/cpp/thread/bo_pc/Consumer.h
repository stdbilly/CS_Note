#pragma once
#include "Thread.h"
#include "TaskQueue.h"

namespace wd {
class Consumer {
public:
    void consume(TaskQueue& taskque) {
        int cnt = 20;
        while (cnt--) {
            int num = taskque.pop();
            cout << "consumer thread " << pthread_self() << " num = " << num
                << endl;
        }
    }
};
}
