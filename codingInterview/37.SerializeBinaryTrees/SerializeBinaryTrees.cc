#include <string.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "../include/binaryTree.h"
using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::ofstream;
using std::ostringstream;
using std::string;

class Solution {
   public:
    char* Serialize(TreeNode* root) {
        ostringstream oss;
        dfsSerialize(root, oss);
        cout << oss.str() << endl;
        char* ret = new char[1024]();
        return strcpy(ret, oss.str().c_str());
    }

    TreeNode* Deserialize(char* str) {
        if (strlen(str) < 1) return nullptr;
        istringstream iss(str);

        return dfsDeserialize(iss);
    }

   private:
    void dfsSerialize(TreeNode* root, ostringstream& oss) {
        if (root == nullptr) {
            oss << "# ";
            return;
        }

        oss << root->val << " ";
        dfsSerialize(root->left, oss);
        dfsSerialize(root->right, oss);
    }

    TreeNode* dfsDeserialize(istringstream& iss) {
        if (iss.eof()) return nullptr;
        string val;
        iss >> val;
        if (val == "#") return nullptr;

        TreeNode* node = new TreeNode(std::stoi(val));
        node->left = dfsDeserialize(iss);
        node->right = dfsDeserialize(iss);

        return node;
    }
};

// ==================== Test Code ====================
bool isSameTree(const TreeNode* pRoot1, TreeNode* pRoot2) {
    if (pRoot1 == nullptr && pRoot2 == nullptr) return true;

    if (pRoot1 == nullptr || pRoot2 == nullptr) return false;

    if (pRoot1->val != pRoot2->val) return false;

    return isSameTree(pRoot1->left, pRoot2->left) &&
           isSameTree(pRoot1->right, pRoot2->right);
}

void Test(const char* testName, TreeNode* pRoot) {
    Solution solution;
    if (testName != nullptr) printf("%s begins: \n", testName);

    printTree(pRoot);

    char* str = solution.Serialize(pRoot);

    TreeNode* pNewRoot = solution.Deserialize(str);

    printTree(pNewRoot);

    if (isSameTree(pRoot, pNewRoot))
        printf("The deserialized tree is same as the oritinal tree.\n\n");
    else
        printf("The deserialized tree is NOT same as the oritinal tree.\n\n");

    delete[] str;
    str = nullptr;
    destroyTree(pNewRoot);
}

//            8
//        6      10
//       5 7    9  11
void Test1() {
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

    Test("Test1", pNode8);

    destroyTree(pNode8);
}

int main() {
    Test1();
    return 0;
}