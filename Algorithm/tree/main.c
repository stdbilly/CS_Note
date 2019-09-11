#include "tree.h"

#define N 10
int main()
{
	ElemType val;
	pNode_t treeRoot=NULL;
	pQueue_t queHead=NULL,queTail=NULL;
	while(scanf("%c",&val)!=EOF)
	{
		if(val=='\n')
		{
			break;
		}
		buildBinaryTree(&treeRoot,&queHead,&queTail,val);
	}
	preOrder(treeRoot);
	printf("\n-----------------------\n");
	midOrder(treeRoot);
	printf("\n-----------------------\n");
	lastOrder(treeRoot);
}
