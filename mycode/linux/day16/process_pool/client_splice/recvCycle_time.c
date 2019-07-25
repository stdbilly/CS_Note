#include <func.h>

int recvCycle_time(int sfd,void* buf,int recvLen)
{
    char *p=(char*)buf;
    int ret,total=0;
    time_t lastTime,nowTime;
    lastTime=nowTime=time(NULL);
    struct timeval start,end;
    gettimeofday(&start,NULL);
    while(total<recvLen) {
        ret=recv(sfd,p+total,recvLen-total,0);
        ERROR_CHECK(ret,-1,"recv");
        time(&nowTime);
        total+=ret;
        if(nowTime-lastTime>=1) {
            printf("%5.2f%%\r",(float)total/recvLen*100);
            fflush(stdout);
            lastTime=nowTime;
        }
    }
    printf("100.00%%\n");
    gettimeofday(&end,NULL);
    printf("use time=%ld\n",(end.tv_sec-start.tv_sec)*1000000+end.tv_usec-start.tv_usec);
    return 0;
}

