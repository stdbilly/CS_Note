#include <iostream>
#include <list>
#include "tree.h"
using std::cout;
using std::endl;
using std::list;

// 面试题68：树中两个结点的最低公共祖先
// 题目：输入两个树结点，求它们的最低公共祖先。

//转化为求两个链表的最后一个公共节点
class Solution {
   public:
    const TreeNode* getLastCommonParent(const TreeNode* pRoot,
                                        const TreeNode* pNode1,
                                        const TreeNode* pNode2) {
        if (!pRoot || !pNode1 || !pNode2) return nullptr;

        list<const TreeNode*> path1;
        getNodePath(pRoot, pNode1, path1);

        list<const TreeNode*> path2;
        getNodePath(pRoot, pNode2, path2);

        return getLastCommonNode(path1, path2);
    }

   private:
    bool getNodePath(const TreeNode* pRoot, const TreeNode* pNode,
                     list<const TreeNode*>& path) {
        if (pRoot == pNode) return true;

        path.push_back(pRoot);
        bool found = false;

        vector<TreeNode*>::const_iterator iter = pRoot->vChild.begin();
        while (!found && iter < pRoot->vChild.end()) {
            found = getNodePath(*iter, pNode, path);
            ++iter;
        }

        if (!found) {
            path.pop_back();
        }

        return found;
    }

    const TreeNode* getLastCommonNode(const list<const TreeNode*>& path1,
                                      const list<const TreeNode*>& path2) {
        auto iter1 = path1.begin();
        auto iter2 = path2.begin();

        const TreeNode* pLast = nullptr;
        while (iter1 != path1.end() && iter2 != path2.end()) {
            if (*iter1 == *iter2) {
                pLast = *iter1;
            }
            ++iter1;
            ++iter2;
        }
        return pLast;
    }
};

// ====================测试代码====================
void Test(const char* testName, const TreeNode* pRoot, const TreeNode* pNode1,
          const TreeNode* pNode2, TreeNode* pExpected) {
    Solution solution;
    if (testName != nullptr) printf("%s begins: ", testName);

    const TreeNode* pResult =
        solution.getLastCommonParent(pRoot, pNode1, pNode2);

    if ((pExpected == nullptr && pResult == nullptr) ||
        (pExpected != nullptr && pResult != nullptr &&
         pResult->val == pExpected->val))
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

// 形状普通的树
//              1
//            /   \
//           2     3
//       /       \
//      4         5
//     / \      / |  \
//    6   7    8  9  10
void Test1() {
    TreeNode* pNode1 = new TreeNode(1);
    TreeNode* pNode2 = new TreeNode(2);
    TreeNode* pNode3 = new TreeNode(3);
    TreeNode* pNode4 = new TreeNode(4);
    TreeNode* pNode5 = new TreeNode(5);
    TreeNode* pNode6 = new TreeNode(6);
    TreeNode* pNode7 = new TreeNode(7);
    TreeNode* pNode8 = new TreeNode(8);
    TreeNode* pNode9 = new TreeNode(9);
    TreeNode* pNode10 = new TreeNode(10);

    ConnectTreeNodes(pNode1, pNode2);
    // cout << pNode1->vChild.size() << endl;
    ConnectTreeNodes(pNode1, pNode3);

    ConnectTreeNodes(pNode2, pNode4);
    ConnectTreeNodes(pNode2, pNode5);

    ConnectTreeNodes(pNode4, pNode6);
    ConnectTreeNodes(pNode4, pNode7);

    ConnectTreeNodes(pNode5, pNode8);
    ConnectTreeNodes(pNode5, pNode9);
    ConnectTreeNodes(pNode5, pNode10);

    // PrintTree(pNode1);

    Test("Test1", pNode1, pNode6, pNode8, pNode2);
}

int main() {
    Test1();
    return 0;
}