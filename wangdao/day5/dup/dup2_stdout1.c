#include <func.h>
//重定向标准输出
int main(int argc,char* argv[])
{
    ARGS_CHECK(argc,2);
    int fd,fd1;
    fd=open(argv[1],O_RDWR);
    ERROR_CHECK(fd,-1,"open");
    printf("\n");
    dup2(1,100);
    fd1=dup2(fd,1);//文件描述符的复制
    close(fd);
    printf("fd1=%d\n",fd1);//不会输出到屏幕上
    printf("you can't see me\n");
    dup2(100,1);
    printf("you can see me\n");
    return 0;
}

