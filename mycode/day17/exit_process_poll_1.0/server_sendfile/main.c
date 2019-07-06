#include "process_poll.h"
int exitFds[2];
void sigExitFunc(int sigNum) {
    write(exitFds[1],&sigNum,1);
}
int main(int argc,char* argv[])
{
    if(argc!=4) {
        printf("./process_poll_server ip port process_num\n");
        return -1;
    }    
    int processNum=atoi(argv[3]);
    process_data_t *pData=(process_data_t*)calloc(processNum,sizeof(process_data_t));
    makeChild(pData,processNum);//创建子进程
    //退出机制
    pipe(exitFds);
    signal(SIGUSR1,sigExitFunc);
    int i;
#ifdef DEBUG
    for(i=0;i<processNum;i++) {
        printf("pid=%d pipeFd=%d\n",pData[i].pid,pData[i].pipeFd);
    }
#endif
    int socketFd,clientFd;
    tcpInit(&socketFd,argv[1],argv[2]);
    int epfd=epoll_create(1);
    struct epoll_event *evs=(struct epoll_event*)calloc(processNum+1,sizeof(struct epoll_event));
    epollAdd(epfd,socketFd);
    epollAdd(epfd,exitFds[0]);
    for(i=0;i<processNum;i++) {
        epollAdd(epfd,pData[i].pipeFd);//注册监控每个子进程的管道对端
    }
    int finishFlag,readyFdCount,j;
    while(1) {
        readyFdCount=epoll_wait(epfd,evs,processNum+1,-1);
        for(i=0;i<readyFdCount;i++) {

            if(evs[i].data.fd==exitFds[0]){
                for(j=0;j<processNum;j++){
                    kill(pData[j].pid,SIGUSR1);
                }
                for(j=0;j<processNum;j++){
                    wait(NULL);
                }
                printf("exit success\n");
                exit(0);
            }

            if(evs[i].data.fd==socketFd) {
                clientFd=accept(socketFd,NULL,NULL);
                for(j=0;j<processNum;j++) {//找非忙碌的的子进程
                    if(pData[j].busy==0) {
                        sendFd(pData[j].pipeFd,clientFd);//把clientFd发送给子进程
                        //子进程收到clienFd后，clienFd的引用计数变为2，父进程一定要close(clienFd),
                        //确保子进程给clienFd发送完以后，能够正常close(clienFd)
                        pData[j].busy=1;//子进程标识为忙碌
                        printf("%d(pid) is busy\n",pData[j].pid);
                        break;
                    }
                }
                close(clientFd);
            }
            
            for(j=0;j<processNum;j++) {
                if(evs[i].data.fd==pData[j].pipeFd) {
                    read(pData[j].pipeFd,&finishFlag,1);//收到子进程发送完成的通知
                    pData[j].busy=0;//子进程设置为非忙碌
                    printf("%d(pid) is not busy\n",pData[j].pid);
                    break;
                }
            }

        }
    }
    return 0;
}

