#include <func.h>

void* threadFunc(void* p1)
{
    time_t now;
    time(&now);
    char *p=ctime(&now);
    printf("I am child thread p=%s\n",p);
    sleep(3);
    printf("I am child thread p=%s\n",p);
}
int main(int argc,char* argv[])
{
    pthread_t pthid;
    pthread_create(&pthid,NULL,threadFunc,NULL);
    sleep(1);
    time_t now;
    time(&now);
    char *p=ctime(&now);
    printf("I am main thread p=%s\n",p);
    pthread_join(pthid,NULL);
    return 0;
}

