#include <deque>
#include <iostream>
#include <vector>
#include "binaryTree.h"
using std::cout;
using std::deque;
using std::endl;
using std::vector;

class Solution {
   public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        if (!root) return {};

        vector<int> ret;
        deque<TreeNode*> que;
        que.push_back(root);
        while (!que.empty()) {
            TreeNode* pNode = que.front();
            que.pop_front();
            ret.push_back(pNode->val);

            if (pNode->left) {
                que.push_back(pNode->left);
            }
            if (pNode->right) {
                que.push_back(pNode->right);
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
    vector<int> ret = solution.PrintFromTopToBottom(pRoot);
    display(ret);
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