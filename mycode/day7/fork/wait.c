#include <func.h>

int main(int argc,char* argv[])
{
    if(!fork()) {
        printf("child process,pid=%d\n",getpid());
        return 1;
    } else {
        int status;
        pid_t pid;
        pid=wait(&status);
        printf("child pid=%d\n",pid);
        if(WIFEXITED(status)) {
            printf("exit code=%d\n",WEXITSTATUS(status));
        } else {
            printf("child crash\n");
        }
        return 0;
    }
}

