#include <func.h>
typedef struct{
    int tickets;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
}Data_t,*pData_t;

void cleanup(void *p)                                                                                                                                                               
{
    pthread_mutex_unlock((pthread_mutex_t*)p);
    printf("unlock success\n");
}

void* saleWindow1(void* p)
{
    pData_t pArg=(pData_t)p;
    int i=0;
    while(1)
    {
        pthread_mutex_lock(&pArg->mutex);
        if(pArg->tickets>0)
        {
            printf("sale Window1 start sale,%d\n",pArg->tickets);
            pArg->tickets--;
            i++;
            if(!pArg->tickets) {
                pthread_cond_signal(&pArg->cond);
            }
            printf("sale Window1 sale finish,%d\n",pArg->tickets);
            pthread_mutex_unlock(&pArg->mutex);
            sleep(1);
        }else{
            pthread_mutex_unlock(&pArg->mutex);
            printf("sale Window1,%d\n",i);
            break;
        }
    }
    return NULL;
}
void* saleWindow2(void* p)
{
    pData_t pArg=(pData_t)p;
    int i=0;
    while(1)
    {
        pthread_mutex_lock(&pArg->mutex);
        if(pArg->tickets>0)
        {
            printf("sale Window2 start sale,%d\n",pArg->tickets);
            pArg->tickets--;
            i++;
            if(!pArg->tickets) {
                pthread_cond_signal(&pArg->cond);
            }
            printf("sale Window2 sale finish,%d\n",pArg->tickets);
            pthread_mutex_unlock(&pArg->mutex);
            sleep(1);
        }else{
            pthread_mutex_unlock(&pArg->mutex);
            printf("sale Window2,%d\n",i);
            break;
        }
    }
    return NULL;
}

void* settickets(void *p) {
    pData_t pArg=(pData_t)p;
    pthread_mutex_lock(&pArg->mutex);
    if(pArg->tickets>0) {
        pthread_cond_wait(&pArg->cond,&pArg->mutex);
    }
    pArg->tickets=20;
    pthread_mutex_unlock(&pArg->mutex);
}
int main(int argc,char* argv[])
{
    Data_t threadInfo;
    threadInfo.tickets=20;
    pthread_t pthid,pthid1,pthid2;
    pthread_mutex_init(&threadInfo.mutex,NULL);
    pthread_cond_init(&threadInfo.cond,NULL);
    pthread_create(&pthid,NULL,saleWindow1,&threadInfo);
    pthread_create(&pthid1,NULL,saleWindow2,&threadInfo);
    pthread_create(&pthid2,NULL,settickets,&threadInfo);
    int ret; 
    long threadRet;
    ret=pthread_join(pthid1,(void**)&threadRet);
    THREAD_ERROR_CHECK(ret,"pthread_join");
    ret=pthread_join(pthid,(void**)&threadRet);
    THREAD_ERROR_CHECK(ret,"pthread_join");
    printf("sale over\n");
    return 0;
}

