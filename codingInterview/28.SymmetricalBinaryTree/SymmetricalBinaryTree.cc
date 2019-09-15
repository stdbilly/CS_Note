#include <iostream>
#include "binaryTree.h"
using std::cout;
using std::endl;

class Solution {
   public:
    bool isSymmetrical(TreeNode* pRoot) {
        if(!pRoot) return true;
        
        return isSymmetrical(pRoot->left, pRoot->right);
    }

   private:
    bool isSymmetrical(TreeNode* pRoot1, TreeNode* pRoot2) {
        if (!pRoot1 && !pRoot2) return true;

        if (!pRoot1 || !pRoot2) return false;

        if (pRoot1->val != pRoot2->val) return false;

        return isSymmetrical(pRoot1->left, pRoot2->right) &&
               isSymmetrical(pRoot1->right, pRoot2->left);
    }
};

// ====================测试代码====================
void Test(char* testName, TreeNode* pRoot, bool expected) {
    Solution solution;
    if (testName != nullptr) printf("%s begins: ", testName);

    if (solution.isSymmetrical(pRoot) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

//            8
//        6      6
//       5 7    7 5
void Test1() {
    TreeNode* pNode8 = new TreeNode(8);
    TreeNode* pNode61 = new TreeNode(6);
    TreeNode* pNode62 = new TreeNode(6);
    TreeNode* pNode51 = new TreeNode(5);
    TreeNode* pNode71 = new TreeNode(7);
    TreeNode* pNode72 = new TreeNode(7);
    TreeNode* pNode52 = new TreeNode(5);

    connectTreeNodes(pNode8, pNode61, pNode62);
    connectTreeNodes(pNode61, pNode51, pNode71);
    connectTreeNodes(pNode62, pNode72, pNode52);

    Test("Test1", pNode8, true);

    destroyTree(pNode8);
}

int main() {
    Test1();
    return 0;
}