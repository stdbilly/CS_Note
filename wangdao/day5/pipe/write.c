#include <func.h>

int main(int argc,char* argv[])
{
    ARGS_CHECK(argc,2);
    int fdw=open(argv[1],O_WRONLY);
    printf("I am writer fdw=%d\n",fdw);
    sleep(5);
    //write(fdw,"I hen shuai",11);
    close(fdw);
    sleep(10);
    return 0;
}

