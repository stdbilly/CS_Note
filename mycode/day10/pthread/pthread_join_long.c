#include <func.h>
void* threadFun(void *p) {
    printf("child thread,%ld\n",(long)p);
    pthread_exit((void*)2);
}
int main(int argc,char* argv[])
{
    pthread_t pthid;
    int ret;
    long val=1;
    ret=pthread_create(&pthid,NULL,threadFun,(void*)val);
    THREAD_ERROR_CHECK(ret,"pthread_create");
    long threadRet;//不能用int,否则访问越界
    ret=pthread_join(pthid,(void**)&threadRet);
    THREAD_ERROR_CHECK(ret,"pthread_join");
    printf("main thread,child thread returns %ld\n",threadRet);
    return 0;
}

