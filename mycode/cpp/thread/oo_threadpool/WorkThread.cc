#include <iostream>
#include "WorkThread.h"
#include "Threadpool.h"
using std::cout;
using std::endl;

namespace wd {
WorkThread::WorkThread(Threadpool& threadpool) 
: _threadpool(threadpool) {
    cout << "WorkThread(Threadpool&)" << endl;
}

WorkThread::~WorkThread() {
    cout << "~WorkThread()" << endl;
}

void WorkThread::run() {
    _threadpool.threadFunc();
}
}
