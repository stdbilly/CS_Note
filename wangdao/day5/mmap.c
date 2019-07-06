#include <func.h>

int main(int argc,char* argv[])
{
    ARGS_CHECK(argc,2);
    int fd=open(argv[1],O_RDWR);
    ERROR_CHECK(fd,-1,"open");
    char *p=(char*)mmap(NULL,5,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    ERROR_CHECK(p,(char*)-1,"mmap");
    printf("%s\n",p);
    strcpy(p,"how");
    int ret=munmap(p,5);
    ERROR_CHECK(ret,-1,"munmap");
    return 0;
}

