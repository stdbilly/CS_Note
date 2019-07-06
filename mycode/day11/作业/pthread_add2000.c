#include <func.h>
#define N 20000000
typedef struct {
    int val;
    pthread_mutex_t mutex;
}Data_t;
void* threadFunc(void* p)
{
    int i;
    Data_t *pVal=(Data_t*)p;
    for(i=0;i<N;i++)
    {
        pthread_mutex_lock(&pVal->mutex);
        pVal->val+=1;
        pthread_mutex_unlock(&pVal->mutex);
    }
}
int main(int argc,char* argv[])
{
    pthread_t pthid;
    int ret;
    Data_t threadInfo;
    threadInfo.val=0;
    ret=pthread_mutex_init(&threadInfo.mutex,NULL);
    THREAD_ERROR_CHECK(ret,"pthread_mutex_init");
    ret=pthread_create(&pthid,NULL,threadFunc,&threadInfo);
    THREAD_ERROR_CHECK(ret,"pthread_create");
    int i;
    for(i=0;i<N;i++)
    {
        pthread_mutex_lock(&threadInfo.mutex);
        threadInfo.val+=1;
        pthread_mutex_unlock(&threadInfo.mutex);
    }
    pthread_join(pthid,NULL);//等待子线程
    printf("I am main thread,val=%d\n",threadInfo.val);
    return 0;
}

