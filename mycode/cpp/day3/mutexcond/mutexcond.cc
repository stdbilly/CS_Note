#include "mutexcond.h"

MutexLock* MutexLock:: getInstance(){
    if(_pInstance==nullptr){
        _pInstance=new MutexLock();
    }
    return _pInstance;
}

void MutexLock:: destroy(){
    if(_pInstance){
        delete _pInstance;
        _pInstance=nullptr;
        cout<<"destroy"<<endl;
    }
}

void MutexLock::lock(){
    pthread_mutex_lock(&_pInstance->_mutex);
}

void MutexLock::unlock(){
    pthread_mutex_unlock(&_pInstance->_mutex);
}

pthread_mutex_t& MutexLock::getMutex(){
    return _pInstance->_mutex;
}
MutexLock::MutexLock(){
    pthread_mutex_init(&_mutex,nullptr);
    cout<<"MutexLock()"<<endl;
}

MutexLock::~MutexLock(){
    pthread_mutex_destroy(&_mutex);
    cout<<"~MutexLock()"<<endl;
}

MutexLock* MutexLock::_pInstance=nullptr;

Condition::Condition(MutexLock& mutex):_mutex(mutex){
    pthread_cond_init(&_cond,nullptr);
    cout<<"Condition(MutexLock&)"<<endl;
}

Condition* Condition:: getInstance(MutexLock& mutex){
    if(_pInstance==nullptr){
        _pInstance=new Condition(mutex);
    }
    return _pInstance;
}

void Condition:: destroy(){
    if(_pInstance){
        delete _pInstance;
        _pInstance=nullptr;
        cout<<"destroy"<<endl;
    }
}

Condition::~Condition(){
    pthread_cond_destroy(&_cond);
    cout<<"~Condition()"<<endl;
}

void Condition::wait(){
    pthread_cond_wait(&_pInstance->_cond,&_pInstance->_mutex.getMutex());
}

void Condition::notify(){
    pthread_cond_signal(&_pInstance->_cond);
}

void Condition::notifyall(){
    pthread_cond_broadcast(&_pInstance->_cond);
}

Condition* Condition::_pInstance=nullptr;

