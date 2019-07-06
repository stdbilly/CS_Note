#include <stdio.h>
#include <stdlib.h>
#define NUM 2+3
void print(int k)
{
    printf("I am print k=%d\n",k);
    printf("I am print1 k=%d\n",k);
	char *p=NULL;
	*p='H';
    printf("I am print2 k=%d\n",k);
}
int main()
{
	int *p;
	int arr[3]={1,2,3};
	int i=3;
	int j=4;
	arr[2]=4;
	p=arr;
    print(j);
	for(i=0;i<5;i++)
	{
		printf("Hello world\n");
	}
	return 0;
}
