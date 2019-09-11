#pragma once
#include <iostream>
using std::cout;
using std::endl;

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(nullptr), right(nullptr), next(nullptr) {
        
    }
};

void connectTreeLinkNodes(TreeLinkNode* parent, TreeLinkNode* left, TreeLinkNode* right) {
    if (parent) {
        parent->left = left;
        parent->right = right;

        if(left) left->next = parent;
        if(right) right->next = parent;
    }
}

void printTreeLinkNode(const TreeLinkNode* pNode) {
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

void printTree(const TreeLinkNode* root) {
    printTreeLinkNode(root);
    if(root) {
        if(root->left) 
            printTree(root->left);
        if(root->right)
            printTree(root->right);
    }
}

void destroyTree(TreeLinkNode* root) {
    if(root) {
        TreeLinkNode* left = root->left;
        TreeLinkNode* right = root->right;
        delete root;
        root = nullptr;
        destroyTree(left);
        destroyTree(right);
    }
}