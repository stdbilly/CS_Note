#pragma once
#include <iostream>
using std::cout;
using std::endl;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void connectTreeNodes(TreeNode* parent, TreeNode* left, TreeNode* right) {
    if (parent) {
        parent->left = left;
        parent->right = right;
    }
}

void printTreeNode(const TreeNode* pNode) {
    if (pNode) {
        cout << "value of this node is: " << pNode->val << endl;
        if (pNode->left)
            cout << "value of its left is: " << pNode->left->val << endl;
        else
            cout << "left is nullptr" << endl;
        if (pNode->right)
            cout << "value of its right is: " << pNode->right->val << endl;
        else
            cout << "right is nullptr" << endl;
    } else {
        cout << "this node is nullptr" << endl;
    }
    cout << endl;
}

void printTree(const TreeNode* root) {
    printTreeNode(root);
    if(root) {
        if(root->left) 
            printTree(root->left);
        if(root->right)
            printTree(root->right);
    }
}

void destroyTree(TreeNode* root) {
    if(root) {
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        delete root;
        root = nullptr;
        destroyTree(left);
        destroyTree(right);
    }
}

template <class Container>
void display(const Container& c) {
    typename Container::const_iterator cit = c.begin();
    while (cit != c.end()) {
        cout << *cit << " ";
        ++cit;
    }
    cout << endl;
}