#include "process_poll.h"
void sigFunc(int sigNum) {
    printf("%d is coming\n",sigNum);
}
int transFile(int clientFd)
{
    signal(SIGPIPE,sigFunc);
    fileInfo_t file;
    int ret;
    file.dataLen=strlen(FILENAME);
    strcpy(file.buf,FILENAME);
    send(clientFd,&file,4+file.dataLen,0);//发送文件名
    int fd=open(FILENAME,O_RDWR);
    struct stat buf;
    fstat(fd,&buf);//获取文件大小
    file.dataLen=sizeof(buf.st_size);
    memcpy(file.buf,&buf.st_size,file.dataLen);
    send(clientFd,&file,4+file.dataLen,0);//发送文件大小
    //发送文件内容，read读多少就发送多少
    char *pMap=(char*)mmap(NULL,buf.st_size,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    ERROR_CHECK(pMap,(char*)-1,"mmap");
    off_t sendSize=0;
    while(buf.st_size-sendSize>=1000) {
        file.dataLen=sizeof(file.buf);
        memcpy(file.buf,pMap+sendSize,file.dataLen);
        ret=send(clientFd,&file,4+file.dataLen,0);
        ERROR_CHECK(ret,-1,"send");
        sendSize+=1000;
    }
    file.dataLen=buf.st_size-sendSize;
    memcpy(file.buf,pMap+sendSize,file.dataLen);
    ret=send(clientFd,&file,4+file.dataLen,0);
    ERROR_CHECK(ret,-1,"send");
    send(clientFd,&file,4,0);//发送结束标志，此时file.dataLen=0
    return 0;
}

