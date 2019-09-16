#include <iostream>
#include <vector>
#include "../include/binaryTree.h"
using std::cout;
using std::endl;
using std::vector;

class Solution {
   public:
    TreeNode* Convert(TreeNode* pRootOfTree) {
        pHead = nullptr;
        pTail = nullptr;
        convertNode(pRootOfTree);
        return pHead;
    }

   private:
    void convertNode(TreeNode* pNode) {
        if (!pNode) return;

        TreeNode* pCur = pNode;
        if (pCur->left) {
            convertNode(pCur->left);
        }
        //只会执行一次,此时pCur为最左子节点, 也就是链表第一个节点
        if (pHead == nullptr) {
            pHead = pCur;
        }

        pCur->left = pTail;
        if (pTail) {
            pTail->right = pCur;
        }

        pTail = pCur;
        if (pCur->right) {
            convertNode(pCur->right);
        }
    }

   private:
    TreeNode* pHead;  //链表头结点
    TreeNode* pTail;  //链表最后一个节点
};

// ====================测试代码====================
void PrintDoubleLinkedList(TreeNode* pHeadOfList) {
    TreeNode* pNode = pHeadOfList;

    printf("The nodes from left to right are:\n");
    while (pNode != nullptr) {
        printf("%d\t", pNode->val);

        if (pNode->right == nullptr) break;
        pNode = pNode->right;
    }

    printf("\nThe nodes from right to left are:\n");
    while (pNode != nullptr) {
        printf("%d\t", pNode->val);

        if (pNode->left == nullptr) break;
        pNode = pNode->left;
    }

    printf("\n");
}

void DestroyList(TreeNode* pHeadOfList) {
    TreeNode* pNode = pHeadOfList;
    while (pNode != nullptr) {
        TreeNode* pNext = pNode->right;

        delete pNode;
        pNode = pNext;
    }
}

void Test(char* testName, TreeNode* pRootOfTree) {
    Solution solution;
    if (testName != nullptr) printf("%s begins:\n", testName);

    printTree(pRootOfTree);

    TreeNode* pHeadOfList = solution.Convert(pRootOfTree);

    PrintDoubleLinkedList(pHeadOfList);
}

//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
void Test1() {
    TreeNode* pNode10 = new TreeNode(10);
    TreeNode* pNode6 = new TreeNode(6);
    TreeNode* pNode14 = new TreeNode(14);
    TreeNode* pNode4 = new TreeNode(4);
    TreeNode* pNode8 = new TreeNode(8);
    TreeNode* pNode12 = new TreeNode(12);
    TreeNode* pNode16 = new TreeNode(16);

    connectTreeNodes(pNode10, pNode6, pNode14);
    connectTreeNodes(pNode6, pNode4, pNode8);
    connectTreeNodes(pNode14, pNode12, pNode16);

    Test("Test1", pNode10);

    DestroyList(pNode4);
}

int main() {
    Test1();
    return 0;
}