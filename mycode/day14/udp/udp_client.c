#include <func.h>

int main(int argc,char* argv[])
{
    ARGS_CHECK(argc,3);
    int socketFd=socket(AF_INET,SOCK_DGRAM,0);
    ERROR_CHECK(socketFd,-1,"socket");
    struct sockaddr_in serAddr;
    bzero(&serAddr,sizeof(serAddr));
    serAddr.sin_family=AF_INET;
    serAddr.sin_port=htons(atoi(argv[2]));
    serAddr.sin_addr.s_addr=inet_addr(argv[1]);
    char buf[1024]={0};
    sendto(socketFd,"Hi I'm client",13,0,(struct sockaddr*)&serAddr,sizeof(serAddr));
    recvfrom(socketFd,buf,sizeof(buf),0,NULL,NULL);
    printf("From server: %s\n",buf);
    close(socketFd);
    return 0;
}

