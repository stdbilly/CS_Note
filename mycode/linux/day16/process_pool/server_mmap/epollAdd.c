#include "process_poll.h"

int epollAdd(int epfd,int fd)
{
    struct epoll_event event;
    event.events=EPOLLIN;
    event.data.fd=fd;
    int ret;
    ret=epoll_ctl(epfd,EPOLL_CTL_ADD,fd,&event);
    ERROR_CHECK(ret,-1,"epoll_ctl");
    return 0;
}

