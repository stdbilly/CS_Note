#include <func.h>
long times=0;
void sigFunc(int signum) {
    time_t now;
    time(&now);
    printf("%s %ld\n",ctime(&now),times);
    times=0;
}
int main(int argc,char* argv[])
{
    signal(SIGVTALRM,sigFunc);
    struct itimerval t;
    bzero(&t,sizeof(t));
    t.it_value.tv_sec=3;
    t.it_interval.tv_sec=4;
    int ret;
    sigFunc(0);
    ret=setitimer(ITIMER_VIRTUAL,&t,NULL);
    ERROR_CHECK(ret,-1,"setitimer");
    sleep(5);
    double d,f;
    while(1) {
        f=3254674.76;
        d=5486.43*f;
        times++;
    }
    return 0;
}

