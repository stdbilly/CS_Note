#include <func.h>

int main(int argc,char* argv[])
{
    pid_t pid,ppid;
    pid=getpid();
    ppid=getppid();
    printf("pid=%d ppid=%d\n",getpid(),getppid());
    while(1);
    return 0;
}

