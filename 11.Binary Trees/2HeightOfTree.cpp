#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Height of a Binary Tree is defined as the number of edges on the longest path from the root node to a leaf node.\

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data=x;
        left=right=NULL;
    }
};

static int idx=-1;
Node* buildTree(vector<int> preOrder){
    idx++;
    if(preOrder[idx]==-1) return NULL;

    Node* root = new Node(preOrder[idx]);
    root->left=buildTree(preOrder);
    root->right=buildTree(preOrder);

    return root;
}


int height(Node* root){  // O(n)
    if(root==NULL) return 0;
    int leftH=height(root->left);
    int rightH=height(root->right);
    return max(leftH,rightH)+1;
}

int countNodes(Node* root){  // O(n)
    if(root==NULL) return 0;
    int leftCount=countNodes(root->left);
    int rightCount=countNodes(root->right);
    return leftCount + rightCount + 1;
}


int sumOfNodes(Node* root){  // O(n)
    if(root==NULL) return 0;
    int leftSum=sumOfNodes(root->left);
    int rightSum=sumOfNodes(root->right);
    return leftSum + rightSum + root->data;
}

void preOrderTraversal(Node* root){
    if(root==NULL) return;
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}


int main(){
    vector<int> preOrder={1,-20,-1,-1,30,400,-1,-1,500,6000,-1,-1,-1};
    Node* root=buildTree(preOrder);

    preOrderTraversal(root);
    cout << endl;

    int h=height(root);
    cout << "Height of the tree: " << h << endl;

    int totalNodes=countNodes(root);
    cout << "Total number of nodes: " << totalNodes << endl;

    int totalSum=sumOfNodes(root);
    cout << "Total sum of nodes: " << totalSum << endl;

    return 0;
}
