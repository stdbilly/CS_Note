#include <vector>
#include "binaryTree.h"
using std::vector;

class Solution {
   public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        if (pNode == nullptr) return nullptr;

        TreeLinkNode* pNext = nullptr;
        if (pNode->right) {
            //节点有右子树,如果右子树没有左子树,下一个节点是右子树;
            //否则,下一个节点为它右子树的最左子节点
            TreeLinkNode* pRight = pNode->right;
            while (pRight->left) {
                pRight = pRight->left;
            }
            pNext = pRight;
        } else if (pNode->next) {
            //没有右子树的情况: 如果该节点是它父节点的左子节点,
            //下一个节点就是他的父节点; 如果该节点是它父节点的右子节点,
            //沿着父节点的指针一直向上遍历,
            //直到找到一个节点是它父节点的左子节点, 如果这样的节点存在,
            //下一个节点便是这个节点的父节点
            TreeLinkNode* pCur = pNode;
            TreeLinkNode* pParent = pNode->next;
            while (pParent && pCur == pParent->right) {
                pCur = pParent;
                pParent = pParent->next;
            }
            pNext = pParent;
        }
        return pNext;
    }
};

//            8
//        6      10
//       5 7    9  11
void test1() {
    Solution solution;
    TreeLinkNode* pNode8 = new TreeLinkNode(8);
    TreeLinkNode* pNode6 = new TreeLinkNode(6);
    TreeLinkNode* pNode10 = new TreeLinkNode(10);
    TreeLinkNode* pNode5 = new TreeLinkNode(5);
    TreeLinkNode* pNode7 = new TreeLinkNode(7);
    TreeLinkNode* pNode9 = new TreeLinkNode(9);
    TreeLinkNode* pNode11 = new TreeLinkNode(11);

    connectTreeLinkNodes(pNode8, pNode6, pNode10);
    connectTreeLinkNodes(pNode6, pNode5, pNode7);
    connectTreeLinkNodes(pNode10, pNode9, pNode11);

    TreeLinkNode* pNext = solution.GetNext(pNode8);
    cout << pNext->val << endl;
    if (pNext == pNode9)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
    
    destroyTree(pNode8);
}

int main() {
    test1();
    return 0;
}