#include <func.h>

int main(int argc,char* argv[])
{
    pid_t pid;
    pid=fork();
    if(0==pid)
    {
        printf("I am child mypid=%d,myppid=%d\n",getpid(),getppid());
    }else{
        printf("I am parent mypid=%d,mychildpid=%d\n",getpid(),pid);
        sleep(1);
    }
    return 0;
}

