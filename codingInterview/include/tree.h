#include <stdio.h>
#include <vector>
using std::vector;

struct TreeNode {
    int val;
    vector<TreeNode*> vChild;
    TreeNode(int value) : val(value) {}
};

void ConnectTreeNodes(TreeNode* pParent, TreeNode* pChild) {
    if (pParent != nullptr) {
        pParent->vChild.push_back(pChild);
    }
}

void PrintTreeNode(const TreeNode* pNode) {
    if (pNode != nullptr) {
        printf("value of this node is: %d.\n", pNode->val);

        printf("its children is as the following:\n");
        std::vector<TreeNode*>::const_iterator i = pNode->vChild.begin();
        while (i != pNode->vChild.end()) {
            if (*i != nullptr) printf("%d\t", (*i)->val);
            ++i;
        }

        printf("\n");
    } else {
        printf("this node is nullptr.\n");
    }

    printf("\n");
}

void PrintTree(const TreeNode* pRoot) {
    PrintTreeNode(pRoot);

    if (pRoot != nullptr) {
        std::vector<TreeNode*>::const_iterator i = pRoot->vChild.begin();
        while (i != pRoot->vChild.end()) {
            PrintTree(*i);
            ++i;
        }
    }
}

void DestroyTree(TreeNode* pRoot) {
    if (pRoot != nullptr) {
        std::vector<TreeNode*>::iterator i = pRoot->vChild.begin();
        while (i != pRoot->vChild.end()) {
            DestroyTree(*i);
            ++i;
        }

        delete pRoot;
    }
}
