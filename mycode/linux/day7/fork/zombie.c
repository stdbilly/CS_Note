#include <func.h>

int main(int argc,char* argv[])
{
    if(!fork()) {
        printf("child process,pid=%d\n",getpid());
    } else {
        while(1);
        return 0;
    }
}

