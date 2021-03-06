#include <func.h>

int main(int argc,char* argv[])
{
    ARGS_CHECK(argc,3);
    int fdw=open(argv[1],O_WRONLY);//1号管道
    int fdr=open(argv[2],O_RDONLY);//2号管道
    printf("I am chat2 fdr=%d fdw=%d\n",fdr,fdw);
    char buf[128]={0};
    fd_set rdset;
    int ret;
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
                 break;
             }
             printf("%s\n",buf);
        }
    }
    return 0;
}

