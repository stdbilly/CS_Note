#include <func.h>
#define N 2
typedef struct{
    pthread_mutex_t mutex;
    pthread_cond_t cond;
}Data_t,*pData_t;

void cleanup(void *p) {
    pthread_mutex_unlock((pthread_mutex_t*)p);
    printf("unlock success\n");
}

void* threadFunc(void *p) {
    pData_t pArg=(pData_t)p;
    pthread_mutex_lock(&pArg->mutex);
    pthread_cleanup_push(cleanup,&pArg->mutex);
    pthread_cond_wait(&pArg->cond,&pArg->mutex);
    printf("wait return\n");
    pthread_cleanup_pop(1);
    printf("child thread weak up\n");
    pthread_exit(NULL);
}
int main(int argc,char* argv[])
{
    Data_t threadInfo;
    pthread_mutex_init(&threadInfo.mutex,NULL);
    pthread_cond_init(&threadInfo.cond,NULL);
    pthread_t pthid[N];
    int i;
    for(i=0;i<N;i++) {
        pthread_create(pthid+i,NULL,threadFunc,&threadInfo);
    }
    int ret;
    for(i=0;i<N;i++) {
        ret=pthread_cancel(pthid[i]);
        THREAD_ERROR_CHECK(ret,"pthread_cancel");
    }
    for(i=0;i<N;i++) {
        ret=pthread_join(pthid[i],NULL);
        THREAD_ERROR_CHECK(ret,"pthread_join");
    }
    printf("main thread\n");
    return 0;
}

