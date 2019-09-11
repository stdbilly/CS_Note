#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct tag
{
	int val;
	struct tag *pNext;
}Node_t,*pNode_t;

typedef struct{
	pNode_t phead;
	int size;
}Stack_t,*pStack_t;

void initStack(pStack_t);
void pop(pStack_t);
void push(pStack_t,int);
int top(pStack_t);
int size(pStack_t);
int empty(pStack_t);