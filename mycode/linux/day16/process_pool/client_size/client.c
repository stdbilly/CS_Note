#include <func.h>
int recvCycle(int sfd,void* buf,int recvLen);
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
    off_t fileSize,downloadSize=0,lastDownload=0,slice;
    recvCycle(socketFd,&dataLen,4);
    recvCycle(socketFd,&fileSize,dataLen);
    slice=fileSize/1000;
    struct timeval start,end;
    gettimeofday(&start,NULL);
    while(1) {//接收文件内容
        recvCycle(socketFd,&dataLen,4);//接收文件内容长度
        if(dataLen>0) {
            recvCycle(socketFd,buf,dataLen);
            write(fd,buf,dataLen);
            downloadSize+=dataLen;
            if(downloadSize-lastDownload>=slice) {
                printf("%5.2f%%\r",(float)downloadSize/fileSize*100);
                fflush(stdout);
                lastDownload=downloadSize;
            }
        }else{
            printf("100.00%%\n");
            break;//接收到dataLen=0,接收完成
        }
    }
    gettimeofday(&end,NULL);
    printf("use time=%ld\n",(end.tv_sec-start.tv_sec)*1000000+end.tv_usec-start.tv_usec);
    close(fd);
    close(socketFd);
    return 0;
}

