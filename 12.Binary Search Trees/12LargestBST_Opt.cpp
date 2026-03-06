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

/*
APPROACH (Largest BST in a Binary Tree) — O(n)

Goal:
Find the size of the largest subtree that is also a Binary Search Tree.

Key Idea:
Instead of checking every subtree separately (which leads to O(n²)),
we solve the problem in ONE traversal using POSTORDER.

Why Postorder?
Because to decide whether a subtree rooted at a node is a BST,
we must first know information about its left and right subtrees.

For each subtree we return an object (Info) containing:
1. minVal → minimum value present in the subtree
2. maxVal → maximum value present in the subtree
3. sz     → size of the largest BST in this subtree

Steps at each node:

1. Recursively get Info from left subtree.
2. Recursively get Info from right subtree.

3. Check if current node can form a BST:
      left.maxVal < root->data < right.minVal

4. If true:
      The subtree rooted at this node is a valid BST.
      - new minimum = min(left.minVal, root->data)
      - new maximum = max(right.maxVal, root->data)
      - size = left.sz + right.sz + 1

5. If false:
      The subtree is NOT a BST.
      We propagate the size of the largest BST found in either child.

      To make sure the parent cannot treat this subtree as BST,
      we return invalid bounds:
          min = INT_MIN
          max = INT_MAX

      so that any parent comparison will fail the BST condition.

Base Case:
For NULL node:
    min = +∞
    max = -∞
    size = 0

This ensures that leaf nodes naturally satisfy the BST condition.

Why this works:
Every node is processed exactly once,
so the time complexity becomes O(n).

Space Complexity:
O(h) recursion stack where h = tree height.
*/

class Info{
  public:
    int minVal, maxVal, sz;   // min value, max value, and size of BST
    
    // constructor to initialize values
    Info(int mn, int mx, int s){
        minVal = mn;
        maxVal = mx;
        sz = s;
    }
};


Info helper(Node* root){
    
    // Base case: empty subtree
    // min = +∞ and max = -∞ so parent comparisons always succeed
    if(!root) 
        return Info(INT_MAX, INT_MIN, 0);
    
    // Recursively get information from left subtree
    Info left = helper(root->left);
    
    // Recursively get information from right subtree
    Info right = helper(root->right);
    
    // Check BST condition
    // current node must be greater than max of left subtree
    // and smaller than min of right subtree
    if(root->data > left.maxVal && root->data < right.minVal){
        
        // Compute new minimum value of this subtree
        int currMin = min(root->data, left.minVal);
        
        // Compute new maximum value of this subtree
        int currMax = max(root->data, right.maxVal);
        
        // Size of BST = size(left) + size(right) + current node
        int currSz = 1 + left.sz + right.sz;
        
        // Return updated information upward
        return Info(currMin, currMax, currSz);
    }
    
    // If BST condition fails:
    // This subtree is NOT a BST
    
    // Return invalid bounds so parent cannot treat it as BST
    // but keep the largest BST size found in children
    return Info(INT_MIN, INT_MAX, max(left.sz, right.sz));
}

int largestBst(Node *root) {
    
    // helper returns info about the whole tree
    // sz stores the largest BST size
    return helper(root).sz;
}

int main(){
    // preorder traversal of the tree (use -1 for NULL nodes)
    vector<int> values = {50,45,30,-1,-1,48,-1,-1,6,-1,-1};
    // The tree looks like this:
    //       50
    //      /  \
   //     45    6
   //    / \
  //    30  48
    int idx = -1;
    Node* root = buildTree(values, idx);
    cout<<largestBst(root)<<endl; // Output: 7 (the entire tree is a BST)
    
    return 0;
}