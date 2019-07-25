#include <func.h>
void Daemon() {
    int i,fd;
    if(fork())
        exit(0);
    setsid();
    chdir("/tmp");
    umask(0);
    fd=open("log",O_RDWR|O_CREAT,0666);
    while(1) {
        sleep(60);
        write(fd,"wohenshuai\n",11);
    }
    for(i=0;i<4;i++) {
        close(i);
    }
}
int main(int argc,char* argv[])
{
    Daemon();
    return 0;
}

