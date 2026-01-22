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

// Lowest Common Ancestor in a Binary Tree
// Returns pointer to the lowest common ancestor of nodes with values p and q

// For example, in the following tree:
//         1
//        / \
//       2   3
//      / \   \
//     4   5   6

// The lowest common ancestor of nodes 4 and 5 is 2
// The lowest common ancestor of nodes 4 and 6 is 1
// The lowest common ancestor of nodes 3 and 6 is 3 (a node can be ancestor of itself)


// APPROACH: 
// 1. If the current node is NULL, return NULL.
// 2. If the current node matches either p or q, return the current node. (This means we found one of the nodes, so we return it up the call stack.)
//    Meaning if we find either p or q, we return that node up the recursion stack.
// 3. Recursively search for p and q in the left and right subtrees.
Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
    // Base case: if tree is empty
    if(!root) return NULL;

    // If current node is either p or q, return it
    if(root == p || root == q) return root;

    // Recur for left and right subtrees
    Node* leftLCA = lowestCommonAncestor(root->left, p, q);
    Node* rightLCA = lowestCommonAncestor(root->right, p, q);

    // If p and q are found in different subtrees, current node is LCA
    if(leftLCA && rightLCA) return root;

    // Otherwise return the non-null result
    else if(leftLCA == NULL && rightLCA == NULL) return NULL;
    else if(leftLCA == NULL && rightLCA != NULL) return rightLCA;
    else return leftLCA;
}
// Time Complexity: O(n) where n is the number of nodes in the binary tree.

// If we do dry run of the above code on the example tree, we can see how it works step by step.
// For example, in the following tree:
//         1
//        / \
//       2   3
//      / \   \
//     4   5   6'

// p = 4, q = 5 
// for node 1: leftLCA = call for node 2
//             for node 2: leftLCA = 4, rightLCA = 5   
//             returns node 2 to node 1
//             rightLCA = call for node 3
//             for node 3: leftLCA = NULL, rightLCA = NULL
//             returns NULL to node 1
//             since leftLCA = 2, rightLCA = NULL, returns node 2 as LCA


int main(){
    vector<int> preOrder = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* root = buildTree(preOrder);

    Node* p = root->left->left;   // Node with value 4
    Node* q = root->left->right;  // Node with value 5

    Node* lca = lowestCommonAncestor(root, p, q);

    if(lca){
        cout << "Lowest Common Ancestor of " << p->data << " and " << q->data << " is: " << lca->data << endl;
    } else {
        cout << "Lowest Common Ancestor not found." << endl;
    }

}