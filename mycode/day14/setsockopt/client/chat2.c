#include <func.h>

int main(int argc,char* argv[])
{
    ARGS_CHECK(argc,3);
    fd_set rdset;
    int socketFd=socket(AF_INET,SOCK_STREAM,0);
    ERROR_CHECK(socketFd,-1,"socket");
    struct sockaddr_in serAddr;
    bzero(&serAddr,sizeof(serAddr));
    serAddr.sin_family=AF_INET;
    serAddr.sin_port=htons(atoi(argv[2]));
    serAddr.sin_addr.s_addr=inet_addr(argv[1]);
    char buf[1024]={0};
    int ret=connect(socketFd,(struct sockaddr*)&serAddr,sizeof(serAddr));
    ERROR_CHECK(ret,-1,"connect");
                 
    while(1) {
        FD_ZERO(&rdset);
        FD_SET(STDIN_FILENO,&rdset);
        FD_SET(socketFd,&rdset);
        ret=select(socketFd+1,&rdset,NULL,NULL,NULL);
        if(ret>0) {
            if(FD_ISSET(STDIN_FILENO,&rdset)) {
                bzero(&buf,sizeof(buf));
                ret=read(STDIN_FILENO,buf,sizeof(buf));
                if(ret==0) {
                    printf("bye bye\n");
                    break;
                }
                send(socketFd,buf,strlen(buf)-1,0);
            }
            if(FD_ISSET(socketFd,&rdset)) {
                bzero(&buf,sizeof(buf));
                ret=recv(socketFd,buf,sizeof(buf),0);
                if(ret==0) {
                    printf("disconnect\n");
                    break;
                }
             printf("From server: %s\n",buf);
            }
        }
    }
    close(socketFd);
    return 0;
}

