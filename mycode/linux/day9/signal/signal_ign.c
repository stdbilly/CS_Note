#include <func.h>
int main(int argc,char* argv[])
{
    if(signal(SIGINT,SIG_IGN)==SIG_ERR) {
        perror("signal");
        return -1;
    }
    while(1);
    return 0;
}

