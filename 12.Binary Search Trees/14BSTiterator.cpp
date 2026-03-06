
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};

// Leetcode 173. Binary Search Tree Iterator

/*
APPROACH (Using Inorder Traversal + Vector)

Goal:
Design an iterator that returns the next smallest element in a BST.

Key Idea:
In a Binary Search Tree (BST), performing an INORDER traversal
(left → root → right) gives elements in sorted order.

Steps:

1. Store BST in sorted order
   - Perform an inorder traversal of the tree.
   - Store each node value in a vector.
   - This creates a sorted array of elements.

2. Maintain a pointer/index
   - Use an index `i` to track the current position in the vector.

3. next()
   - Return the element at index `i`
   - Increment `i`

4. hasNext()
   - Check whether `i < vector.size()`
   - If yes → more elements exist.

Complexity:

Time Complexity
Constructor: O(N) (full inorder traversal)
next(): O(1)
hasNext(): O(1)

Space Complexity
O(N) because we store all nodes in a vector.

This approach is simple but uses extra memory.
*/


class BSTIteratorVector {

    vector<int> v;   // stores inorder traversal (sorted values)
    int i;           // pointer to current index

    void inorder(TreeNode* root, vector<int>& v){
        if(!root) return;   // base case: if node is NULL stop
        inorder(root->left, v);   // visit left subtree
        v.push_back(root->val);   // store root value
        inorder(root->right, v);  // visit right subtree
    }

public:

    BSTIteratorVector(TreeNode* root) {
        i = 0;             // iterator starts from first element
        inorder(root, v);  // fill vector with sorted values
    }

    int next() {
        return v[i++];     // return current element and move pointer
    }

    bool hasNext() {
        if(i < v.size())   // if pointer is still inside vector
            return true;

        return false;      // otherwise no more elements
    }
};

/*
APPROACH (Optimized using Stack)

Goal:
Return BST elements in sorted order WITHOUT storing entire tree.

Key Idea:
Simulate inorder traversal using a stack.

Important Observation:
In inorder traversal we go as LEFT as possible first.

Steps:

1. Constructor
   - Push all LEFT nodes starting from root into the stack.
   - The top of the stack will be the smallest element.

2. next()
   - Pop the top node (this is the next smallest element).
   - If that node has a RIGHT child:
        → push all LEFT nodes from that right subtree.

3. hasNext()
   - If stack is not empty → elements remain.

Why this works:
The stack always stores the path to the next smallest node.

Example Stack Content:
top → next smallest node

Complexity:

Time Complexity
Constructor: O(H)
next(): amortized O(1)
hasNext(): O(1)

Space Complexity
O(H) where H = tree height

This is the optimal solution.
*/

class BSTIteratorStack {
    stack<TreeNode*> s;   // stack to simulate inorder traversal
public:

    BSTIteratorStack(TreeNode* root) {
        // push all left nodes of tree into stack
        while(root){
            s.push(root);     // store node
            root = root->left;  // move left
        }
    }

    int next() {
        TreeNode* t = s.top();  // get smallest node
        s.pop();                // remove it from stack

        // if right subtree exists
        if(t->right){
            TreeNode* temp = t->right;
            // push all left nodes of right subtree
            while(temp){
                s.push(temp);
                temp = temp->left;
            }
        }

        return t->val;   // return next smallest value
    }

    bool hasNext() {
        return !s.empty();   // if stack not empty → more nodes exist
    }
};

int main(){

    /*
           7
         /   \
        3     15
             /  \
            9    20
    */

    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);


    cout<<"Using Vector Iterator:"<<endl;

    BSTIteratorVector it1(root);

    while(it1.hasNext()){
        cout<<it1.next()<<" ";
    }
    cout<<endl;


    cout<<"Using Stack Iterator:"<<endl;

    BSTIteratorStack it2(root);

    while(it2.hasNext()){
        cout<<it2.next()<<" ";
    }

    cout<<endl;

}