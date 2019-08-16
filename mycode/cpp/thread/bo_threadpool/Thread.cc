#include "Thread.h"
#include <iostream>
using std::cout;
using std::endl;

namespace wd{
void Thread::start() {
    pthread_create(&_pthid, nullptr, threadFunc, this);
    _isRunning = true;
} 

void* Thread::threadFunc(void* arg) {
    Thread* pthread = static_cast<Thread*>(arg);
    if(pthread) {
        pthread->_cb(); //执行任务
    }
    return nullptr;
}

void Thread::join(){
    if(_isRunning) {
        pthread_join(_pthid, nullptr);
        _isRunning = false;
    }
}

Thread::~Thread() {
    if(_isRunning) {
        pthread_detach(_pthid);
    }
    cout << "~Thread()" << endl;
}

}
