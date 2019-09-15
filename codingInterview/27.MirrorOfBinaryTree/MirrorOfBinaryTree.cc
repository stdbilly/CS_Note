#include <iostream>
#include <vector>
#include "binaryTree.h"
using std::cout;
using std::endl;
using std::vector;

class Solution {
   public:
    void Mirror(TreeNode *pRoot) {
        if (!pRoot || (!pRoot->left && !pRoot->right)) return;

        std::swap(pRoot->left, pRoot->right);

        if (pRoot->left) Mirror(pRoot->left);

        if (pRoot->right) Mirror(pRoot->right);
    }
};

// ====================测试代码====================
// 测试完全二叉树：除了叶子节点，其他节点都有两个子节点
//            8
//        6      10
//       5 7    9  11
void Test1()
{
    Solution solution;
    printf("=====Test1 starts:=====\n");
    TreeNode* pNode8 = new TreeNode(8);
    TreeNode* pNode6 = new TreeNode(6);
    TreeNode* pNode10 = new TreeNode(10);
    TreeNode* pNode5 = new TreeNode(5);
    TreeNode* pNode7 = new TreeNode(7);
    TreeNode* pNode9 = new TreeNode(9);
    TreeNode* pNode11 = new TreeNode(11);

    connectTreeNodes(pNode8, pNode6, pNode10);
    connectTreeNodes(pNode6, pNode5, pNode7);
    connectTreeNodes(pNode10, pNode9, pNode11);

    printTree(pNode8);

    cout << "-------------" << endl;
    solution.Mirror(pNode8);
    printTree(pNode8);

    destroyTree(pNode8);
}

int main() {
    Test1();
    return 0;
}