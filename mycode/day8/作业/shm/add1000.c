#include <func.h>
#define N 10000000
int main(int argc,char* argv[])
{
    int shmid;
    shmid=shmget(1000,1<<20,IPC_CREAT|0600);
    ERROR_CHECK(shmid,-1,"shmget");
    int *p=(int*)shmat(shmid,NULL,0);
    ERROR_CHECK(p,(int*)-1,"shmat");
    *p=0;
    if(!fork()) {
        int i;
        for(i=0;i<N;i++) {
            *p=*p+1;
        }
    } else {
        int i;
        for(i=0;i<N;i++) {
            *p=*p+1;
        }
        wait(NULL);
        printf("result=%d\n",*p);
    }
    return 0;
}

