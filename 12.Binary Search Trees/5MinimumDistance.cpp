#include <iostream>
#include <climits>
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


// Insert a new value into the BST
Node* insertBST(Node* root, int val){
    if(!root) return new Node(val);
    if(val<root->data) {
        root->left= insertBST(root->left,val);
    } else{ 
        root->right= insertBST(root->right,val);
    }

    return root;
}

Node* buildBST(vector<int> arr){
    Node* root=NULL;
    for(int i:arr){
        root=insertBST(root,i);
    }
    return root;
}


// LeetCode 783. Minimum Distance Between BST Nodes

// Minimum distance means the minimum absolute difference between values of any two nodes in the BST.
// As inorder traversal of BST gives sorted order, the minimum difference will be between
// two adjacent nodes in inorder traversal.

// So we need to compare each node with its previous node in inorder traversal
// and keep track of the minimum difference found so far.
// We can do this using a global variable to store the previous node and another
// global variable to store the minimum difference.

// For example, consider the following BST:
//        40
//      /   \
//     23     60
//    / \
//   13   34

// Inorder traversal: 13, 23, 34, 40, 60
// Minimum differences: |23-13|=10, |34-23|=11, |40-34|=6, |60-40|=20
// Minimum distance = 6 (between nodes 34 and 40)


Node* pre = NULL;      // Stores previously visited node in inorder
int ans = INT_MAX;          // Stores minimum difference found so far

void inorder(Node* root){
    if(!root) return;       // Base case

    inorder(root->left);    // Visit left subtree

    // Compare current node with previous node
    if(pre == NULL)
        pre = root;        // First node in inorder
    else{
        ans = min(ans, root->data - pre->data); // Update min difference
        pre = root;        // Update previous node
    }

    inorder(root->right);   // Visit right subtree
}

int minDiffInBST(Node* root) {
    inorder(root);          // Inorder traversal of BST
    return ans;             // Return minimum difference
}


int main(){
    vector<int> arr = {40, 23, 60, 13, 34};
    Node* root = buildBST(arr);

    cout << "Minimum distance between any two nodes in the BST: " << minDiffInBST(root) << endl;
    // Should print 6 (between nodes 34 and 40)
    
    return 0;
}