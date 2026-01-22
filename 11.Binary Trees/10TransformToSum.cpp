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

int sumOfTree(Node* root) {
    if (!root) return 0;

    // Recursively calculate the sum of left and right subtrees
    int leftSum = sumOfTree(root->left);
    int rightSum = sumOfTree(root->right);

    root->data += leftSum + rightSum;

    // Return the total sum including the original value of the current node
    return root->data;
}

void preorderPrint(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}

int main() {
    
    vector<int> preOrder = {10, -2, 8, -1, -1, -4, -1, -1, 6, -1, 5, -1, -1};
    Node* root = buildTree(preOrder);
    cout << "Original Tree Preorder: ";
    preorderPrint(root);
    cout << endl;
    cout << "Sum Tree Preorder: " << sumOfTree(root) << endl;
    cout << "Sum Tree Preorder: ";
    preorderPrint(root);
    cout << endl;

    return 0;
}