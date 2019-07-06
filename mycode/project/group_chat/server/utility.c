#include <func.h>
#include "utility.h"

int tcpInit(int *sfd,char* ip,char* port)
{
    int socketFd=socket(AF_INET,SOCK_STREAM,0);
    ERROR_CHECK(socketFd,-1,"socket");
    struct sockaddr_in serAddr;
    bzero(&serAddr,sizeof(serAddr));
    serAddr.sin_family=AF_INET;
    serAddr.sin_port=htons(atoi(port));
    serAddr.sin_addr.s_addr=inet_addr(ip);
    int ret,reuse=1;
    ret=setsockopt(socketFd,SOL_SOCKET,SO_REUSEADDR,&reuse,sizeof(int));
    ERROR_CHECK(ret,-1,"setsockopt");
    ret=bind(socketFd,(struct sockaddr*)&serAddr,sizeof(serAddr));
    ERROR_CHECK(ret,-1,"bind");
    listen(socketFd,10);
    *sfd=socketFd;
    return 0;
}

int setNonblock(int fd)
{
    int status;
    status=fcntl(fd,F_GETFL);
    status=status|O_NONBLOCK;
    fcntl(fd,F_SETFL,status);
    return 0;
}

int addEpfd(int epfd,int fd) {
    int ret;
    struct epoll_event event;
    event.events=EPOLLIN;
    event.data.fd=fd;
    ret=epoll_ctl(epfd,EPOLL_CTL_ADD,fd,&event);
    ERROR_CHECK(ret,-1,"epoll_ctl");
    setNonblock(fd);
    return 0;
}

void addClient(pClientList_t *ppHead,pClientList_t *ppTail,ClientList_t cl) {
    pClientList_t pNew=(pClientList_t)calloc(1,sizeof(ClientList_t));
    *pNew=cl;
    if(*ppHead==NULL) {
        *ppHead=pNew;
        *ppTail=pNew;
    } else {
        (*ppTail)->pNext=pNew;
        *ppTail=pNew;
    }
    (*ppTail)->pNext=NULL;
}

int sendBroadcastmessage(pClientList_t pClient,pClientList_t *ppHead,pClientList_t *ppTail) {
    char message[BUF_SIZE],buf[BUF_SIZE];
    pClientList_t pCur=*ppHead;
    int ret;
    bzero(buf,BUF_SIZE);
    bzero(message,BUF_SIZE);
    printf("read from client(clientIp=%s)\n",pClient->ip);
    ret=recv(pClient->clientFd,buf,BUF_SIZE,0);
    if(ret==0) {
        close(pClient->clientFd);
        printf("clientIp=%s exit\n",pClient->ip);
        removeClient(pClient,ppHead,ppTail);
    }else{
        if(*ppHead==*ppTail && *ppHead!=NULL) {
            send(pClient->clientFd,CAUTION,strlen(CAUTION),0);
            return 0;
        }
        sprintf(message,SERVER_MESSAGE,pClient->name,buf);
        while(pCur!=NULL) {
            if(pCur->clientFd!=pClient->clientFd){
                ret=send(pCur->clientFd,message,strlen(message),0);
                ERROR_CHECK(ret,-1,"send");
            }
            pCur=pCur->pNext;
        }
    }
    return 0;
}

pClientList_t findClient(int clientFd,pClientList_t pHead){
    pClientList_t pCur=pHead;
    if(pCur->clientFd==clientFd) {
        return pCur;
    }else{
        while(pCur) {
            if(pCur->clientFd==clientFd) {
                break;
            }
            pCur=pCur->pNext;
        }
    }
    return pCur;
}

int removeClient(pClientList_t pClient,pClientList_t *ppHead,pClientList_t *ppTail) {
    pClientList_t pCur=*ppHead,pPre;
    pPre=pCur;
    if(pCur==pClient) {
        *ppHead=pCur->pNext;
        if(*ppHead==NULL) {
            *ppTail=NULL;
        }
    }else {
        while(pCur){
            if(pCur==pClient) {
                pPre->pNext=pCur->pNext;
                break;
            }
            pPre=pCur;
            pCur=pCur->pNext;
        }
        if(pCur==*ppTail) {
            *ppTail=pPre;
            (*ppTail)->pNext=NULL;
        }
    }
    free(pCur);
    pCur=NULL;
    return  0;
}
