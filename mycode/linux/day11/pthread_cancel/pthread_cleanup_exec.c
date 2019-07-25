#include <func.h>
void cleanup(void* p){
    printf("clceanup %ld\n",(long)p);
}
void* threadFunc(void *p) {
    pthread_cleanup_push(cleanup,(void*)1);
    pthread_cleanup_push(cleanup,(void*)2);
    pthread_exit(NULL);
    pthread_cleanup_pop(1);
    pthread_cleanup_pop(1);
}
int main(int argc,char* argv[])
{
    pthread_t pthid;
    pthread_create(&pthid,NULL,threadFunc,NULL);
    long threadRet;
    int ret=pthread_join(pthid,(void**)&threadRet);
    THREAD_ERROR_CHECK(ret,"pthread_join");
    printf("threadRet=%ld\n",threadRet);
    return 0;
}

