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


// BINARY SEARCH TREE (BST)

// A binary tree in which for each node:
// 1. The left subtree contains only nodes with values less than the node's value
// 2. The right subtree contains only nodes with values greater than the node's value
// 3. Both left and right subtrees are also binary search trees

// BSTs do not contain duplicate values
// BSTs allow for efficient searching, insertion, and deletion operations

// Time Complexity for search, insert, delete: O(h) where h is the height of the tree
// In average case, h = O(log N) for balanced BSTs

// Inorder traversal of a BST gives sorted order of elements


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
// Time Complexity: O(N log N) for inserting N elements (average case)

void inorder(Node* root){
    if(!root) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

bool searchBST(Node* root, int key){
    if(!root) return false;
    if(root->data==key) return true;
    if(key<root->data) return searchBST(root->left,key);
    else return searchBST(root->right,key);
}
// Time Complexity: O(h) where h is the height of the tree
// In Balanced BST, O(log N) 
// Balanced BSt means height of left and right subtree differ by at most 1 for every node


int main(){
    vector<int> values = {5,3,8,1,4,7,9};
    Node* root = buildBST(values);

    inorder(root); // Should print values in sorted order: 1 3 4 5 7 8 9
    cout << endl;

    cout << searchBST(root,90) << endl;
    cout << searchBST(root,9) << endl;

    return 0;
}