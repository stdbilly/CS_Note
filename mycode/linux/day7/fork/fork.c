#include <func.h>

int main(int argc,char* argv[])
{
    pid_t pid;
    pid=fork();
    if(pid==0) {
        printf("child process,pid=%d,ppid=%d\n",getpid(),getppid());
        while(1);
    } else {
        printf("parent process,pid=%d,childid=%d\n",getpid(),pid);
        while(1);
    }
    return 0;
}

