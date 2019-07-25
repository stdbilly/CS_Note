#include <iostream>
using std::cout;
using std::endl;

int a=0;
char* p1;

int main()
{
    int b;
    char s[]="hello";
    char* p2;

    printf("&a=%p\n",&a);
    printf("&p1=%p\n",&p1);
    printf("p1=%p\n",p1);
    printf("&b=%p\n",&b);
    printf("s=%p\n",s);
    printf("&p2=%p\n",&p2);
    printf("p2=%p\n",p2);
    return 0;
}

