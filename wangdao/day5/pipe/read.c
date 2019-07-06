#include <func.h>

int main(int argc,char* argv[])
{
    ARGS_CHECK(argc,2);
    int fdr=open(argv[1],O_RDONLY);
    printf("I am reader fdr=%d\n",fdr);
    char buf[128]={0};
    int ret;
    ret=read(fdr,buf,sizeof(buf));
    printf("ret=%d,gets %s\n",ret,buf);
    return 0;
}

