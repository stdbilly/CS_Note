#include <func.h>

int main(int argc,char* argv[])
{
    ARGS_CHECK(argc,2);
    int fd,fd1;
    fd=open(argv[1],O_RDWR|O_CREAT,0666);
    ERROR_CHECK(fd,-1,"open");
    close(STDOUT_FILENO);
    fd1=dup(fd);
    close(fd);
    printf("fd1=%d\n",fd1);
    printf("stdout to log1\n");
    return 0;
}

