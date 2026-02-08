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


// Insert a new value into the BST
Node* insertBST(Node* root, int val){
    if(!root) return new Node(val);
    if(val<root->data) {
        root->left= insertBST(root->left,val);
    } else{ 
        root->right= insertBST(root->right,val);
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

Node* helper(vector<int>arr, int s, int e){
    if(s>e) return NULL;
    int m = (s+e)/2;
    Node* root = new Node(arr[m]);
    root->left = helper(arr, s, m-1);
    root->right = helper(arr, m+1, e);
    return root;
}

Node* BSTfromSortedArray(vector<int> arr){
    Node* root = helper(arr, 0, arr.size()-1);
    return root;
}


void inorder(vector<int> &arr, Node* root){
    if(!root) return;
    inorder(arr, root->left);
    arr.push_back(root->data);
    inorder(arr, root->right);
}

Node* merge(Node* r1, Node* r2){
    vector<int> arr1;
    vector<int> arr2;
    inorder(arr1, r1);
    inorder(arr2, r2);
    vector<int> temp;
    int i=0, j=0;
    while(i<arr1.size() && j<arr2.size()){
        if(arr1[i]<arr2[j]) temp.push_back(arr1[i++]);
        else temp.push_back(arr2[j++]);
    }
    while(i<arr1.size()) temp.push_back(arr1[i++]);
    while(j<arr2.size()) temp.push_back(arr2[j++]);

    Node* root = BSTfromSortedArray(temp);

    return root;
}
// Time Complexity: O(n+m) [n = nodes in r1, m = nodes in r2]

void inorder2(Node* root){
    if(!root) return;
    inorder2(root->left);
    cout << root->data << " ";
    inorder2(root->right);
}

int main(){
    vector<int> nums = {-10, -3, 0, 5, 9};
    vector<int> nums1 = {-12, -4, 1, 14, 80};
    Node* r1 = buildBST(nums);
    Node* r2 = buildBST(nums1);

    Node* root = merge(r1, r2);

    cout << "Inorder Traversal of the constructed BST: ";
    inorder2(root); // Should print values in sorted order: -10 -3 0 5 9
    cout << endl;

    return 0;
}