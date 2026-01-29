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



// Insert a new value into the BST
Node* insertBST(Node* root, int data){
    if(!root) return new Node(data);
    if(data<root->data) {
        root->left= insertBST(root->left,data);
    } else{ 
        root->right= insertBST(root->right,data);
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


// DELETING A NODE FROM BST

// APPROACH:
// 1. If the node to be deleted is a leaf node, simply remove it.
// 2. If the node to be deleted has one child, replace it with its Non-NULL child.
// 3. If the node to be deleted has two children, find its inorder successor (smallest in the right subtree),
//    copy the inorder successor's content to this node and delete the inorder successor.

// Inorder Successor: The node with the smallest value in the right subtree of the node to be deleted.
//     i.e the leftmost node in the right subtree.
//     consider the following tree:
//         5
//        / \
//       3   8
//      / \   \
//     2   4   9
//        / \
//       3.5  4.5

//     If we want to delete 3, its inorder successor is 3.5 (the smallest node in its right subtree).
//     Inorder Traversal: [2, 3, 3.5, 4, 4.5, 5, 8, 9]
//     Inorder successor is the next node in this sorted order.(3.5)
//     We replace 3 with 3.5 and then delete the original 3.5 node.
//     The modified tree will be: [2, 3.5, 4, 4.5, 5, 8, 9]  (Maintains BST properties)

// Inorder Successor will always have at most one child (right child) because it is the leftmost node in the right subtree.
// So deleting it is very easy (either leaf node or one child case).


// Find inorder successor (minimum value node in a subtree)
Node* inorderSuccessor(Node* root){
    if(root->left == NULL)        // leftmost node is successor
        return root;
    return inorderSuccessor(root->left);
}

Node* deleteNode(Node* root, int key) {
    if(!root)                     // empty tree
        return NULL;

    if(root->data == key) {        // node to delete found

        // Case 1: node has both left and right child
        if(root->left != NULL && root->right != NULL){
            Node* InSucc = inorderSuccessor(root->right); // find inorder successor
            root->data = InSucc->data;                           // copy successor value
            root->right = deleteNode(root->right, InSucc->data); // delete successor
            // Will find successor in right subtree and delete it

        // Case 2: only right child
        } else if(root->right != NULL){
            Node* t = root->right;
            delete root;
            return t;

        // Case 3: only left child
        } else if(root->left != NULL){
            Node* t = root->left;
            delete root;
            return t;

        // Case 4: leaf node
        } else{
            delete root;
            return NULL;
        }

    } 
    // If key is smaller, go left
    else if (root->data > key){
        root->left = deleteNode(root->left, key);
    } 
    // If key is larger, go right
    else {
        root->right = deleteNode(root->right, key);
    }

    return root;                  // return updated root
}
// Time Complexity: O(h) where h is the height of the tree
// In Balanced BST, O(log N)


int main(){
    vector<int> values = {5,3,8,1,4,7,9};
    Node* root = buildBST(values);

    cout << "Inorder before deletion: ";
    inorder(root); // Should print values in sorted order: 1 3 4 5 7 8 9
    cout << endl;

    int key = 3;
    root = deleteNode(root, key);

    cout << "Inorder after deleting " << key << ": ";
    inorder(root); // Should print values in sorted order without 3: 1 4 5 7 8 9
    cout << endl;

    return 0;
}