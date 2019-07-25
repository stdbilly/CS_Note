#include <func.h>

int main()
{
    int ret;
    ret=chdir("/tmp");
    ERROR_CHECK(ret,-1,"chdir");
    printf("current path=%s\n",getcwd(NULL,0));
    return 0;
}

