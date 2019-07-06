#include <func.h>
void* threadFunc(void* p) {
    printf("child thread\n");
}
int main(int argc,char* argv[])
{
    pthread_t pthid;
    int ret;
    ret=pthread_create(&pthid,NULL,threadFunc,NULL);
    ERROR_CHECK(ret,-1,"pthread_create");
    usleep(1);
    printf("main thread\n");
    return 0;
}

