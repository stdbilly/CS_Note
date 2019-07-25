#include <func.h>
void* pthreadFunc(void* p1){
    time_t now;
    time(&now);
    char* p=ctime(&now);
    printf("child thread,time=%s\n",p);
    sleep(3);
    printf("child thread,time=%s\n",p);
}
int main(int argc,char* argv[])
{
    pthread_t pthid;
    int ret;
    ret=pthread_create(&pthid,NULL,pthreadFunc,NULL);
    THREAD_ERROR_CHECK(ret,"pthread_create");
    sleep(1);
    time_t now;
    time(&now);
    char* p=ctime(&now);
    printf("main thread,time=%s\n",p);
    ret=pthread_join(pthid,NULL);
    THREAD_ERROR_CHECK(ret,"pthread_join");
    return 0;
}

