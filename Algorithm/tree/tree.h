#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

typedef struct node_t{
	ElemType c;
	struct node_t *pleft;
	struct node_t *pright;
}Node_t,*pNode_t;

typedef struct queue_t{
	pNode_t insertPos;
	struct queue_t *pNext;
}Queue_t,*pQueue_t;
void preOrder(pNode_t root);
void midOrder(pNode_t root);
void lastOrder(pNode_t root);
void buildBinaryTree(pNode_t*,pQueue_t*,pQueue_t*,ElemType);