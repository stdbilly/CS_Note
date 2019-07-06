#ifndef __WORK_QUE_H__
#define __WORK_QUE_H__
#include "head.h"

typedef struct node{
    int clientFd;
    struct node* pNext;
}Node_t,*pNode_t;

typedef struct {
    pNode_t queHead,queTail;
    int queCapacity;
    int queSize;
    pthread_mutex_t mutex;
}Que_t,*pQue_t;

void queInit(pQue_t,int);
void queInsert(pQue_t,pNode_t);
void queGet(pQue_t,pNode_t*);
#endif
