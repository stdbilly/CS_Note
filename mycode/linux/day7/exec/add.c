#include <func.h>

int main(int argc,char* argv[])
{
    ARGS_CHECK(argc,3);
    printf("sum=%d\n",atoi(argv[1])+atoi(argv[2]));  
    while(1);
    return 0;
}

