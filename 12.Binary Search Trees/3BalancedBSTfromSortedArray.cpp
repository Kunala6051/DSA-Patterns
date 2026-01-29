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

// Leetcode 108

// In Balanced BST, the middle element of the sorted array becomes the root.

// As the array is sorted, all elements to the left of the middle element are smaller,
// and all elements to the right are larger, satisfying the BST property.

// Also, by choosing the middle element, we ensure that the tree remains balanced,
// as the left and right subtrees will have roughly equal numbers of nodes.

// Recursively do this for left and right subarrays to form left and right subtrees.


Node* helper(vector<int>& nums, int s, int e){
    if(s>e) return NULL;
    int m = (s+e)/2;
    Node* root = new Node(nums[m]);
    root->left = helper(nums, s, m-1);
    root->right = helper(nums, m+1, e);

    return root;
}

Node* sortedArrayToBST(vector<int>& nums) {
    return helper(nums, 0, nums.size()-1);
}

void inorder(Node* root){
    if(!root) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main(){
    vector<int> nums = {-10, -3, 0, 5, 9};
    Node* root = sortedArrayToBST(nums);

    cout << "Inorder Traversal of the constructed BST: ";
    inorder(root); // Should print values in sorted order: -10 -3 0 5 9
    cout << endl;

    return 0;
}