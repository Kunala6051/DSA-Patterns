#include <iostream>
#include <vector>
#include <queue>
#include <map>

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

static int idx = -1;   // global index for preorder traversal

// Builds binary tree from preorder traversal where -1 represents NULL
Node* buildTree(vector<int> preOrder){
    idx++;

    if(preOrder[idx] == -1) return NULL;   // null node

    Node* root = new Node(preOrder[idx]);  // create current node

    root->left = buildTree(preOrder);      // build left subtree
    root->right = buildTree(preOrder);     // build right subtree

    return root;
}

// LeetsCode Problem: 105
// Question: Build Tree from Preorder and Inorder Traversal
// Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.
// Example:
// Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
// Output:
//         3
//        / \   
//       9  20
//          /  \
//         15   7



// APPROACH:
// 1. The first element in preorder is always the root.
// 2. Find the index of this root in inorder to determine the left and right subtrees.
// Note: Elements to the left of the root in inorder belong to the left subtree, and elements to the right belong to the right subtree.
// So, we provide the left and right boundaries for inorder array accordingly.
// 3. Recursively repeat the process for left and right subtrees.
// Base case: if there are no elements to construct the tree, return NULL.
// i.e Tree will be start building from leftmost node and go on building right nodes.


// Jaise pehle preorder se 3 aaya, wo root hoga
// Fir inorder me 3 ke left me jitne elements honge wo left subtree ke honge, aur right me jitne honge wo right subtree ke honge
// Toh inorder me 3 ke left me sirf 9 hai, toh 9 left subtree me jayega
// Right me 20, 15, 7 hai, toh wo right subtree me jayege


// In above example:
// firstly 9 will be created as left child of 3, then since there are no more left nodes, we backtrack to 3 and start building right subtree with 20 as root, and so on.

// Finds the index of key k in inorder array between l and r
int search(vector<int>& inorder, int l, int r, int k){
    for(int i = l; i <= r; i++){
        if(inorder[i] == k) return i;   // return index if found
    }
    return -1;  // not found
}

// Recursive function to build tree using preorder and inorder
Node* helper(vector<int>& preorder, vector<int>& inorder, int& preIdx, int l, int r) {
    if(l > r) return NULL;   // no nodes in this range

    // Create root from current preorder index
    Node* root = new Node(preorder[preIdx]);

    // Find root position in inorder traversal
    int i = search(inorder, l, r, preorder[preIdx]);

    preIdx++;  // move to next root in preorder

    // Build left and right subtrees
    root->left = helper(preorder, inorder, preIdx, l, i - 1);
    root->right = helper(preorder, inorder, preIdx, i + 1, r);

    return root;
}

// Main function to build tree
Node* buildTree(vector<int>& preorder, vector<int>& inorder) { 
    int preIdx = 0;   // starting index for preorder
    Node* root = helper(preorder, inorder, preIdx, 0, preorder.size() - 1);
    return root;
}

// Time Complexity: O(N^2) in worst case due to search function



int main() {
    // Example usage:
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    Node* root = buildTree(preorder, inorder);

    // The tree is now built. You can add code to verify the structure if needed.

    return 0;
}