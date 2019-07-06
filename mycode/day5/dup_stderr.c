#include <func.h>

int main(int argc,char* argv[])
{
    ARGS_CHECK(argc,2);
    int fd,fd2;
    fd=open(argv[1],O_RDWR|O_CREAT,0666);
    ERROR_CHECK(fd,-1,"open");
    close(STDERR_FILENO);
    fd2=dup(fd);
    close(fd);
    printf("fd2=%d\n",fd2);
    perror("stderr to log2\n");
    return 0;
}

