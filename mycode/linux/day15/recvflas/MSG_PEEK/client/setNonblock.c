#include <func.h>

int setNonblock(int fd)
{
    int status;
    status=fcntl(fd,F_GETFL);
    status=status|O_NONBLOCK;
    fcntl(fd,F_SETFL,status);
    return 0;
}

