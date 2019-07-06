#include <func.h>
int tcpInit(int*,char*,char*);
int main(int argc,char* argv[])
{
    ARGS_CHECK(argc,3);
    int socketFd;
    tcpInit(&socketFd,argv[1],argv[2]);
    int newFd=accept(socketFd,NULL,NULL);
    printf("newFd=%d\n",newFd);
    char buf[10]={0};
    read(STDIN_FILENO,buf,sizeof(buf));
    return 0;
}
