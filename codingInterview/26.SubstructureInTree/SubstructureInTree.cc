#include <iostream>
#include "binaryTree.h"
using std::cout;
using std::endl;

class Solution {
   public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
        bool result = false;
        if (pRoot1 && pRoot2) {
            if (pRoot1->val == pRoot2->val) {
                result = tree1HaveTree2(pRoot1, pRoot2);
            }

            if (!result) {
                result = HasSubtree(pRoot1->left, pRoot2);
            }

            if (!result) {
                result = HasSubtree(pRoot1->right, pRoot2);
            }
        }

        return result;
    }

   private:
    bool tree1HaveTree2(TreeNode* pRoot1, TreeNode* pRoot2) {
        if (!pRoot2) return true;
        if (!pRoot1) return false;
        if (pRoot1->val != pRoot2->val) return false;

        return tree1HaveTree2(pRoot1->left, pRoot2->left) &&
               tree1HaveTree2(pRoot1->right, pRoot2->right);
    }
};

// ====================测试代码====================
void Test(char* testName, TreeNode* pRoot1, TreeNode* pRoot2, bool expected) {
    Solution solution;
    if (solution.HasSubtree(pRoot1, pRoot2) == expected)
        printf("%s passed.\n", testName);
    else
        printf("%s failed.\n", testName);
}

// 树中结点含有分叉，树B是树A的子结构
//                  8                8
//              /       \           / \
//             8         7         9   2
//           /   \
//          9     2
//               / \
//              4   7
void Test1() {
    TreeNode* pNodeA1 = new TreeNode(8);
    TreeNode* pNodeA2 = new TreeNode(8);
    TreeNode* pNodeA3 = new TreeNode(7);
    TreeNode* pNodeA4 = new TreeNode(9);
    TreeNode* pNodeA5 = new TreeNode(2);
    TreeNode* pNodeA6 = new TreeNode(4);
    TreeNode* pNodeA7 = new TreeNode(7);

    connectTreeNodes(pNodeA1, pNodeA2, pNodeA3);
    connectTreeNodes(pNodeA2, pNodeA4, pNodeA5);
    connectTreeNodes(pNodeA5, pNodeA6, pNodeA7);

    TreeNode* pNodeB1 = new TreeNode(8);
    TreeNode* pNodeB2 = new TreeNode(9);
    TreeNode* pNodeB3 = new TreeNode(2);

    connectTreeNodes(pNodeB1, pNodeB2, pNodeB3);
    //printTree(pNodeA1);
    //printTree(pNodeB1);

    Test("Test1", pNodeA1, pNodeB1, true);

    destroyTree(pNodeA1);
    destroyTree(pNodeB1);
}

int main() {
    Test1();
    return 0;
}