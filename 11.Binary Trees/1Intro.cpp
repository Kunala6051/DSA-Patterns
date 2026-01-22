#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Binary Tree are hierarchical data structures where each node has at most two children.
// They are widely used in various applications such as expression parsing, searching algorithms, and hierarchical data representation.

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
// time complexity: O(n)
// space complexity: O(h) where h is the height of the tree due to recursive stack


// Traversal Techniques:   

// 1. Pre-order Traversal (Root, Left, Right)
// 2. In-order Traversal (Left, Root, Right)
// 3. Post-order Traversal (Left, Right, Root)
// 4. Level-order Traversal (Breadth-First)  (Iterative)

void preOrderTraversal(Node* root){
    if(root==NULL) return;
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void inOrderTraversal(Node* root){
    if(root==NULL) return;
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

void postOrderTraversal(Node* root){
    if(root==NULL) return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

// BFS
void levelOrderTraversalbyBFS(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* curr=q.front();
        if(curr!=NULL) cout << curr->data << " ";
        q.pop();
        if(curr==NULL){
            if(!q.empty()) {
                cout << endl;
                q.push(NULL);
                continue;
            }
            else break;
        }
        if(curr->left!=NULL) q.push(curr->left);
        if(curr->right!=NULL) q.push(curr->right);
    }
}

int main(){
    vector<int> preOrder={1,2,-1,-1,3,4,40,-1,-1,-1,5,-1,-1};

    Node* root=buildTree(preOrder);

    cout<<"Root Node: "<<root->data<<endl;
    cout<<"Left Child of Root: "<<root->left->data<<endl;
    cout<<"Right Child of Root: "<<root->right->data<<endl; 

    cout << "Tree in Pre-Order Traversal: ";
    preOrderTraversal(root);
    cout << endl;
    
    cout << "Tree in In-Order Traversal: ";
    inOrderTraversal(root);
    cout << endl;

    cout << "Tree in Post-Order Traversal: ";
    postOrderTraversal(root);
    cout << endl;

    cout << "Tree in Level-Order Traversal: ";
    levelOrderTraversalbyBFS(root);
    cout << endl;


    return 0;
}