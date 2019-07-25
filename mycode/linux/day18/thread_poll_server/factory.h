#ifndef __FACTORY_H__
#define __FACTORY_H__
#include "work_que.h"

typedef struct{
    Que_t que;
    pthread_t *pthid;//存储线程ID的起始地址
    pthread_cond_t cond;
    int threadNum;
    short startFlag;//线程池是否启动
}Factory_t,*pFactory_t;

int factoryInit(pFactory_t,int,int);
int factoryStart(pFactory_t);
int tcpInit(int *sfd,char* ip,char* port);
int transFile(int clientFd);
#endif
