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

// Morris Inorder Traversal
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
            if(IP->right==NULL){
                IP->right=curr;
                curr=curr->left;
            } else{
                IP->right=NULL;
                cout << curr->data << " ";
                curr=curr->right;
            }
        }
    }
}


int main(){
     // Preorder traversal where -1 represents NULL
    vector<int> preOrder = {1, 3, 2, 5, -1, -1, 9, -1, -1, -1, 7, -1, -1};

    // Build the binary tree
    Node* root = buildTree(preOrder);

    morrisInorder(root);

    return 0;
}