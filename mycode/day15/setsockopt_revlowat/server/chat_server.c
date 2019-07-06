#include <func.h>
int tcpInit(int*,char*,char*);
int main(int argc,char* argv[])
{
    ARGS_CHECK(argc,3);
    int socketFd;
    int ret=tcpInit(&socketFd,argv[1],argv[2]);
    if(ret==-1) {
        return -1;
    }
    int newFd;
    struct sockaddr_in client;
    bzero(&client,sizeof(client));
    socklen_t clientLen=sizeof(client);
    newFd=accept(socketFd,(struct sockaddr*)&client,&clientLen);
    ERROR_CHECK(newFd,-1,"accept");
    printf("clent ip=%s,clinet port=%d\n",inet_ntoa(client.sin_addr),ntohs(client.sin_port));
    char buf[128]={0};
    int epfd=epoll_create(1);
    struct epoll_event event,evs[2];
    event.events=EPOLLIN;
    event.data.fd=STDIN_FILENO;
    ret=epoll_ctl(epfd,EPOLL_CTL_ADD,STDIN_FILENO,&event);
    ERROR_CHECK(ret,-1,"epoll_ctl");

    int rcvLowAtVal=20;
    ret=setsockopt(newFd,SOL_SOCKET,SO_RCVLOWAT,&rcvLowAtVal,sizeof(int));
    ERROR_CHECK(ret,-1,"setsockopt");
    event.data.fd=newFd;
    ret=epoll_ctl(epfd,EPOLL_CTL_ADD,newFd,&event);
    ERROR_CHECK(ret,-1,"epoll_ctl");
    int readyFdCount,i;
    while(1) {
        readyFdCount=epoll_wait(epfd,evs,2,-1);
        for(i=0;i<readyFdCount;i++) {
            if(evs[i].events==EPOLLIN && evs[i].data.fd==STDIN_FILENO) {
                bzero(&buf,sizeof(buf));
                ret=read(STDIN_FILENO,buf,sizeof(buf));
                if(ret==0) {
                    printf("bye bye\n");
                    goto finish;
                }
                send(newFd,buf,strlen(buf)-1,0);
            }
            if(evs[i].data.fd==newFd) {
                bzero(buf,sizeof(buf));
                ret=recv(newFd,buf,sizeof(buf)-1,0);
                if(ret==0) {
                    printf("disconnect\n");
                    goto finish;
                }
                printf("From client: %s\n",buf);
            }
        }
    }
finish:
    close(newFd);
    close(socketFd);
    return 0;
}

