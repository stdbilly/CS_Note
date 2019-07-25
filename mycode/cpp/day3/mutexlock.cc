#include "mutexcond.h"
#include <iostream>
using std::cout;
using std::endl;

class MutexLock {
    friend class Condition;
public:
    static MutexLock* getInstance(){
        if(_pInstance==nullptr){
            _pInstance=new MutexLock();
        }
        return _pInstance;
    }
    
    static void destroy(){
        if(_pInstance)
            delete _pInstance;
    }

    void lock(){
        pthread_mutex_lock(&_pInstance->_mutex);
    }

    void unlock(){
        pthread_mutex_unlock(&_pInstance->_mutex);
    }

    pthread_mutex_t* getMutex(){
        return &_pInstance->_mutex;
    }
private:
    MutexLock(){
        pthread_mutex_init(&_mutex,nullptr);
        cout<<"MutexLock()"<<endl;
    }

    ~MutexLock(){
        pthread_mutex_destroy(&_pInstance->_mutex);
        cout<<"~MutexLock()"<<endl;
    }
private:
    static MutexLock* _pInstance;
    pthread_mutex_t _mutex;
};

MutexLock* MutexLock::_pInstance=nullptr;

class Condition {
public:
    Condition(MutexLock& mutex):_mutex(mutex){
        pthread_cond_init(&_cond,nullptr);
        cout<<"Condition()"<<endl;
    }

    ~Condition(){
        pthread_cond_destroy(&_cond);
        cout<<"~Condition()"<<endl;
    }

    void wait(){
        _mutex.lock();
        pthread_cond_wait(&_cond,_mutex.getMutex());
        _mutex.unlock();
    }

    void notify(){
        pthread_cond_signal(&_cond);
    }

    void notifyall(){
        pthread_cond_broadcast(&_cond);
    }
private:
    pthread_cond_t _cond;
    MutexLock& _mutex;
};

void* threadFun(void* p){
    Condition* pCond=(Condition*)p;
    pCond->wait();
    cout<<"child thread wake up"<<endl;
    pthread_exit(nullptr);
}
void test1() {
    MutexLock* mutex = MutexLock::getInstance();
    Condition cond(*mutex);
    pthread_t pthid;
    pthread_create(&pthid,nullptr,threadFun,&cond);
    sleep(1);
    cond.notify();
    pthread_join(pthid,nullptr);
    cout<<"main thread"<<endl;
    MutexLock::destroy();
}
int main() {
    test1();
    return 0;
}

