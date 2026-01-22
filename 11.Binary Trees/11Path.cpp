#include <iostream>
#include <vector>
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

// Helper function to collect all root-to-leaf paths
void allPaths(Node* root, string curr, vector<string>& v){
    // If leaf node, store the complete path
    if(!root->left && !root->right){
        v.push_back(curr);
        return;
    }

    // Traverse left subtree if exists
    if(root->left)
        allPaths(root->left, curr + "->" + to_string(root->left->data), v);

    // Traverse right subtree if exists
    if(root->right)
        allPaths(root->right, curr + "->" + to_string(root->right->data), v);
}

// Main function to return all root-to-leaf paths
vector<string> binaryTreePaths(Node* root) {
    vector<string> v;
    string s;

    // Start path with root value
    if(root) s += to_string(root->data);

    // Generate all root-to-leaf paths
    allPaths(root, s, v);

    return v;
}
// time complexity: O(N)

int main() {
    // Preorder traversal where -1 represents NULL
    vector<int> preOrder = {3,9,-1,-1,20,15,-1,-1,7,-1,-1};

    // Build binary tree
    Node* root = buildTree(preOrder);

    // Get all root-to-leaf paths
    vector<string> paths = binaryTreePaths(root);

    // Print all paths
    cout << "Root-to-leaf paths:" << endl;
    for (const string& path : paths) {
        cout << path << endl;
    }

    return 0;
}
