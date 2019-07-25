#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/select.h>
#include <sys/time.h>
#include <strings.h>
#include <syslog.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/msg.h>
#include <errno.h>
#include <signal.h>
#include <pthread.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/epoll.h>
#include <sys/uio.h>
#include <sys/sendfile.h>
#define ARGS_CHECK(argc,val) {if(argc!=val)  {printf("error args\n");return -1;}}
#define ERROR_CHECK(ret,retVal,funcName) {if(ret==retVal) {perror(funcName);return -1;}}
#define THREAD_ERROR_CHECK(ret,funcName) {if(ret!=0) {printf("%s:%s\n",funcName,strerror(ret));return -1;}}
#define CHILD_THREAD_ERROR_CHECK(ret,funcName) {if(ret!=0) {printf("%s:%s\n",funcName,strerror(ret));return (void*)-1;}}
#define FILENAME "44.day10-项目讲解.avi"
typedef struct{
    pid_t pid;
    int pipeFd;
    short busy;
}process_data_t;

typedef struct {
    int dataLen;//存储buf上要发送的数据长度
    char buf[1000];//要发送的内容
}fileInfo_t;

int makeChild(process_data_t *p,int processNum);
int childHandle(int pipeFd);
int epollAdd(int epfd,int fd);
int sendFd(int pipeFd,int fd);
int recvFd(int pipeFd,int *fd);
int tcpInit(int *sfd,char* ip,char* port);
int transFile(int clientFd);
int recvCycle(int sfd,void* buf,int recvLen);
