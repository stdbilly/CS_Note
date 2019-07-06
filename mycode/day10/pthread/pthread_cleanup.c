#include <func.h>
void cleanup(void *p) {
    free(p);
    printf("free success\n");
}
void* threadFunc(void *p) {
    p=malloc(20);
    pthread_cleanup_push(cleanup,p);
    read(STDIN_FILENO,p,sizeof(p));
    sleep(1);
    printf("child thread\n");
    pthread_cleanup_pop(1);
    return NULL;
}
int main(int argc,char* argv[])
{
    pthread_t pthid;
    int ret;
    ret=pthread_create(&pthid,NULL,threadFunc,NULL);
    THREAD_ERROR_CHECK(ret,"pthread_create");
    ret=pthread_cancel(pthid);
    THREAD_ERROR_CHECK(ret,"pthread_cancle");
    long threadRet;
    ret=pthread_join(pthid,(void**)&threadRet);
    THREAD_ERROR_CHECK(ret,"pthread_join");
    printf("main thread %ld\n",threadRet);
    return 0;
}

