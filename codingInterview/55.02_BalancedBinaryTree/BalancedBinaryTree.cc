#include <iostream>
#include <vector>
#include "binaryTree.h"
using std::cout;
using std::endl;
using std::vector;

// 面试题55（二）：平衡二叉树
// 题目：输入一棵二叉树的根结点，判断该树是不是平衡二叉树。如果某二叉树中
// 任意结点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。

class Solution {
   public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        int depth = 0;
        return isBalanced(pRoot, depth);
    }

   private:
    bool isBalanced(TreeNode* pRoot, int& depth) {
        if (pRoot == nullptr) {
            depth = 0;
            return true;
        }

        int leftD, rightD;
        if (isBalanced(pRoot->left, leftD) &&
            isBalanced(pRoot->right, rightD)) {
            int dif = leftD - rightD;
            if (dif <= 1 && dif >= -1) {
                //只有左右子树深度相差不超过1才返回true,否则返回false;
                depth = leftD > rightD ? (leftD + 1) : (rightD + 1);
                return true;
            }
        }

        return false;
    }
};

// ====================测试代码====================
void Test(const char* testName, TreeNode* pRoot, bool expected) {
    Solution solution;
    if (testName != nullptr) printf("%s begins:\n", testName);

    if (solution.IsBalanced_Solution(pRoot) == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

// 完全二叉树
//             1
//         /      \
//        2        3
//       /\       / \
//      4  5     6   7
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
    connectTreeNodes(pNode3, pNode6, pNode7);

    Test("Test1", pNode1, true);

    destroyTree(pNode1);
}

// 不是完全二叉树，但是平衡二叉树
//             1
//         /      \
//        2        3
//       /\         \
//      4  5         6
//        /
//       7
void Test2() {
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

    Test("Test2", pNode1, true);

    destroyTree(pNode1);
}

// 不是平衡二叉树
//             1
//         /      \
//        2        3
//       /\         
//      4  5
//        /
//       6
void Test3() {
    TreeNode* pNode1 = new TreeNode(1);
    TreeNode* pNode2 = new TreeNode(2);
    TreeNode* pNode3 = new TreeNode(3);
    TreeNode* pNode4 = new TreeNode(4);
    TreeNode* pNode5 = new TreeNode(5);
    TreeNode* pNode6 = new TreeNode(6);

    connectTreeNodes(pNode1, pNode2, pNode3);
    connectTreeNodes(pNode2, pNode4, pNode5);
    connectTreeNodes(pNode5, pNode6, nullptr);

    Test("Test3", pNode1, false);

    destroyTree(pNode1);
}

int main() {
    Test1();
    Test2();
    Test3();
    return 0;
}