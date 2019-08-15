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

class Mythread : public Thread {
    void run() override {
        ::srand(::clock());
        while(1) {
            int num = rand() % 100;
            cout << "num = " << num << endl;
            ::sleep(1);
        }
    }
};

int main() {
    unique_ptr<Thread> thread(new Mythread());
    thread->start();
    thread->join();
    return 0;
}

