#include "MutexCond.h"
#include <unistd.h>
#include <iostream>
using std::cout;
using std::endl;
using namespace lock;

class Data{
public:
    Data(MutexLock& mutex,Condition& cond,int tickets=20)
    :_tickets(tickets),
    _mutex(mutex),
    _cond(cond){}

    bool haveTickets(){
        return _tickets>0 ;
    }

    void saleTickets(){
        _tickets--;
    }

    void setTickets(int x){
        _tickets=x;
    }

    int getTickets(){
        return _tickets;
    }

public:
    MutexLock& _mutex;
    Condition& _cond;
private:
    int _tickets;
};

void* threadFun(void* p){
    Data* pArg=(Data*)p;
        MutexLockGuard autolock(pArg->_mutex);
    pArg->_cond.wait();
    cout<<"child thread wake up"<<endl;
    pthread_exit(nullptr);
}
void test1() {
    cout<<"test1()"<<endl;
    MutexLock* mutex = MutexLock::getInstance();
    Condition* cond = Condition::getInstance(*mutex);
    Data threadInfo(*mutex,*cond);
    cout<<"mutex:"<<mutex<<endl
        <<"cond:"<<cond<<endl;
    cout<<"threadInfo._mutex:"<<&threadInfo._mutex<<endl
        <<"threadInfo._cond:"<<&threadInfo._cond<<endl;
    pthread_t pthid;
    pthread_create(&pthid,nullptr,threadFun,&threadInfo);
    sleep(1);
    cond->notify();
    pthread_join(pthid,nullptr);
    cout<<"main thread"<<endl;
    MutexLock::destroy();
    Condition::destroy();
}

void* saleWindows1(void* p)
{
    Data* pArg=(Data*)p;
    int i=0;
    while(1)
    {
        MutexLockGuard autolock(pArg->_mutex);
        if(pArg->haveTickets())
        {
            cout<<"I am saleWindows1 start sale,"<<pArg->getTickets()<<endl;
            pArg->saleTickets();
            i++;
            if(!pArg->haveTickets())
            {
                pArg->_cond.notify();
            }
            cout<<"I am saleWindows1 sale finish,"<<pArg->getTickets()<<endl;
            sleep(1);
        }else{
            cout<<"I am saleWindows1,"<<i<<endl;
            break;
        }
    }
    return nullptr;
}
void* saleWindows2(void* p)
{
    Data* pArg=(Data*)p;
    int i=0;
    while(1)
    {
        MutexLockGuard autolock(pArg->_mutex);
        if(pArg->haveTickets())
        {
            cout<<"I am saleWindows2 start sale,"<<pArg->getTickets()<<endl;
            pArg->saleTickets();
            i++;
            if(!pArg->haveTickets())
            {
                pArg->_cond.notify();
            }
            cout<<"I am saleWindows2 sale finish,"<<pArg->getTickets()<<endl;
            sleep(1);
        }else{
            cout<<"I am saleWindows2,"<<i<<endl;
            break;
        }
    }
    return nullptr;
}
void* setTickets(void* p)
{
    Data* pArg=(Data*)p;
        MutexLockGuard autolock(pArg->_mutex);
    if(pArg->haveTickets())
    {
        pArg->_cond.wait();
    }
    pArg->setTickets(20);
    return nullptr;
}

void test2() {
    cout<<"test2()"<<endl;
    MutexLock* mutex = MutexLock::getInstance();
    Condition* cond=Condition::getInstance(*mutex);
    Data threadInfo(*mutex,*cond);
    cout<<"mutex:"<<mutex<<endl
        <<"cond:"<<cond<<endl;
    cout<<"threadInfo._mutex:"<<&threadInfo._mutex<<endl
        <<"threadInfo._cond:"<<&threadInfo._cond<<endl;
    pthread_t pthid,pthid1,pthid2;
    pthread_create(&pthid,nullptr,saleWindows1,&threadInfo);
    pthread_create(&pthid1,nullptr,saleWindows2,&threadInfo);
    pthread_create(&pthid2,nullptr,setTickets,&threadInfo);
    pthread_join(pthid,nullptr);
    pthread_join(pthid1,nullptr);
    pthread_join(pthid2,nullptr);
    cout<<"sale over"<<endl;
    MutexLock::destroy();
    Condition::destroy();
}

int main() {
    test1();
    cout<<endl;
    test2();
    return 0;
}

