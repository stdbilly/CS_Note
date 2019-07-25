#include <func.h>

int main(int argc,char* argv[])
{
    ARGS_CHECK(argc,3);
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
    recv(newFd,buf,sizeof(buf),0);
    printf("From client: %s\n",buf);
    send(newFd,"Hi I'm server",13,0);
    //while(1);
    close(socketFd);
    close(newFd);
    return 0;
}

