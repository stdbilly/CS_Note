#ifndef __FUNC_H__
#define __FUNC_H__
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/msg.h>
#include <signal.h>
#include <time.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <shadow.h>
#include <crypt.h>
#include <sys/mman.h>
#include <openssl/md5.h>
#include <sys/sendfile.h>
#define SERVERNUM 3
typedef struct{
	char fileName[200];
	char ip[200];
	char port[200];
	char tmp_path[200];
	long size;
	pthread_t phid;
	char *p_mmap;
	long average;
}clientType;
void recv_file_n(int,int,char*,int,long);
int recv_n(int,char*,int);
int send_n(int,char*,int);
void log_in_operation(int);
void reg_in_operation(int);
void get_command(char*,char*,int);
void get_valid(char*,int);
int File_Isexist(char*);
void  get_md5sum(char*,char*);
void command_gets(char*,int);
#endif
