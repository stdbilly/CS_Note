#include <vector>
#include "binaryTree.h"
using std::vector;

class Solution {
   public:
    vector<vector<int>> FindPath(TreeNode* root, int expectNumber) {
        if (!root) return vector<vector<int>>();

        int curSum = 0;
        findPath(root, expectNumber, curSum);
        return ret;
    }

   private:
    void findPath(TreeNode* root, int expectNum, int curSum) {
        curSum += root->val;
        path.push_back(root->val);

        // 如果是叶结点，并且路径上结点的和等于输入的值
        // 保存这条路径
        bool isLeaf = root->left == nullptr && root->right == nullptr;
        if (curSum == expectNum && isLeaf) {
            ret.push_back(path);
        }

        // 如果不是叶结点，则遍历它的子结点
        if (root->left) {
            findPath(root->left, expectNum, curSum);
        }
        if (root->right) {
            findPath(root->right, expectNum, curSum);
        }

        // 在返回到父结点之前，在路径上删除当前结点，
        // 并在currentSum中减去当前结点的值
        curSum -= root->val;
        path.pop_back();
    }

   private:
    vector<vector<int>> ret;
    vector<int> path;
};

// ====================测试代码====================
void Test(char* testName, TreeNode* pRoot, int expectedSum) {
    Solution solution;
    if (testName != nullptr) printf("%s begins:\n", testName);

    vector<vector<int>> ret = solution.FindPath(pRoot, expectedSum);
    for (auto& vec : ret) {
        display(vec);
    }
}

//            10
//         /      \
//        5        12
//       /\        
//      4  7
// 有两条路径上的结点和为22
void Test1() {
    TreeNode* pNode10 = new TreeNode(10);
    TreeNode* pNode5 = new TreeNode(5);
    TreeNode* pNode12 = new TreeNode(12);
    TreeNode* pNode4 = new TreeNode(4);
    TreeNode* pNode7 = new TreeNode(7);

    connectTreeNodes(pNode10, pNode5, pNode12);
    connectTreeNodes(pNode5, pNode4, pNode7);

    printf("Two paths should be found in Test1.\n");
    Test("Test1", pNode10, 22);

    destroyTree(pNode10);
}

int main() {
    Test1();
    return 0;
}