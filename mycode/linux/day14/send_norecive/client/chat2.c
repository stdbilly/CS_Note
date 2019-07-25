#include <func.h>
int setNonblock(int);
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
    char buf[1000]={0};
    int ret=connect(socketFd,(struct sockaddr*)&serAddr,sizeof(serAddr));
    ERROR_CHECK(ret,-1,"connect");
    setNonblock(socketFd);
    int total=0;
    while(1) {
        ret=send(socketFd,buf,sizeof(buf),0);
        if(ret==-1) {
            break;
        }
        total+=ret;
        printf("ret=%d,total=%d\n",ret,total);
   }
    close(socketFd);
    return 0;
}

