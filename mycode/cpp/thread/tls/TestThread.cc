#include "Thread.h"
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <memory>
using std::unique_ptr;
using std::cout;
using std::endl;
using namespace wd;

class Task {
public:
    void run() {
        ::srand(::clock());
        while(1) {
            int num = ::rand() % 100;
            cout << "num = " << num << endl;
            ::sleep(1);
        }
    }
};

void process() {
    ::srand(::clock());
    while(1) {
        int num = ::rand() % 100;
        cout << "sub thread " << current_thread::threadName << " num = " << num << endl;
        ::sleep(1);
    }
}

int main() {
    //unique_ptr<Thread> thread(new Thread(std::bind(&Task::run, Task())));
    current_thread::threadName = "main thread";
    cout << current_thread::threadName << endl;
    unique_ptr<Thread> thread(new Thread((process), "1"));
    thread->start();
    thread->join();
    return 0;
}

