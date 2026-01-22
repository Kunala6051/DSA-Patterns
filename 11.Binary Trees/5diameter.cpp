#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// APPROACH EXPLANATION:
// The diameter may be passed through the root or may lie entirely in the left or right subtree.
// Hence, we calculate the diameter for left and right subtrees recursively, and 
// also calculate the diameter passing through the current root (left height + right height).
// Finally, we return the maximum of these three values.

// Computes height of a subtree rooted at 'root'
int height(TreeNode* root){
    if(!root) return 0;                  // base case: empty tree has height 0
    int l = height(root->left);         // height of left subtree
    int r = height(root->right);        // height of right subtree
    return max(l, r) + 1;               // height = max(left, right) + 1
}


int diameterOfBinaryTreeBruteForce(TreeNode* root) {
    if(!root) return 0;                 // base case: empty tree has diameter 0

    int l = diameterOfBinaryTreeBruteForce(root->left);   // diameter of left subtree
    int r = diameterOfBinaryTreeBruteForce(root->right);  // diameter of right subtree
    // diameter passing through current root
    int curr = height(root->left) + height(root->right);

    // maximum of left diameter, right diameter, and current diameter
    return max(curr, max(l, r));
}
// Time Complexity: O(N^2) in the worst case (unbalanced tree)






// Optimized Approach: Calculate height and diameter in a single traversal

// APPROACH EXPLANATION:
// This approach basically calculates diameter(left height + right height) for each node and stores the 
// maximum diameter found so far in a global variable 'ans'.

int ans = 0;   // stores maximum diameter found so far

// Computes height and updates diameter at each node
int heightAndCalculatingDiameter(TreeNode* root){
    if(!root) return 0;                  // base case

    int l = height(root->left);         // height of left subtree
    int r = height(root->right);        // height of right subtree

    ans = max(ans, l + r);              // update diameter using current node

    return max(l, r) + 1;               // return height of current subtree
}

int diameterOfBinaryTree(TreeNode* root) {
    int h = height(root);               // trigger recursion
    return ans;                        // return final diameter
}
// Time Complexity: O(N)


int main() {
    // Build sample tree:
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Diameter of Binary Tree: " << diameterOfBinaryTreeBruteForce(root) << endl;
    cout << "Diameter of Binary Tree using optimized approach: " << diameterOfBinaryTree(root) << endl;

    return 0;
}
