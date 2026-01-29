#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Node structure for binary tree
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

// LeetCode 98. Validate Binary Search Tree

// MY APPROACH:
// Use inorder traversal to get the elements in sorted order

void inorder(TreeNode* root, vector<int> &v){
    if(!root) return;
    inorder(root->left,v);
    v.push_back(root->val);
    inorder(root->right,v);
}

bool isValidBST(TreeNode* root) {
    vector<int> v;
    inorder(root,v);
    
    for(int i=0; i<v.size()-1; i++){
        if(v[i]>=v[i+1]) return false;
    }
    return true;

}