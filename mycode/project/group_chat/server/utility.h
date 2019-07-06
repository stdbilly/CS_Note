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
#define ARGS_CHECK(argc,val) {if(argc!=val)  {printf("error args\n");return -1;}}
#define ERROR_CHECK(ret,retVal,funcName) {if(ret==retVal) {perror(funcName);return -1;}}
#define THREAD_ERROR_CHECK(ret,funcName) {if(ret!=0) {printf("%s:%s\n",funcName,strerror(ret));return -1;}}
#define CHILD_THREAD_ERROR_CHECK(ret,funcName) {if(ret!=0) {printf("%s:%s\n",funcName,strerror(ret));return (void*)-1;}}

typedef struct clientList{
    int clientFd;
    char ip[16];
    uint16_t port;
    char name[20];
    struct clientList *pNext;
}ClientList_t,*pClientList_t;

#define EPOLL_SIZE 100
#define BUF_SIZE 1024
#define SERVER_WELCOME "Welcome to join the chat room! Please enter username:"
#define SERVER_MESSAGE "%s >> %s"
#define EXIT "EXIT"
#define CAUTION "There is only you in the char room!"

int tcpInit(int *sfd,char* ip,char* port);
int setNonblock(int fd);
int addEpfd(int epfd,int fd);
void addClient(pClientList_t *ppHead,pClientList_t *ppTail,ClientList_t cl);
int sendBroadcastmessage(pClientList_t pClient,pClientList_t *ppHead,pClientList_t *ppTail);
pClientList_t findClient(int clientFd,pClientList_t pHead);
int removeClient(pClientList_t pClient,pClientList_t *pHead,pClientList_t *ppTail);
