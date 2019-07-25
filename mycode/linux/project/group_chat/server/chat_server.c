#include "utility.h"

int main(int argc,char* argv[])
{
    if(argc!=3) {
        printf("./server ip(192.168.5.171) port(2000)\n");
    }
    int socketFd;
    int ret; 
    ret=tcpInit(&socketFd,argv[1],argv[2]);
    if(ret==-1) {
        return -1;
    }
    struct sockaddr_in client;
    ClientList_t cl;
    pClientList_t pHead=NULL,pTail=NULL,pRet;
    int clientFd;
    char buf[1024]={0};
    int epfd=epoll_create(1);
    struct epoll_event evs[EPOLL_SIZE];
    addEpfd(epfd,socketFd);
    int readyFdCount,i;
    while(1) {
        readyFdCount=epoll_wait(epfd,evs,EPOLL_SIZE,-1);
        for(i=0;i<readyFdCount;i++) {
            if(evs[i].data.fd==socketFd) {
                bzero(&client,sizeof(client));
                socklen_t clientLen=sizeof(client);
                clientFd=accept(socketFd,(struct sockaddr*)&client,&clientLen);
                ERROR_CHECK(clientFd,-1,"accept");

                cl.clientFd=clientFd;
                strcpy(cl.ip,inet_ntoa(client.sin_addr));
                cl.port=ntohs(client.sin_port);
                printf("clent ip=%s,clinet port=%d\n",cl.ip,cl.port);
                send(clientFd,SERVER_WELCOME,sizeof(SERVER_WELCOME),0);
                ret=recv(clientFd,buf,sizeof(buf),0);
                if(ret==0) {
                    break;
                }
                strcpy(cl.name,buf);
                send(clientFd,"username saved",14,0);

                addEpfd(epfd,clientFd);
                addClient(&pHead,&pTail,cl);
            }else{
                pRet=findClient(evs[i].data.fd,pHead); 
                sendBroadcastmessage(pRet,&pHead,&pTail);
            }

        }
    }
    close(socketFd);
    return 0;
}

