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
    //发送文件内容
    char *pMap=(char*)mmap(NULL,buf.st_size,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    ERROR_CHECK(pMap,(char*)-1,"mmap");
    ret=send(clientFd,pMap,buf.st_size,0);
    ERROR_CHECK(ret,-1,"send");
    munmap(pMap,buf.st_size);
    //send(clientFd,&file,4,0);//可以不发结束符
    return 0;
}

