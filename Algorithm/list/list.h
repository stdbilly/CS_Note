#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int val;
    struct list *pNext;
} List_t, *pList_t;

void listHeadInsert(pList_t *, List_t **, int);
void listTailInsert(pList_t *, List_t **, int);
void listSortInsert(pList_t *, List_t **, int);
void listDelete(pList_t *, pList_t *, int);
void listModify(pList_t, int);
void listPrint(pList_t);