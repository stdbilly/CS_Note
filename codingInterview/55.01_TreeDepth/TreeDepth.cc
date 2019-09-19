#include <iostream>
#include <vector>
#include "binaryTree.h"
using std::cout;
using std::endl;
using std::vector;

// 面试题55（一）：二叉树的深度
// 题目：输入一棵二叉树的根结点，求该树的深度。从根结点到叶结点依次经过的
// 结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。

class Solution {
   public:
    int TreeDepth(TreeNode* pRoot) {
        if (pRoot == nullptr) {
            return 0;
        }
        int left = TreeDepth(pRoot->left);
        int right = TreeDepth(pRoot->right);

        return left > right ? (left + 1) : (right + 1);
    }
};

// ====================测试代码====================
void Test(char* testName, TreeNode* pRoot, int expected) {
    Solution solution;
    int result = solution.TreeDepth(pRoot);
    if (expected == result)
        printf("%s passed.\n", testName);
    else
        printf("%s FAILED.\n", testName);
}

//            1
//         /      \
//        2        3
//       /\         \
//      4  5         6
//        /
//       7
void Test1() {
    TreeNode* pNode1 = new TreeNode(1);
    TreeNode* pNode2 = new TreeNode(2);
    TreeNode* pNode3 = new TreeNode(3);
    TreeNode* pNode4 = new TreeNode(4);
    TreeNode* pNode5 = new TreeNode(5);
    TreeNode* pNode6 = new TreeNode(6);
    TreeNode* pNode7 = new TreeNode(7);

    connectTreeNodes(pNode1, pNode2, pNode3);
    connectTreeNodes(pNode2, pNode4, pNode5);
    connectTreeNodes(pNode3, nullptr, pNode6);
    connectTreeNodes(pNode5, pNode7, nullptr);

    Test("Test1", pNode1, 4);

    destroyTree(pNode1);
}

int main() {
    Test1();
    return 0;
}