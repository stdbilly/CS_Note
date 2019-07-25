#include <func.h>
int tcpInit(int*,char*,char*);
int main(int argc,char* argv[])
{
    ARGS_CHECK(argc,3);
    fd_set rdset,moniterFd;
    int socketFd;
    tcpInit(&socketFd,argv[1],argv[2]);
    int newFd;
    char buf[1024]={0};
    int ret;
    struct sockaddr_in client;                                                                                                                                                            
    bzero(&client,sizeof(client));
    socklen_t clientLen=sizeof(client);
    FD_ZERO(&moniterFd);
    FD_SET(STDIN_FILENO,&moniterFd);
    FD_SET(socketFd,&moniterFd);
    while(1) {
        memcpy(&rdset,&moniterFd,sizeof(fd_set));
        ret=select(13,&rdset,NULL,NULL,NULL);
        if(ret>0) {
            if(FD_ISSET(socketFd,&rdset)) {
                newFd=accept(socketFd,(struct sockaddr*)&client,&clientLen);
                ERROR_CHECK(newFd,-1,"accept");
                FD_SET(newFd,&moniterFd);
                printf("clent ip=%s,clinet port=%d\n",inet_ntoa(client.sin_addr),ntohs(client.sin_port));
            }
            if(FD_ISSET(STDIN_FILENO,&rdset)) {
                bzero(&buf,sizeof(buf));
                ret=read(STDIN_FILENO,buf,sizeof(buf));
                if(ret==0) {
                    printf("bye bye\n");
                    break;
                }
                send(newFd,buf,strlen(buf)-1,0);
            }
            if(FD_ISSET(newFd,&rdset)) {
                bzero(&buf,sizeof(buf));
                ret=recv(newFd,buf,sizeof(buf),0);
                if(ret==0) {
                    printf("disconnect\n");
                    FD_CLR(newFd,&moniterFd);
                    close(newFd);
                }
                printf("From client: %s\n",buf);
            }
        }
    }
    close(socketFd);
    return 0;
}

