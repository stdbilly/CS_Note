#include <func.h>
typedef struct {
    int tickets;
    pthread_mutex_t mutex;
}Data_t;

void* cleanup(void *p) {
    pthread_mutex_unlock((pthread_mutex_t*)p);
    printf("unlock success\n");
}

void* saleWindow1(void *p) {
    Data_t* pArg=(Data_t*)p;
    int i=0;
    while(1) {
        pthread_mutex_lock(&pArg->mutex);
        if(pArg->tickets>0) {
            //printf("Sales window1 start sale\n");
            pArg->tickets--;
            i++;
            pthread_mutex_unlock(&pArg->mutex);
        } else {
            pthread_mutex_unlock(&pArg->mutex);
            printf("Sale window1, %d\n",i);
            break;
        }
    }
    return NULL;
}

void* saleWindow2(void *p) {
    Data_t* pArg=(Data_t*)p;
    int i=0;
    while(1) {
        pthread_mutex_lock(&pArg->mutex);
        if(pArg->tickets>0) {
            //printf("saleWindow2les window1 start sale\n");
            pArg->tickets--;
            i++;
            pthread_mutex_unlock(&pArg->mutex);
        } else {
            pthread_mutex_unlock(&pArg->mutex);
            printf("sale Window2, %d\n",i);
            break;
        }
    }
    return NULL;
}

int main(int argc,char* argv[])
{
    Data_t threadInfo;
    threadInfo.tickets=20000000;
    pthread_t pthid,pthid1;
    pthread_mutex_init(&threadInfo.mutex,NULL);
    pthread_create(&pthid,NULL,saleWindow1,&threadInfo);
    pthread_create(&pthid1,NULL,saleWindow2,&threadInfo);
    int ret;
    long threadRet;
    ret=pthread_join(pthid1,(void**)&threadRet);
    THREAD_ERROR_CHECK(ret,"pthread_join");
    ret=pthread_join(pthid,(void**)&threadRet);
    THREAD_ERROR_CHECK(ret,"pthread_join");
    printf("sales over\n");
    return 0;
}

