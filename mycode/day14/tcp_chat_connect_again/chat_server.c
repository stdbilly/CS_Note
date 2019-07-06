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
    int ret=bind(socketFd,(struct sockaddr*)&serAddr,sizeof(serAddr));
    ERROR_CHECK(ret,-1,"bind");
    listen(socketFd,10);
    struct sockaddr_in client;
    bzero(&client,sizeof(client));
    socklen_t clientLen=sizeof(client);
    int newFd=accept(socketFd,(struct sockaddr*)&client,&clientLen);
    printf("clent ip=%s,clinet port=%d\n",inet_ntoa(client.sin_addr),ntohs(client.sin_port));
    char buf[1024]={0};

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

