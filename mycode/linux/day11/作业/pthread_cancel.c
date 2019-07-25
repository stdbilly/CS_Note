#include <func.h>
void cleanup(void* p) {
    free(p);
    printf("free success\n");
}
void* threadFunc(void* p) {
    p=(char*)malloc(20);
    pthread_cleanup_push(cleanup,p);
    read(STDIN_FILENO,p,sizeof(p));
    printf("you can't see me\n");
    pthread_cleanup_pop(1);
    pthread_exit(NULL);
}
int main(int argc,char* argv[])
{
    pthread_t pthid;
    int ret;
    ret=pthread_create(&pthid,NULL,threadFunc,NULL);
    THREAD_ERROR_CHECK(ret,"pthread_create");
    ret=pthread_cancel(pthid);
    THREAD_ERROR_CHECK(ret,"pthread_cancel");
    long threadRet;
    ret=pthread_join(pthid,(void**)&threadRet);
    THREAD_ERROR_CHECK(ret,"pthread_join");
    printf("main thread,%ld\n",threadRet);
    return 0;
}

