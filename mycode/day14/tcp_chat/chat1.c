#include <func.h>
int tcpInit(int*,char*,char*);
int main(int argc,char* argv[])
{
    ARGS_CHECK(argc,3);
    fd_set rdset;
    int socketFd;
    tcpInit(&socketFd,argv[1],argv[2]);
    int newFd=accept(socketFd,NULL,NULL);
    char buf[1024]={0};
    int ret;

    while(1) {
        FD_ZERO(&rdset);
        FD_SET(STDIN_FILENO,&rdset);
        FD_SET(newFd,&rdset);
        ret=select(newFd+1,&rdset,NULL,NULL,NULL);
        if(ret>0) {
            if(FD_ISSET(STDIN_FILENO,&rdset)) {
                bzero(&buf,sizeof(buf));
                read(STDIN_FILENO,buf,sizeof(buf));
                send(newFd,buf,strlen(buf),0);
            }
            if(FD_ISSET(newFd,&rdset)) {
                bzero(&buf,sizeof(buf));
                ret=recv(newFd,buf,sizeof(buf),0);
                if(ret==-1) {
                    printf("disconnect\n");
                    break;
                }
                if(*buf){
                    printf("From client: %s\n",buf);
                }
            }
        }
    }
    close(socketFd);
    close(newFd);
    return 0;
}

