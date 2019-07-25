#ifndef __FACTORY_H__
#define __FACTORY_H__
#include "work_que.h"

typedef struct{
    Que_t que;
    int threadNum;//线程数目
    pthread_t* pthid;//线程ID的起始地址
    pthread_cond_t cond;
    short startFlag;//线程池启动标志，1启动
}Factory_t,*pFactory_t;

int factoryInit(pFactory_t pf,int threadNum,int capacity);
int factoryStart(pFactory_t pf);
int tcpInit(int *sfd,char* ip,char* port);
int transFile(int clientFd);
#endif
