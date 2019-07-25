#include <func.h>
#define N 20000000

int val=0;
pthread_mutex_t mutex;

void* threadFunc(void* p) {
    int i;
    for(i=0;i<N;i++) {
        pthread_mutex_lock(&mutex);
        val++;
        pthread_mutex_unlock(&mutex);
    }
}
int main(int argc,char* argv[])
{
    pthread_t pthid;
    int ret;
    ret=pthread_mutex_init(&mutex,NULL);
    THREAD_ERROR_CHECK(ret,"pthread_mutex_init");
    ret=pthread_create(&pthid,NULL,threadFunc,NULL);
    THREAD_ERROR_CHECK(ret,"pthread_create");
    int i;
    for(i=0;i<N;i++) {
        pthread_mutex_lock(&mutex);
        val++;
        pthread_mutex_unlock(&mutex);
    }
    ret=pthread_join(pthid,NULL);
    THREAD_ERROR_CHECK(ret,"pthread_join");
    printf("main thread,val=%d\n",val);
    return 0;
}

