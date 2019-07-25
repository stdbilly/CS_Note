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
    char buf[1024]={0};
    int ret=connect(socketFd,(struct sockaddr*)&serAddr,sizeof(serAddr));
    ERROR_CHECK(ret,-1,"connect");
    int epfd=epoll_create(1);
    struct epoll_event event,evs[2];
    event.events=EPOLLIN;
    event.data.fd=STDIN_FILENO;
    epoll_ctl(epfd,EPOLL_CTL_ADD,STDIN_FILENO,&event);
    event.data.fd=socketFd;
    epoll_ctl(epfd,EPOLL_CTL_ADD,socketFd,&event);
    int readyFdCount,i;
    while(1) {
        readyFdCount=epoll_wait(epfd,evs,2,-1);
        for(i=0;i<readyFdCount;i++) {
            if(evs[i].events==EPOLLIN && evs[i].data.fd==STDIN_FILENO) {
                bzero(&buf,sizeof(buf));
                ret=read(STDIN_FILENO,buf,sizeof(buf));
                if(ret==0) {
                    printf("bye bye\n");
                    break;
                }
                send(socketFd,buf,strlen(buf)-1,0);
            }
            if(evs[i].data.fd==socketFd) {
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

