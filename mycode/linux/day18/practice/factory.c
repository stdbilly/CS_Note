#include "factory.h"

void* threadFunc(void *p){
    pFactory_t pf=(pFactory_t)p;
    pQue_t pq=&pf->que;
    pNode_t pGet;
    int getSuccess;
    while(1){
        pthread_mutex_lock(&pq->mutex);
        if(!pq->queSize){
            pthread_cond_wait(&pf->cond,&pq->mutex);
        }
        getSuccess=queGet(pq,&pGet);
        if(!getSuccess){
            transFile(pGet->clientFd);
            close(pGet->clientFd);
            free(pGet);
            pGet=NULL;
        }
    }
}

int factoryInit(pFactory_t pf,int threadNum,int capacity){
    queInit(&pf->que,capacity);
    pthread_cond_init(&pf->cond,NULL);
    pf->pthid=(pthread_t*)calloc(threadNum,sizeof(pthread_t));
    pf->threadNum=threadNum;
    pf->startFlag=0;
    return 0;
}

int factoryStart(pFactory_t pf){
    if(!pf->startFlag){
        int i;
        for(i=0;i<pf->threadNum;i++){
            pthread_create(pf->pthid+i,NULL,threadFunc,pf);
        }
        pf->startFlag=1;
    }
    return 0;
}
