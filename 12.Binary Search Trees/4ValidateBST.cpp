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

void inorder(Node* root, vector<int> &v){
    if(!root) return;
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}

bool isValidBST(Node* root) {
    vector<int> v;
    inorder(root,v);
    
    for(int i=0; i<v.size()-1; i++){
        if(v[i]>=v[i+1]) return false;
    }
    return true;

}
// Time Complexity: O(N)



// APPROACH 2:

// Use range limits to validate BST properties
// The biggest mistake is to compare root Node with its immediate children only.

// We need to ensure that all nodes in the left subtree are less than root 
// and all nodes in the right subtree are greater than root.

// So, we pass down the valid range for each node.
// For left child, max limit is root's value
// For right child, min limit is root's value

// Helper function to validate BST using range limits
bool helper(Node* root, Node* min, Node* max){
    // Empty tree is a valid BST
    if(!root) return true;

    // Current value must be greater than min value
    if(min != NULL && root->data <= min->data) return false;

    // Current value must be less than max value
    if(max != NULL && root->data >= max->data) return false;

    // Check left subtree (update max) and right subtree (update min)
    return helper(root->left, min, root) &&
           helper(root->right, root, max);
}

// Main function to check if tree is a valid BST
bool isValidBST2(Node* root) {
    // Initially, no min or max constraints
    return helper(root, NULL, NULL);
}
// Time Complexity: O(N)


int main() {
    // Example usage:
    Node* root = new Node(2);
    root->left = new Node(1);
    root->right = new Node(3);

    cout << "Is valid BST (Approach 1): " << (isValidBST(root) ? "Yes" : "No") << endl;
    cout << "Is valid BST (Approach 2): " << (isValidBST2(root) ? "Yes" : "No") << endl;

    return 0;
}