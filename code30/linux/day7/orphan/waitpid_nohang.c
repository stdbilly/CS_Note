#include <func.h>

int main(int argc,char* argv[])
{
    pid_t pid;
    pid=fork();
    if(!pid)
    {
        printf("I am child %d\n",getpid());
        return 1;
    }else{
        int status;
        pid_t childPid;
        sleep(1);
        childPid=waitpid(pid,&status,WNOHANG);
        printf("I am parent child pid=%d\n",childPid);
        if(childPid>0)
        {
            if(WIFEXITED(status))
            {
                printf("exit code=%d\n",WEXITSTATUS(status));
            }else{
                printf("child crash\n");
            }
        }
        return 0;
    }
}

