#include "tree.h"

void preOrder(pNode_t root)
{
	if(root)
	{
		putchar(root->c);
		preOrder(root->pleft);
		preOrder(root->pright);
	}
}

void midOrder(pNode_t root)
{
	if(root)
	{
		midOrder(root->pleft);
		putchar(root->c);
		midOrder(root->pright);
	}
}

void lastOrder(pNode_t root)
{
	if(root)
	{
		lastOrder(root->pleft);
		lastOrder(root->pright);
		putchar(root->c);
	}
}

void buildBinaryTree(pNode_t* treeRoot,pQueue_t* queHead,pQueue_t* queTail,ElemType val)
{
	pNode_t treeNew=(pNode_t)calloc(1,sizeof(Node_t));
	pQueue_t queNew=(pQueue_t)calloc(1,sizeof(Queue_t));
	pQueue_t queCur=*queHead;
	treeNew->c=val;
	queNew->insertPos=treeNew;
	if(NULL==*treeRoot)
	{
		*treeRoot=treeNew;
		*queHead=queNew;
		*queTail=queNew;
	}else{
		(*queTail)->pNext=queNew;
		*queTail=queNew;
		if(NULL==queCur->insertPos->pleft)
		{
			queCur->insertPos->pleft=treeNew;
		}else if(NULL==queCur->insertPos->pright)
		{
			queCur->insertPos->pright=treeNew;
			*queHead=queCur->pNext;
			free(queCur);
			queCur=NULL;
		}
	}
}