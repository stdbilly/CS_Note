#include <func.h>

int main(int argc,char* argv[])
{
    int fds[2];
    pipe(fds);
    if(!fork()) {
        close(fds[0]);//关闭读端，因为子进程要写
        write(fds[1],"hello",5);
        exit(0);
    } else {
        close(fds[1]);//关闭写端，因为父进程要读
        char buf[128]={0};
        read(fds[0],buf,sizeof(buf));
        printf("I'm parent,gets=%s\n",buf);
        wait(NULL);
    }
    return 0;
}

