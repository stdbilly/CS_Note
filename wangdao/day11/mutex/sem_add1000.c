#include <func.h>
#define N 20000000
int main(int argc,char* argv[])
{
    int semArrId=semget(1000,1,IPC_CREAT|0600);
    ERROR_CHECK(semArrId,-1,"semget");                                                                                    
    int shmid;
    shmid=shmget(1000,1<<20,IPC_CREAT|0600);
    ERROR_CHECK(shmid,-1,"shmget");
    int *p;
    p=(int*)shmat(shmid,NULL,0);
    ERROR_CHECK(p,(int*)-1,"shmat");
    *p=0;
    int ret=semctl(semArrId,0,SETVAL,1);
    ERROR_CHECK(ret,-1,"semctl");
    struct sembuf sopp,sopv;
    sopp.sem_num=0;
    sopp.sem_op=-1;
    sopp.sem_flg=SEM_UNDO;
    sopv.sem_num=0;
    sopv.sem_op=1;
    sopv.sem_flg=SEM_UNDO;
    struct timeval start,end;
    gettimeofday(&start,NULL);
    if(!fork())
    {
        int i;
        for(i=0;i<N;i++)
        {
            //加锁
            semop(semArrId,&sopp,1);
            p[0]=p[0]+1;
            semop(semArrId,&sopv,1);
            //解锁
        }
    }else{
        int i;
        for(i=0;i<N;i++)
        {
            semop(semArrId,&sopp,1);
            p[0]=p[0]+1;
            semop(semArrId,&sopv,1);
        }
        wait(NULL);
        gettimeofday(&end,NULL);
        printf("result=%d,use time=%ld\n",p[0],(end.tv_sec-start.tv_sec)*1000000+end.tv_usec-start.tv_usec);
    }
    return 0;
}

