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

// Morris Inorder Traversal (Iterative)

// Works on threading the tree and using no extra space
// Threading means making right child of inorder predecessor point to current node

// Inorder Predecessor (IP) of a node is the rightmost node in its left subtree
// Basically node existing before the current node in inorder traversal
// It is done so that we can go back to the root node everytime we finish left subtree traversal
// As it is not possible to go back to root node without using stack or recursion (in iterative approach)

// There are two cases of Morris Inorder Traversal:
// 1. If left child of current node is NULL, print current node and move to right child
// 2. If left child is not NULL, find IP of current node
        // If right child of IP is NULL, make current node as right child of IP and move to left child of current node (threading) 
        // So that we can come back to current node after left subtree traversal

        // If right child of IP is current node, it means left subtree is already visited (and we have already threaded the tree)
            // So, we revert the changes made (i.e., make right child of IP as NULL)
            // Print current node and move to right child of current node


void morrisInorder(Node* root){
    Node* curr= root;
    while(curr!=NULL){
        if(curr->left==NULL){
            cout << curr->data << " ";
            curr=curr->right;
        } else{
            // Find IP
            Node* IP=curr->left;
            while(IP->right!=NULL && IP->right!=curr){
                IP=IP->right;
            }
            // If IP is not connected to the root node (curr)
            if(IP->right==NULL){ 
                IP->right=curr; // Threading
                curr=curr->left;
            } 
            // If IP is already connected to the root node (curr)
            else{
                IP->right=NULL;
                cout << curr->data << " ";
                curr=curr->right;
            }
        }
    }
}
// Time Complexity: O(N)
// Each edge is traversed at most twice, so the time complexity is O(N)

// Space Complexity: O(1)


int main(){
     // Preorder traversal where -1 represents NULL
    vector<int> preOrder = {1, 3, 2, 5, -1, -1, 9, -1, -1, -1, 7, -1, -1};

    // Build the binary tree
    Node* root = buildTree(preOrder);

    morrisInorder(root);

    return 0;
}