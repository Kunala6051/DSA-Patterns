#include <iostream>
#include <climits>
#include <vector>
#include <queue>
using namespace std;

// Node structure for binary tree
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x){
        val = x;
        left = right = NULL;
    }
};


// Insert a new value into the BST
TreeNode* insertBST(TreeNode* root, int val){
    if(!root) return new TreeNode(val);
    if(val<root->val) {
        root->left= insertBST(root->left,val);
    } else{ 
        root->right= insertBST(root->right,val);
    }

    return root;
}

TreeNode* buildBST(vector<int> arr){
    TreeNode* root=NULL;
    for(int i:arr){
        root=insertBST(root,i);
    }
    return root;
}

// LeetCode: 1008. Construct Binary Search Tree from Preorder Traversal


/*
APPROACH:

We are given the preorder traversal of a Binary Search Tree (BST).

Key properties used:
1. Preorder traversal order is: Root → Left → Right
2. In a BST:
   - Left subtree values < root
   - Right subtree values > root

Idea:
- Use an index `i` that moves through the preorder array exactly once.
- Use an `upperbound` to restrict how large a node value can be in the current subtree.

How recursion works:
- If current value exceeds upperbound, it does not belong to this subtree → return NULL.
- Create a node with preorder[i] and increment index.
- Recursively build:
    - Left subtree with upperbound = current node's value
    - Right subtree with same upperbound as parent

This ensures:
- Correct BST structure
- O(n) time since each node is processed once
- O(h) recursion stack where h is tree height
*/

TreeNode* helper(vector<int>& preorder, int& i, int upperbound) {
    // stop if all elements are used or current value violates BST constraint
    if (i >= preorder.size() || preorder[i] > upperbound)
        return NULL;

    // create current root node
    TreeNode* root = new TreeNode(preorder[i]);
    i++;  // move to next preorder element

    // build left subtree (values must be < root->val)
    root->left = helper(preorder, i, root->val);

    // build right subtree (values must be <= upperbound) 
    // upperbound is inherited from parent
    root->right = helper(preorder, i, upperbound);

    return root;
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
    int i = 0;  // index to track preorder traversal
    return helper(preorder, i, INT_MAX);  // initial upperbound is infinity
}

// Function to print inorder traversal of the BST
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    vector<int> preorder = {8, 5, 1, 7, 10, 12};
    TreeNode* root = bstFromPreorder(preorder);

    cout << "Inorder Traversal of the constructed BST: ";
    inorder(root); // Should print values in sorted order: 1 5 7 8 10 12
    cout << endl;

    return 0;
}