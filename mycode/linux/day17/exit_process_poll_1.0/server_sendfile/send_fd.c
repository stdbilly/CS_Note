#include "process_poll.h"
int sendFd(int pipeFd,int fd) {
    struct msghdr msg;
    bzero(&msg,sizeof(msg));
    struct iovec *iov=(struct iovec*)calloc(1,sizeof(struct iovec));
    char buf[10]="a";
    iov->iov_base=buf;
    iov->iov_len=1;
    msg.msg_iov=iov;
    msg.msg_iovlen=1;
    struct cmsghdr *cmsg;
    int cmsgLen=CMSG_LEN(sizeof(int));
    cmsg=(struct cmsghdr*)calloc(1,cmsgLen);
    cmsg->cmsg_len=cmsgLen;
    cmsg->cmsg_level=SOL_SOCKET;
    cmsg->cmsg_type=SCM_RIGHTS;
    *(int*)CMSG_DATA(cmsg)=fd;
    msg.msg_control=cmsg;
    msg.msg_controllen=cmsgLen;
    int ret;
    ret=sendmsg(pipeFd,&msg,0);
    ERROR_CHECK(ret,-1,"sendmsg");
    return 0;
}

int recvFd(int pipeFd,int *fd) {
    struct msghdr msg;
    bzero(&msg,sizeof(msg));
    struct iovec *iov=(struct iovec*)calloc(1,sizeof(struct iovec));
    char buf[10]="a";
    iov->iov_base=buf;
    iov->iov_len=1;
    msg.msg_iov=iov;
    msg.msg_iovlen=1;
    struct cmsghdr *cmsg;
    int cmsgLen=CMSG_LEN(sizeof(int));
    cmsg=(struct cmsghdr*)calloc(1,cmsgLen);
    cmsg->cmsg_len=cmsgLen;
    cmsg->cmsg_level=SOL_SOCKET;
    cmsg->cmsg_type=SCM_RIGHTS;
    msg.msg_control=cmsg;
    msg.msg_controllen=cmsgLen;
    int ret;
    ret=recvmsg(pipeFd,&msg,0);
    ERROR_CHECK(ret,-1,"sendmsg");
    *fd=*(int*)CMSG_DATA(cmsg);
    return 0;
}
