#include <vector>
#include <algorithm>
#include "binaryTree.h"
using std::vector;

class Solution {
   public:
    using vecIterator = vector<int>::iterator;

    TreeNode* reConstructBinaryTree(vector<int> preorder, vector<int> inorder) {
        if (preorder.empty() || inorder.empty()) return nullptr;
        //左闭右开区间[...)
        return constructCore(preorder.begin(), preorder.end(), inorder.begin(),
                             inorder.end());
    }

   private:
    TreeNode* constructCore(vecIterator begPreorder, vecIterator endPreorder,
                            vecIterator begInorder, vecIterator endInorder) {
        //前序遍历序列的第一个数字为根节点的值
        TreeNode* root = new TreeNode(*begPreorder);
        //递归出口
        if (begPreorder + 1 == endPreorder) {
            if (begInorder + 1 == endInorder && *begPreorder == *begInorder)
                return root;
            else
                throw std::exception();
        }
        //在中序遍历中找到根节点的值
        auto rootInorder = std::find(begInorder, endInorder, root->val);

        if (rootInorder == endInorder) {
            throw std::exception();
        }

        int leftLen = rootInorder - begInorder;
        vecIterator leftEndPreorder = begPreorder + leftLen + 1;
        //构建左子树
        if (leftLen > 0) {
            root->left = constructCore(begPreorder + 1, leftEndPreorder,
                                       begInorder, rootInorder);
        }
        //构建右子树
        if (leftLen < endPreorder - begPreorder - 1) {
            root->right = constructCore(leftEndPreorder, endPreorder,
                                        rootInorder + 1, endInorder);
        }

        return root;
    }
};

int main() {
    Solution solution;
    vector<int> preorder{3, 9, 20, 15, 7};
    vector<int> inorder{9, 3, 15, 20, 7};
    TreeNode* root = solution.reConstructBinaryTree(preorder, inorder);
    printTree(root);
    destroyTree(root);
    return 0;
}