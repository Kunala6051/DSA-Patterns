#include <iostream>
#include <climits>
#include <vector>
#include <queue>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data=x;
        left=right=NULL;
    }
};

Node* buildTree(vector<int> preOrder, int& idx){
    idx++;
    if(preOrder[idx]==-1) return NULL;

    Node* root = new Node(preOrder[idx]);
    root->left=buildTree(preOrder, idx);
    root->right=buildTree(preOrder, idx);

    return root;
}


// LeetCode: 333. Largest BST Subtree
// Given a binary tree, find the size of the largest subtree which is also a Binary Search Tree (BST).

// Brute Force Approach:
// - For each node, check if the subtree rooted at that node is a BST
// - If it is a BST, calculate its size and update the maximum size found so far
// - If it is not a BST, recursively check the left and right subtrees
int size(Node* root){
    if(!root) return 0;
    return 1 + size(root->left) + size(root->right);
}
void inorder(Node* root, vector<int> &v){
    if(!root) return;
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}

bool validBST(Node* root) {
    vector<int> v;
    inorder(root,v);
    
    for(int i=0; i<v.size()-1; i++){
        if(v[i]>=v[i+1]) return false;
    }
    return true;

}
int largestBst(Node *root) {
    // Your code here
    if(!root) return 0;
    if(validBST(root)) return size(root);
    return max(largestBst(root->left), largestBst(root->right));
    
}

int main(){
    // preorder traversal of the tree (use -1 for NULL nodes)
    vector<int> values = {50,45,30,-1,-1,48,-1,-1,6,-1,-1};
    // The tree looks like this:
    //       50
    //      /  \
   //     45    6
   //    / \
  //    30  70
    int idx = -1;
    Node* root = buildTree(values, idx);
    cout<<largestBst(root)<<endl; // Output: 7 (the entire tree is a BST)
    return 0;
}