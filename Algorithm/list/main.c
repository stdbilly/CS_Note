#include "list.h"

int main() {
    pList_t phead = NULL, ptail = NULL;
    int num;
    while (scanf("%d", &num) != EOF) {
        // listHeadInsert(&phead,&ptail,num);
        // listTailInsert(&phead,&ptail,num);
        listSortInsert(&phead, &ptail, num);
    }
    listPrint(phead);
    //刷新标准输出
    // while(printf("please input delete
    // num:"),fflush(stdout),scanf("%d",&num)!=EOF)
    //{
    //	listDelete(&phead,&ptail,num);
    //	listPrint(phead);
    //}
    while (printf("please input modify num:"), fflush(stdout),
           scanf("%d%f", &num) != EOF) {
        listModify(phead, num);
        listPrint(phead);
    }
    system("pause");
}