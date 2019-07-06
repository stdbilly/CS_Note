#include <func.h>

int main(int argc,char* argv[])
{
    ARGS_CHECK(argc,2);
    FILE* fp;
    fp=fopen(argv[1],"rb+");
    ERROR_CHECK(fp,NULL,"fopen");
    char buf[128]={0};
    read(3,buf,sizeof(buf));
    printf("buf=%s\n",buf);
    return 0;
}

