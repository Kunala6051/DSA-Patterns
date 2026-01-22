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

// LeetCode: 662. Maximum Width of Binary Tree

// Maximum width is defined as the maximum number of nodes between the leftmost and rightmost non-null nodes at any level, including null nodes in between.
// Null nodes are represented by their position in a complete binary tree.

// Complete binary tree: In a complete binary tree, every level, except possibly the last, has two children.

// Complete binary tree indexing:
// - Root node is at index 0
// - For any node at index i, left child is at index 2*i + 1 and right child is at index 2*i + 2

// APPROACH:
// We perform a level order traversal (BFS) of the tree while keeping track of the indices of nodes as if they were in a complete binary tree.
// We will assume these nodes are indexed starting from 0 for each level.
// At each level, we calculate the width as the difference between the maximum and minimum indices of nodes at that level plus one.

// Example:
// Consider the binary tree:
//         1
//       /   \
//      3     2
//     / \     \
//    5   3     9

// Level 0: [1] -> indices [0] -> width = 1
// Level 1: [3, 2] -> indices [1, 2] -> width = 2
// Level 2: [5, 3, null, 9] -> indices [3, 4, 5, 6] -> width = 6 - 3 + 1 = 4
// No matter the node is present or null, we consider its position in a complete binary tree for width calculation.

int widthOfBinaryTree(Node* root) {
    // Queue stores node along with its index (as in array representation)
    queue<pair<Node*, unsigned long long>> q;
    q.push({root, 0});

    int maxWid = 0;

    // Level order traversal
    while (!q.empty()) {
        int currSize = q.size();                 // number of nodes at current level
        unsigned long long stIdx = q.front().second; // index of first node in level
        unsigned long long endIdx = q.back().second; // index of last node in level

        // width of current level = last index - first index + 1
        maxWid = max(maxWid, (int)(endIdx - stIdx + 1));

        // process all nodes of current level
        for (int i = 0; i < currSize; i++) {
            TreeNode* curr = q.front().first;
            unsigned long long idx = q.front().second;
            q.pop();

            // push left child with its calculated index
            if (curr->left) q.push({curr->left, 2 * idx + 1});

            // push right child with its calculated index
            if (curr->right) q.push({curr->right, 2 * idx + 2});
        }
    }

    return maxWid;   // maximum width found
}
// Time complexity: O(N)


int main() {
    // Preorder traversal where -1 represents NULL
    vector<int> preOrder = {1, 3, 2, 5, -1, -1, 9, -1, -1, -1, 7, -1, -1};

    // Build the binary tree
    Node* root = buildTree(preOrder);

    // Calculate the maximum width of the binary tree
    int maxWidth = widthOfBinaryTree(root);

    // Output the result
    cout << "Maximum Width of the Binary Tree: " << maxWidth << endl;

    return 0;
}