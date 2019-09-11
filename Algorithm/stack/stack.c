#include "stack.h"
void initStack(pStack_t stack)
{
	memset(stack,0,sizeof(Stack_t));
}
void pop(pStack_t stack)
{
	pNode_t pCur;
	if(!stack->size)
	{
		printf("stack is empty\n");
		return;
	}
	pCur=stack->phead;
	stack->phead=pCur->pNext;
	free(pCur);
	pCur=NULL;
}
void push(pStack_t stack,int val)
{
	pNode_t pNew=(pNode_t)calloc(1,sizeof(Node_t));
	pNew->val=val;
	pNew->pNext=stack->phead;
	stack->phead=pNew;
	stack->size++;
}
int top(pStack_t stack)
{
	if(!stack->size)
	{
		printf("stack is empty\n");
		return -1;
	}
	return stack->phead->val;
}
int size(pStack_t stack)
{
	return stack->size;
}
int empty(pStack_t stack)
{
	return !stack->size;
}