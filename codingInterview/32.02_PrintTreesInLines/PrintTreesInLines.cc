#include <iostream>
#include <queue>
#include <vector>
#include "binaryTree.h"
using std::cout;
using std::endl;
using std::queue;
using std::vector;

class Solution {
   public:
    vector<vector<int>> Print(TreeNode* pRoot) {
        if (!pRoot) return vector<vector<int>>();

        vector<vector<int>> ret;
        vector<int> temp;
        queue<TreeNode*> que;
        que.push(pRoot);
        int nextLevel = 0;
        int curLevel = 1;
        while (!que.empty()) {
            TreeNode* pNode = que.front();
            temp.push_back(pNode->val);
            if (pNode->left) {
                que.push(pNode->left);
                ++nextLevel;
            }

            if (pNode->right) {
                que.push(pNode->right);
                ++nextLevel;
            }

            que.pop();
            --curLevel;
            if (curLevel == 0) {
                ret.push_back(temp);
                temp.clear();
                curLevel = nextLevel;
                nextLevel = 0;
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