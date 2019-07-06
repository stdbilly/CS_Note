#include <func.h>

int main(int argc,char* argv[])
{
    int fds[2];
    pipe(fds);//管道的读端就存在fds[0],写端存在fds[1]
    if(!fork())
    {
        close(fds[1]);//关闭写端因为子进程要读
        char buf[128]={0};
        read(fds[0],buf,sizeof(buf));
        printf("I am child,gets=%s\n",buf);
        exit(0);
    }else{
        close(fds[0]);//关闭读端，因为父进程要写
        write(fds[1],"I hen niu",9);
        wait(NULL);
    }
    return 0;
}

