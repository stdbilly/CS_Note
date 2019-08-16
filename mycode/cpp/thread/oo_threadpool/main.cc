#include "Threadpool.h"
#include "Task.h"
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <memory>
using std::unique_ptr;
using std::cout;
using std::endl;
using namespace wd;

class MyTask : public Task {
public:
    void process() override {
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
    unique_ptr<Task> task(new MyTask());
    //Task* task = new MyTask();
    int cnt = 20;
    while(cnt--) {
        threadpool.addTask(task.get());
        cout << "main thread :cnt = " << cnt << endl;
    }

    threadpool.stop();
    //这里要显式的stop，虽然析构函数也会调用stop(),但是析构函数是在mian()之后执行的，
    //此时task对象已经被销毁了，子线程无法正常执行，core dump
    return 0;
}

