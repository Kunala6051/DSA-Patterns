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

// LeetCode: 235. Lowest Common Ancestor of a Binary Search Tree

// In a BST, for any node:
// - All values in the left subtree are less than the node's value
// - All values in the right subtree are greater than the node's value

// To find the lowest common ancestor (LCA) of two nodes p and q:
// 1. Start from the root and compare its value with p and q.
// 2. If both p and q are less than the root, move to the left subtree.
// 3. If both p and q are greater than the root, move to the right subtree.

// 4. If one of p or q is on one side and the other is on the opposite side (or one matches the root),
//    then the current root is their lowest common ancestor.

// (Split will happen when one node is on the left and the other is on the right,
// or when one of them is the root itself.)
// This works because in a BST, the first node we encounter that separates p and q
// must be their lowest common ancestor.


// Consider the following BST:
//         6
//        / \
//       2   8
//      / \ / \
//     0  4 7  9

// dry run example:
// p = 0, q = 4 → LCA = 2

// 1. Start at root (6):
//    - Both 0 and 4 are less than 6 → move to left child (2)
// 2. At node (2):
//    - 0 is less than 2, but 4 is greater than 2 → split point found
//    - LCA is 2

// p = 4, q = 7 → LCA = 6

// 1. Start at root (6):
//    - 4 is less than 6, but 7 is greater than 6 → split point found
//    - LCA is 6


TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root) return NULL;
    int x=root->val;
    if(x>p->val && x>q->val) return lowestCommonAncestor(root->left, p, q);
    else if(x<p->val && x<q->val) return lowestCommonAncestor(root->right, p, q);
    else return root;
}

int main() {
    vector<int> values = {6,2,8,0,4,7,9};
    TreeNode* root = buildBST(values);

    TreeNode* p = root->left;          // Node with value 2
    TreeNode* q = root->left->right;   // Node with value 4

    TreeNode* lca = lowestCommonAncestor(root, p, q);
    cout << "LCA of " << p->val << " and " << q->val << " is: " << lca->val << endl; // Should print 2

    p = root->left->right;  // Node with value 4
    q = root->right;        // Node with value 8

    lca = lowestCommonAncestor(root, p, q);
    cout << "LCA of " << p->val << " and " << q->val << " is: " << lca->val << endl; // Should print 6

    return 0;
}