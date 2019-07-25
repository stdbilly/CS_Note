#include <func.h>

int main(int argc,char* argv[])
{
    if(!fork()) {
        printf("child process,pid=%d\n",getpid());
        while(1);
    } else {
        return 0;
    }
}

