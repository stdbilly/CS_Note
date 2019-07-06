#include <func.h>
struct msgbuf{
    long mtype;
    char mtext[256];
};
int msgid;
void sigFunc(int signum) {
    msgctl(msgid,IPC_RMID,NULL);
    printf("clean success,exit\n");
    exit(0);
}
int main(int argc,char* argv[])
{
    ARGS_CHECK(argc,3);
    int fdw=open(argv[1],O_WRONLY);//1号管道
    int fdr=open(argv[2],O_RDONLY);//2号管道
    msgid=msgget(1000,IPC_CREAT|0600);
    ERROR_CHECK(msgid,-1,"msgget");
    struct msgbuf msgInfo;
    msgInfo.mtype=1;
    int ret;
    char buf[256]={0};
    fd_set rdset;
    signal(SIGINT,sigFunc);
    while(1)
    {
        FD_ZERO(&rdset);
        FD_SET(STDIN_FILENO,&rdset);
        FD_SET(fdr,&rdset);
        ret=select(fdr+1,&rdset,NULL,NULL,NULL);//rdset是传入传出参数
        if(FD_ISSET(STDIN_FILENO,&rdset))
        {
            memset(buf,0,sizeof(buf));
            read(STDIN_FILENO,buf,sizeof(buf));
            write(fdw,buf,strlen(buf)-1);
        }
        if(FD_ISSET(fdr,&rdset))
        {
            memset(buf,0,sizeof(buf));
            ret=read(fdr,buf,sizeof(buf));
            if(0==ret)
            {
                printf("byebye\n");
                sigFunc(0);
                break;
            }
            strcpy(msgInfo.mtext,buf);
            ret=msgsnd(msgid,&msgInfo,strlen(msgInfo.mtext),0);
            ERROR_CHECK(ret,-1,"msgsnd");
        }
    }
    close(fdr);
    close(fdw);
    return 0;
}

