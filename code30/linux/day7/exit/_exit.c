#include <func.h>
void print()
{
    printf("I am print\n");
    _exit(5);
}
int main(int argc,char* argv[])
{
    print();
    printf("after print\n");
    return 0;
}

