#include <func.h>
#define MAP_HUGE_2MB 1<<21
int main(int argc,char* argv[])
{
    ARGS_CHECK(argc,2);
    int fd=open(argv[1],O_RDWR|O_CREAT,0666);
    ERROR_CHECK(fd,-1,"open");
    char *p=(char*)mmap(NULL,MAP_HUGE_2MB,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    ERROR_CHECK(p,(char*)-1,"mmap");
    strcpy(p,"hello");
    sleep(20);
    int ret=munmap(p,MAP_HUGE_2MB);
    ERROR_CHECK(ret,-1,"munmap");
    return 0;
}

