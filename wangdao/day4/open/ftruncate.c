#include <func.h>

int main(int argc,char* argv[])
{
    ARGS_CHECK(argc,2);
    int fd;
    fd=open(argv[1],O_RDWR);
    ERROR_CHECK(fd,-1,"open");
    printf("fd=%d\n",fd);
    int ret=ftruncate(fd,3);
    ERROR_CHECK(ret,-1,"ftruncate");
    close(fd);
    return 0;
}

