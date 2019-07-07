#define _GNU_SOURCE
#include <func.h>
int recvCycle(int sfd,void* buf,int recvLen);
int recvCycle_time(int sfd,void* buf,int recvLen);
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
    int ret=connect(socketFd,(struct sockaddr*)&serAddr,sizeof(serAddr));
    ERROR_CHECK(ret,-1,"connect");
    int fd;
    int dataLen;
    char buf[1000]={0};
    recvCycle(socketFd,&dataLen,4);
    recvCycle(socketFd,buf,dataLen);//接收文件名
    fd=open(buf,O_RDWR|O_CREAT,0666);
    ERROR_CHECK(fd,-1,"open");
    //接收文件大小
    off_t fileSize,download=0,lastDownload=0,slice;
    recvCycle(socketFd,&dataLen,4);
    recvCycle(socketFd,&fileSize,dataLen);
    printf("fileSize=%ld\n",fileSize);
    int fds[2];
    pipe(fds);
    struct timeval start,end;
    gettimeofday(&start,NULL);
    slice=fileSize/1000;
    while(download<fileSize) {
        ret=splice(socketFd,NULL,fds[1],NULL,65536,SPLICE_F_MOVE|SPLICE_F_MORE);
        if(ret==0) {
            break;
        }
        ERROR_CHECK(ret,-1,"splice");
        splice(fds[0],NULL,fd,NULL,ret,SPLICE_F_MOVE|SPLICE_F_MORE);
        download+=ret;
        if(download-lastDownload>=slice) {
            printf("%5.2f%%\r",(float)download/fileSize*100);
            fflush(stdout);
            lastDownload=download;
        }
    }
    if(download==fileSize) {
        printf("100.00%%\n");
    }
    gettimeofday(&end,NULL);
    printf("use time=%ld\n",(end.tv_sec-start.tv_sec)*1000000+end.tv_usec-start.tv_usec);
    close(fd);
    close(socketFd);
    return 0;
}

