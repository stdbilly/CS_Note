#include <stdio.h>
#define NUM 2+3
void print(int k)
{
    printf("I am print k=%d\n",k);
}
int main()
{
	int *p;
	int arr[3]={1,2,3};
	int i=NUM*NUM;
	int j=10;
	arr[2]=4;
	p=arr;
    print(j);
	for(i=0;i<5;i++)
	{
		printf("Hello world\n");
	}
	return 0;
}
