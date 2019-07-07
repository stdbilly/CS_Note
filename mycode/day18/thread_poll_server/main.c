#include "factory.h"

int main(int argc,char* argv[])
{
    if(argc!=5){
        printf("./thread_pool_server IP Port ThreadNum Capacity\n");
        return -1;
    }
    Factory_t threadInfo;
    int threadNum=atoi(argv[3]);
    int capacity=atoi(argv[4]);
    factoryInit(&threadInfo,threadNum,capacity);
    factoryStart(&threadInfo);
    int socketFd;
    tcpInit(&socketFd,argv[1],argv[2]);
    int clientFd;
    pQue_t pq=&threadInfo.que;
    pNode_t pNew;
    while(1){
        clientFd=accept(socketFd,NULL,NULL);
        pNew=(pNode_t)calloc(1,sizeof(Node_t));
        pNew->clientFd=clientFd;
        pthread_mutex_lock(&pq->mutex);
        queInsert(pq,pNew);
        pthread_mutex_unlock(&pq->mutex);
        pthread_cond_signal(&threadInfo.cond);
    }
    return 0;
}

