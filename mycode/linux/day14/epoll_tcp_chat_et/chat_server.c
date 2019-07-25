#include <func.h>
int tcpInit(int*,char*,char*);
int setNonblock(int);
int main(int argc,char* argv[])
{
    ARGS_CHECK(argc,3);
    int socketFd;
    int ret=tcpInit(&socketFd,argv[1],argv[2]);
    if(ret==-1) {
        return -1;
    }
    struct sockaddr_in client;
    int newFd;
    char buf[10]={0};
    int epfd=epoll_create(1);
    struct epoll_event event,evs[3];
    event.events=EPOLLIN;
    event.data.fd=STDIN_FILENO;
    ret=epoll_ctl(epfd,EPOLL_CTL_ADD,STDIN_FILENO,&event);
    ERROR_CHECK(ret,-1,"epoll_ctl");
    event.data.fd=socketFd;
    ret=epoll_ctl(epfd,EPOLL_CTL_ADD,socketFd,&event);
    ERROR_CHECK(ret,-1,"epoll_ctl");
    int readyFdCount,i;
    while(1) {
        readyFdCount=epoll_wait(epfd,evs,3,-1);
        for(i=0;i<readyFdCount;i++) {
            if(evs[i].data.fd==socketFd) {
                bzero(&client,sizeof(client));
                socklen_t clientLen=sizeof(client);
                newFd=accept(socketFd,(struct sockaddr*)&client,&clientLen);
                ERROR_CHECK(newFd,-1,"accept");
                printf("clent ip=%s,clinet port=%d\n",inet_ntoa(client.sin_addr),ntohs(client.sin_port));
                setNonblock(newFd);
                event.events=EPOLLIN|EPOLLET;
                event.data.fd=newFd;
                ret=epoll_ctl(epfd,EPOLL_CTL_ADD,newFd,&event);
                ERROR_CHECK(ret,-1,"epoll_ctl");
            }
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
                while(1) {
                    bzero(buf,sizeof(buf));
                    ret=recv(newFd,buf,sizeof(buf)-1,0);
                    if(ret==0) {
                        printf("disconnect\n");
                        event.data.fd=newFd;
                        ret=epoll_ctl(epfd,EPOLL_CTL_DEL,newFd,&event);
                        close(newFd);
                        break;
                    }else if(ret==-1) {
                        break;
                    }else {
                        printf("%s",buf);
                    }
                }   
                printf("\n");
            }
        }
    }
finish:
    close(socketFd);
    return 0;
}

