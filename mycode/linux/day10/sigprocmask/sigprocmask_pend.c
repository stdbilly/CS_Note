#include <func.h>

int main(int argc,char* argv[])
{
    sigset_t procMask;
    sigemptyset(&procMask);
    sigaddset(&procMask,SIGINT);
    int ret;
    ret=sigprocmask(SIG_BLOCK,&procMask,NULL);
    ERROR_CHECK(ret,-1,"sigprocmask");
    sleep(5);
    sigset_t pending;
    sigemptyset(&pending);
    sigpending(&pending);
    if(sigismember(&pending,SIGINT)) {
        printf("SIGINT is pending\n");
    } else {
        printf("SIGINT id not pending\n");
    }
    ret=sigprocmask(SIG_UNBLOCK,&procMask,NULL);
    ERROR_CHECK(ret,-1,"sigprocmask");
    return 0;
}

