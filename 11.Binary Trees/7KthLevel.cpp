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

// Print nodes at Kth level of binary tree
void printKthLevel2(Node* root, int k){
    if(!root) return;          // base case: empty tree

    if(k == 1){                // if k is 1, print current node's data
        cout << root->data << " ";
        return;
    }

    // recursively call for left and right subtrees with k-1
    printKthLevel2(root->left, k - 1);
    printKthLevel2(root->right, k - 1);
}


// My approach
void helper(Node* root, int k, int i){
    if(!root) return;          // base case: empty tree

    if(i == k){        
        cout << root->data << " ";
        return;
    }

    // recursively call for left and right subtrees with k-1
    helper(root->left, k, i + 1);
    helper(root->right, k, i + 1);
}

void printKthLevel(Node* root, int k){
    helper(root, k, 1);
}

int main(){
    vector<int> preOrder = {1, 2, -1, 4, -1, -1, 3, -1, 5, -1, -1};

    Node* root = buildTree(preOrder);

    int k = 3;   // level to print
    cout << "Nodes at level " << k << ": ";
    printKthLevel(root, k);
    cout << endl;

}