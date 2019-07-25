#include <func.h>

int main(int argc,char* argv[])
{
    pid_t pid;
    char *p=(char*)malloc(20);
    strcpy(p,"hello");
    pid=fork();
    if(pid==0) {
        printf("I'm child,mypid=%d,myppid=%d,%s,  %p\n",getpid(),getppid(),p,p);
    } else {
        printf("I'm parent,mypid=%d,mychildpid=%d,%s\n",getpid(),pid,p);
        p[0]='H';
        printf("I'm parent after modify %s,  %p\n",p,p);
        sleep(1);
    }
    return 0;
}

