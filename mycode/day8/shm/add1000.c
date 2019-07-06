#include <func.h>

int main(int argc,char* argv[])
{
    int shmid;
    shmid=shmget(1000,1<20,IPC_CREAT|0600);
    ERROR_CHECK(shmid,-1,"shmget");
    int *p;
    p=(int*)shmat(shmid,NULL,0);
    ERROR_CHECK(p,(int*)-1,"shmat");
    if(!fork()) {
        printf("child process,%d\n",*p);
    } else {
        *p=10;
        wait(NULL);
    }
    return 0;
}

