#include <iostream>
#include <climits>
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



// LeetCode: 99. Recover Binary Search Tree

// You are given the root of a binary search tree (BST), where the values of exactly 
// two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.


// Approach:

// Uses inorder traversal to find the two swapped nodes
// Inorder traversal of a BST gives sorted order, so we can find the two nodes that are out of order
// We keep track of the previous node visited during inorder traversal
// If we find a node that is smaller than the previous node, it means there is a violation of the BST property
// We can have two cases:
// 1. The two swapped nodes are adjacent in the inorder traversal (e.g., 1, 3, 2, 4)
//    In this case, we will find only one violation (3 > 2), and the two nodes to swap are the previous node (3) and the current node (2).
// 2. The two swapped nodes are not adjacent (e.g., 1, 4, 3, 2, 5)
//    In this case, we will find two violations (4 > 3 and 3 > 2), and the two nodes to swap are the previous node of the first violation (4) and the current node of the second violation (2).
// After finding the two nodes, we can simply swap their values to recover the BST.

// Basicaly, in case 1, we will just find one pair (first and second)
// In case 2, we will find two pairs (frst1 and sec1, and frst2 and sec2) (4,3 and 3,2)
// But we just want frst1 and sec2 (4 and 2) to swap, 
// so we can just keep track of the first node of the first violation (frst1) and the second node of 
// the second violation (sec2) and swap them at the end. 

// So when we find a violation, we will check if frst1 is already set or not. 
// If not, we will set frst1 to the previous node and sec2 to the current node. If frst1 is already set, we will just update sec2 to the current node. 
// This way, at the end of the traversal, we will have frst1 and sec2 as the two nodes to swap.

Node* pre = NULL;    // previous node in inorder traversal
Node* first = NULL;   // first misplaced node
Node* sec = NULL;     // second misplaced node

void inorder(Node* root) {
    if (!root) return;

    inorder(root->left);   // visit left subtree

    // detect violation of inorder property
    if (pre != NULL && pre->data > root->data) {
        if (!first) first = pre;  // first wrong node
        sec = root;                // second wrong node
    }

    pre = root;          // update previous node
    inorder(root->right); // visit right subtree
}

void recoverTree(Node* root) {
    inorder(root);        // find swapped nodes
    int t = first->data;   // swap their values
    first->data = sec->data;
    sec->data = t;
}

void inorder2(Node* root) {
    if (!root) return;
    inorder2(root->left);
    cout << root->data << " ";
    inorder2(root->right);
}



int main() {
    // manually create swapped BST
    //       3
    //      / \
    //     1   4
    //        /
    //       2   (swapped)
    Node* root = new Node(3);
    root->left = new Node(1);
    root->right = new Node(4);
    root->right->left = new Node(2);

    cout << "Before recovery: ";
    inorder2(root);   // 1 3 2 4

    recoverTree(root);

    cout << "\nAfter recovery: ";
    inorder2(root);   // 1 2 3 4

    return 0;
}