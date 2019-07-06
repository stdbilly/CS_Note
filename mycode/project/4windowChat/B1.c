#include <func.h>
struct msgbuf{
    long mtype;
    char mtext[256];
};
int main(int argc,char* argv[])
{
    int msgid=msgget(1000,IPC_CREAT|0600);
    ERROR_CHECK(msgid,-1,"msgget");
    struct msgbuf msgInfo;
    while(1) {
        bzero(&msgInfo,sizeof(msgInfo));
        int ret=msgrcv(msgid,&msgInfo,sizeof(msgInfo.mtext),0,0);
        ERROR_CHECK(ret,-1,"msgrcv");
        if(msgInfo.mtext){
            printf("from A: %s\n",msgInfo.mtext);
        }
    }
    return 0;
}

