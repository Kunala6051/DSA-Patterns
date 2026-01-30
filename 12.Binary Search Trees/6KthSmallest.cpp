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


// LeetCode: 230. Kth Smallest Element in a BST

// Kth smallest element means the element that would appear in the kth position
// if we were to list all elements of the BST in sorted order.

// Consider the following BST:
//       50
//      /  \
//    45    60
//   / \    / \
//  40 48  55 70

// Inorder traversal (sorted order): 40, 45, 48, 50, 55, 60, 70
// 1st smallest: 40
// 2nd smallest: 45
// kth smallest elememt can be found using inorder traversal of BST
// We can keep a count of nodes visited during inorder traversal




// Approach 1:
// - Performs full inorder traversal
// - Uses global counter and variable to store answer
// - Simple and easy to understand
// - Traverses entire tree even after finding k-th element

int order = 0;      // Counts nodes visited in inorder sequence
int ans = -1;       // Stores k-th smallest value

void inorder(TreeNode* root, int k){
    if(!root) return;            // Base case

    inorder(root->left, k);      // Visit left subtree (smaller values)

    order++;                     // Visit current node
    if(order == k)               // If k-th node reached
        ans = root->val;         // Store answer

    inorder(root->right, k);     // Visit right subtree (larger values)
}

int kthSmallest(TreeNode* root, int k) {
    inorder(root, k);            // Full inorder traversal
    return ans;                  // Return stored result
}




// Approach 2:
// - Uses inorder traversal with early stopping
// - Returns answer immediately when k-th node is found
// - Avoids unnecessary traversal
// - More complex due to multiple return paths
// - Harder to read and debug

int order2 = 0;    // Counts nodes visited so far

int kthSmallest2(TreeNode* root, int k) {
    if(!root) return -1;         // Base case / not found

    // Search in left subtree
    if(root->left){
        int leftAns = kthSmallest2(root->left, k);
        if(leftAns != -1)        // If k-th found in left subtree
            return leftAns;      // Return immediately (early exit)
    }

    order2++;                     // Visit current node
    if(order2 == k)               // If k-th node reached
        return root->val;        // Return answer immediately

    // Search in right subtree
    if(root->right){
        int rightAns = kthSmallest2(root->right, k);
        if(rightAns != -1)       // If k-th found in right subtree
            return rightAns;
    }

    return -1;                   // k-th element not found here
}


int main(){
    vector<int> values = {50,45,60,40,48,55,70};
    TreeNode* root = buildBST(values);

    int k = 3;
    cout << "The " << k << "th smallest element is: " << kthSmallest(root, k) << endl;
    cout << "The " << k << "th smallest element (Approach 2) is: " << kthSmallest2(root, k) << endl;

    return 0;
}