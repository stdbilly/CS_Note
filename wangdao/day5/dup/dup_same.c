#include <func.h>

int main(int argc,char* argv[])
{
    ARGS_CHECK(argc,2);
    int fd,fd1;
    fd=open(argv[1],O_RDWR);
    ERROR_CHECK(fd,-1,"open");
    fd1=dup(fd);//文件描述符的复制
    printf("fd=%d,fd1=%d\n",fd,fd1);
    lseek(fd,5,SEEK_SET);
    char buf[128]={0};
    int ret=read(fd1,buf,sizeof(buf));
    ERROR_CHECK(ret,-1,"read");
    printf("buf=%s\n",buf);
    return 0;
}

