#include <func.h>

int main(int argc,char* argv[])
{
    sleep(10);
    execl("./add","plus","3","4",NULL);
    printf("you can't see me\n");
    return 0;
}

