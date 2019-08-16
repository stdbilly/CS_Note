#pragma once
#include "Thread.h"
#include <iostream>
using std::cout;
using std::endl;

namespace wd {
class Threadpool;

class WorkThread : public Thread {
public:
    WorkThread(Threadpool& threadpool);
    ~WorkThread();

private:
    void run();
    Threadpool& _threadpool;
};
}

