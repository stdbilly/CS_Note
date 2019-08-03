#include <func.h>

int main()
{
    printf("Parent process id:%d\n",getpid());
    pid_t iRet=fork();
    if(iRet<0) {
        printf("Creat child process failed\n");
    }else if(iRet==0) {
        printf("Child process id:%d,Parent process id:%d\n",getpid(),getppid());
    }else {
        printf("parent process sucess,child id:%d\n",iRet);
    }
    return 0;
}

