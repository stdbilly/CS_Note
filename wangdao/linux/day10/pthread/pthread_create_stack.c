#include <func.h>
void* threadFunc(void* p)
{
    printf("I am child thread %d\n",*(int*)p);
}
int main(int argc,char* argv[])
{
    pthread_t pthid,pthid1;
    int ret;
    int val=1;
    ret=pthread_create(&pthid,NULL,threadFunc,&val);
    THREAD_ERROR_CHECK(ret,"pthread_create");
    val=2;
    ret=pthread_create(&pthid1,NULL,threadFunc,&val);
    THREAD_ERROR_CHECK(ret,"pthread_create");
    pthread_join(pthid,NULL);//等待子线程
    pthread_join(pthid1,NULL);//等待子线程
    printf("I am main thread\n");
    return 0;
}

