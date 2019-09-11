#include "list.h"
//链表头插法
void listHeadInsert(pList_t *ppHead, List_t **ppTail, int val) {
    pList_t pNew = (pList_t)calloc(1, sizeof(List_t));
    pNew->val = val;
    if (NULL == *ppHead)  //判断链表是否为空
    {
        *ppHead = pNew;
        *ppTail = pNew;
    } else {
        pNew->pNext = *ppHead;
        *ppHead = pNew;
    }
}
//链表打印
void listPrint(pList_t pHead) {
    while (pHead) {
        printf("%3d\n", pHead->val);
        pHead = pHead->pNext;
    }
}
//链表尾插法
void listTailInsert(pList_t *ppHead, List_t **ppTail, int val) {
    pList_t pNew = (pList_t)calloc(1, sizeof(List_t));
    pNew->val = val;
    if (NULL == *ppTail) {
        *ppHead = pNew;
        *ppTail = pNew;
    } else {
        (*ppTail)->pNext = pNew;
        *ppTail = pNew;
    }
}
//链表有序插入
void listSortInsert(pList_t *ppHead, List_t **ppTail, int val) {
    pList_t pNew = (pList_t)calloc(1, sizeof(List_t));
    pList_t pCur, pPre;
    pCur = pPre = *ppHead;
    pNew->val = val;
    if (NULL == pCur)  //判断链表是否为空
    {
        *ppHead = pNew;
        *ppTail = pNew;
    } else if (val < pCur->val)  //头插法
    {
        pNew->pNext = *ppHead;
        *ppHead = pNew;
    } else {
        while (pCur)  //插入到中间
        {
            if (pCur->val > val) {
                pPre->pNext = pNew;
                pNew->pNext = pCur;
                break;
            }
            pPre = pCur;
            pCur = pCur->pNext;
        }
        if (NULL == pCur)  //这时就要插入到尾部
        {
            pPre->pNext = pNew;
            *ppTail = pNew;
        }
    }
}
//链表的删除
void listDelete(pList_t *ppHead, List_t **ppTail, int deleteval) {
    pList_t pCur = *ppHead, pPre;
    pPre = pCur;
    if (NULL == pCur) {
        printf("List is empty\n");
        return;
    } else if (pCur->val == deleteval)  //删除的是头部
    {
        *ppHead = pCur->pNext;
        if (NULL == *ppHead) {
            *ppTail = NULL;
        }
    } else {
        while (pCur)  //删除的是中间或者尾部
        {
            if (pCur->val == deleteval) {
                pPre->pNext = pCur->pNext;
                break;
            }
            pPre = pCur;
            pCur = pCur->pNext;
        }
        if (NULL == pCur)  //没有找到对应结点
        {
            printf("Don't find deleteval\n");
            return;
        }
        if (pCur == *ppTail) {
            *ppTail = pPre;
        }
    }
    free(pCur);
    pCur = NULL;
}

void listModify(pList_t pHead, int val) {
    while (pHead) {
        if (pHead->val == val) {
            break;
        }
        pHead = pHead->pNext;
    }
    if (NULL == pHead) {
        printf("Don't find modify val\n");
    }
}