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

static int idx = -1;   // global index for preorder traversal

// Builds binary tree from preorder traversal where -1 represents NULL
Node* buildTree(vector<int> preOrder){
    idx++;

    // If current value is -1, return NULL node
    if(preOrder[idx] == -1) return NULL;

    // Create node with current value
    Node* root = new Node(preOrder[idx]);

    // Build left and right subtrees recursively
    root->left = buildTree(preOrder);
    root->right = buildTree(preOrder);

    return root;
}

// Flatten a binary tree to a linked list in-place

// The linked list should use the right pointers to point to the next node in the list
// The linked list should be in the same order as a preorder traversal of the binary tree
// All left children should be NULL
// The right child should point to the next node in preorder traversal

// Approach:
// We can use a recursive approach to flatten the tree

// We will start making linked list from the bottom of the tree
// Means reverse of preorder traversal (i.e., right -> left -> root)
// Traverse the right subtree first, then left subtree, and finally process the root node

// We will maintain a pointer to the previously processed node (prev)
// For each node, we will set its right child to prev and left child to NULL


Node* nextRight = NULL;  // Stores the previously processed node in reverse preorder

void flatten(Node* root){
    // Base case: if current node is NULL, do nothing
    if(!root) return;
    
    // Recursively flatten the right subtree first
    // This ensures correct order when we rewire pointers
    flatten(root->right);
    
    // Recursively flatten the left subtree
    flatten(root->left);

    // After both subtrees are flattened:
    
    // Set left child to NULL as required by the flattened linked list
    root->left = NULL;
    
    // Point the current node's right to the previously processed node
    // This effectively links nodes in preorder sequence
    root->right = nextRight;
    
    // Update 'nextRight' to current node for the next iteration
    nextRight = root;
}

// Time Complexity: O(n)



int main(){
    vector<int> preOrder = {1,2,3,-1,-1,4,-1,-1,5,-1,6,-1,-1};
    Node* root = buildTree(preOrder);

    flatten(root);

    // Print the flattened linked list
    Node* curr = root;
    while(curr){
        cout << curr->data << " ";
        curr = curr->right;
    }

    return 0;
}