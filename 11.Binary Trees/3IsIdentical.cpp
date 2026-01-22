#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Subtree of a Binary Tree is a tree consisting of a node in the tree and all of its descendants.

// Trees are identical if they have the same structure and node values.

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

bool isIdentical(Node* p, Node* q){
    if(!p || !q) return p==q;

    bool isLeftIdentical = isIdentical(p->left, q->left);
    bool isRightIdentical = isIdentical(p->right, q->right);

    return isLeftIdentical && isRightIdentical && p->data==q->data;
}



int main(){
    int idx=-1; // reset index for building the tree
    vector<int> tree1={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root1=buildTree(tree1, idx);

    // The tree looks like this:
    //        1
    //      /   \
    //     2     3
    //    / \     \
    //   4   5     6

    idx=-1; // reset index for building another tree
    vector<int> tree2={1,2,4,-1,-1,5,-1,-1,3,-1,-1};
    Node* root2=buildTree(tree2, idx);
    
    // The tree looks like this:
    //        1
    //      /   \
    //     2     3
    //    / \     
    //   4   5     

    cout << isIdentical(root1, root2);

    return 0;
}