#include <func.h>

int main(int argc,char* argv[])
{
    ARGS_CHECK(argc,2);
    int fdw=open(argv[1],O_WRONLY);
    printf("write fdw=%d\n",fdw);
    sleep(5);
    write(fdw,"hello",5);
    return 0;
}

