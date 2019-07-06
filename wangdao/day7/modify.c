#include <func.h>

int main(int argc,char* argv[])
{
    printf("uid=%d,gid=%d,euid=%d,egid=%d",getuid(),getgid(),geteuid(),getegid());
    int fd=open("file",O_RDWR|O_CREAT);
    ERROR_CHECK(fd,-1,"open");
    write(fd,"hello",5);
    close(fd);
    return 0;
}

