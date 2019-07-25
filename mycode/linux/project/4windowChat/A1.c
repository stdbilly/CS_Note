#include <func.h>

int main(int argc,char* argv[])
{
    int shmid;
    char buf[256]={0};
    shmid=shmget(1000,1<<20,IPC_CREAT|0600);
    ERROR_CHECK(shmid,-1,"shmget");
    char *p=(char*)shmat(shmid,NULL,0);
    ERROR_CHECK(p,(char*)-1,"shmat");
    while(1) {
        if(strcmp(buf,p)) {
            strcpy(buf,p);
            printf("from B: %s\n",buf);
        }
    }
    int ret;
    ret=shmctl(shmid,IPC_RMID,NULL);
    ERROR_CHECK(ret,-1,"shmctl");
    return 0;
}

