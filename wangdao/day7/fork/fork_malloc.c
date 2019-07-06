#include <func.h>

int main(int argc,char* argv[])
{
    pid_t pid;
    char *pMalloc=(char*)malloc(20);
    strcpy(pMalloc,"hello");
    pid=fork();
    if(0==pid)
    {
        printf("I am child mypid=%d,myppid=%d,%s, %p\n",getpid(),getppid(),pMalloc,pMalloc);
    }else{
        printf("I am parent mypid=%d,mychildpid=%d,%s\n",getpid(),pid,pMalloc);
        pMalloc[0]='H';
        printf("I am parent after modify %s, %p\n",pMalloc,pMalloc);
        sleep(1);
    }
    return 0;
}

