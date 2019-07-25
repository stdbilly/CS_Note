#include <func.h>

int main(int argc,char* argv[])
{
    pid_t pid;
    int iStack=10;
    pid=fork();
    if(0==pid)
    {
        printf("I am child mypid=%d,myppid=%d,iStack=%d, %p\n",getpid(),getppid(),iStack,&iStack);
    }else{
        printf("I am parent mypid=%d,mychildpid=%d,iStack=%d\n",getpid(),pid,iStack);
        iStack=5;
        printf("I am parent after modify %d, %p\n",iStack,&iStack);
        sleep(1);
    }
    return 0;
}

