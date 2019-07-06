#include <func.h>

int main(int argc,char* argv[])
{
    printf("pid=%d,ppid=%d,uid=%d,gid=%d,euid=%d,egid=%d\n",getpid(),getppid(),getuid(),getgid(),geteuid(),getegid());    
    return 0;
}

