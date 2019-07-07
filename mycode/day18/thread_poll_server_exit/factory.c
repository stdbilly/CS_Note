#include "factory.h"

void cleanUp(void *p) {
    pthread_mutex_unlock((pthread_mutex_t*)p);
    //printf("clean success\n");
}
void* threadFunc(void *p) {
    pFactory_t pthreadInfo=(pFactory_t)p;
    pQue_t pq=&pthreadInfo->que;
    pNode_t pGet;
    int getTaskSuccess;
    while(1){
        pthread_mutex_lock(&pq->mutex);
        pthread_cleanup_push(cleanUp,&pq->mutex);
        if(!pq->queSize){
            pthread_cond_wait(&pthreadInfo->cond,&pq->mutex);
        }
        getTaskSuccess=queGet(pq,&pGet);//拿任务
        pthread_cleanup_pop(1);
        if(!getTaskSuccess){
           transFile(pGet->clientFd);
           free(pGet);
           pGet=NULL;
        }
    }
}
int factoryInit(pFactory_t p,int threadNum,int capacity)
{
    queInit(&p->que,capacity);
    pthread_cond_init(&p->cond,NULL);
    p->pthid=(pthread_t*)calloc(threadNum,sizeof(pthread_t));
    p->threadNum=threadNum;
    p->startFlag=0;
    return 0;
}

int factoryStart(pFactory_t p) {
    if(!p->startFlag){
        int i;
        for(i=0;i<p->threadNum;i++) {
            pthread_create(p->pthid+i,NULL,threadFunc,p);
        }
        p->startFlag=1;
    }
    return 0;
}
