#include <func.h>

int main(int argc,char* argv[])
{
    pid_t pid;
    pid=fork();
    if(!pid)
    {
        printf("I am child %d\n",getpid());
        sleep(10);
        return 1;
    }else{
        int status;
        pid_t childPid;
        childPid=waitpid(pid,&status,0);
        printf("I am parent child pid=%d\n",pid);
        if(WIFEXITED(status))
        {
            printf("exit code=%d\n",WEXITSTATUS(status));
        }else{
            printf("child crash\n");
        }
        return 0;
    }
}

