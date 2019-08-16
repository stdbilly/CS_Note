#include "Threadpool.h"
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <memory>
using std::unique_ptr;
using std::cout;
using std::endl;
using namespace wd;

class MyTask {
public:
    void process() {
        ::srand(::clock());
        //::srand(::time(nullptr));
        int num = rand() % 100;
        cout << "sub thread " << pthread_self() << " num = " << num << endl;
        //sleep(1);
    }
};

int main() {
    Threadpool threadpool(4, 10);
    threadpool.start();
    unique_ptr<MyTask> task(new MyTask());
    int cnt = 20;
    while(cnt--) {
        threadpool.addTask(std::bind(&MyTask::process, task.get()));
        cout << "main thread :cnt = " << cnt << endl;
    }

    threadpool.stop();
    return 0;
}

