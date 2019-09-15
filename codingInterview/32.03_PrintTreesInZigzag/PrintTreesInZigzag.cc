#include <iostream>
#include <stack>
#include <vector>
#include "binaryTree.h"
using std::cout;
using std::endl;
using std::stack;
using std::vector;

// 面试题32（三）：之字形打印二叉树
// 题目：请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺
// 序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，
// 其他行以此类推。

class Solution {
   public:
    vector<vector<int>> Print(TreeNode* pRoot) {
        if (!pRoot) return vector<vector<int>>();

        vector<vector<int>> ret;
        vector<int> temp;
        stack<TreeNode*> levels[2];
        int current = 0;
        int next = 1;

        levels[current].push(pRoot);
        while (!levels[0].empty() || !levels[1].empty()) {
            TreeNode* pNode = levels[current].top();
            levels[current].pop();
            temp.push_back(pNode->val);

            if (current == 0) {
                //下一层从右往左遍历
                if (pNode->left) {
                    levels[next].push(pNode->left);
                }
                if (pNode->right) {
                    levels[next].push(pNode->right);
                }
            } else {
                //下一层从左往右遍历
                if (pNode->right) {
                    levels[next].push(pNode->right);
                }
                if (pNode->left) {
                    levels[next].push(pNode->left);
                }
            }

            if (levels[current].empty()) {
                ret.push_back(temp);
                temp.clear();
                current = 1 - current;
                next = 1 - next;
            }
        }
        return ret;
    }
};

// ====================测试代码====================
void Test(char* testName, TreeNode* pRoot) {
    Solution solution;
    if (testName != nullptr) printf("%s begins: \n", testName);

    printTree(pRoot);

    printf("The nodes from top to bottom, from left to right are: \n");
    vector<vector<int>> ret = solution.Print(pRoot);
    for (auto& v : ret) {
        display(v);
    }
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

    destroyTree(pNode10);
}

int main() {
    Test1();
    return 0;
}