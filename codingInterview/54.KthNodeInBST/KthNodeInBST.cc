#include <iostream>
#include <vector>
#include "binaryTree.h"
using std::cout;
using std::endl;
using std::vector;

class Solution {
   public:
    TreeNode* KthNode(TreeNode* pRoot, int k) {
        if (!pRoot || k == 0) {
            return nullptr;
        }
        return KthNodeCore(pRoot, k);
    }

   private:
    TreeNode* KthNodeCore(TreeNode* pRoot, int& k) {
        TreeNode* target = nullptr;
        //cout << "pRoot->val = " << pRoot->val << endl;
        if (pRoot->left) {
            target = KthNodeCore(pRoot->left, k);
        }
        //当找到结果后,递归返回时,下面两步都不会执行
        if (target == nullptr) {
            if (k == 1) {
                target = pRoot;
            }
            --k;
        }
        //当target = pRoot后,这一步不会执行,直接返回target
        if (target == nullptr && pRoot->right != nullptr) {
            target = KthNodeCore(pRoot->right, k);
        }

        return target;
    }
};

// ====================测试代码====================
void Test(const char* testName, TreeNode* pRoot, int k, bool isNull,
          int expected) {
    Solution solution;
    if (testName != nullptr) printf("%s begins: ", testName);

    const TreeNode* pTarget = solution.KthNode(pRoot, k);
    if ((isNull && pTarget == nullptr) || (!isNull && pTarget->val == expected))
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

//            8
//        6      10
//       5 7    9  11
void TestA() {
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

    Test("TestA0", pNode8, 0, true, -1);
    Test("TestA1", pNode8, 1, false, 5);
    Test("TestA2", pNode8, 2, false, 6);
    Test("TestA3", pNode8, 3, false, 7);
    Test("TestA4", pNode8, 4, false, 8);
    Test("TestA5", pNode8, 5, false, 9);
    Test("TestA6", pNode8, 6, false, 10);
    Test("TestA7", pNode8, 7, false, 11);
    Test("TestA8", pNode8, 8, true, -1);

    destroyTree(pNode8);
}

int main() {
    TestA();
    return 0;
}