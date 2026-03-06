#include <iostream>
#include <vector>
using namespace std;

// Definition of BST Node
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

/*
APPROACH 

Goal:
Find the **Predecessor** and **Successor** of a given key in a BST.

Definitions:

Predecessor:
The largest value in the BST that is **smaller than the key**.

Successor:
The smallest value in the BST that is **greater than the key**.


Example BST

            50
          /    \
        30      70
       /  \    /  \
     20   40  60   80

For key = 50

Predecessor = 40
Successor   = 60


Key BST Property:
Left subtree values < Root < Right subtree values

We use this property to search efficiently.


Step 1:
Start traversing the tree from the root.

Maintain two pointers:
pre  → predecessor
succ → successor

Initially both are NULL.


Step 2:
If key < current node value

Then current node could be the successor
because it is larger than the key.

So:
succ = curr

Move LEFT to search for a smaller successor.


Step 3:
If key > current node value

Then current node could be the predecessor
because it is smaller than the key.

So:
pre = curr

Move RIGHT to search for a larger predecessor.


Step 4:
If key == current node value

Now we check its subtrees.

Predecessor:
Largest value in LEFT subtree.

So go left once, then keep going right.


Successor:
Smallest value in RIGHT subtree.

So go right once, then keep going left.


Step 5:
Return both nodes in a vector.

v[0] = predecessor
v[1] = successor


========================= COMPLEXITY =========================

Time Complexity:
O(H)

H = height of tree

Space Complexity:
O(1)
*/

vector<Node*> findPreSuc(Node* root, int key) {

    Node* curr = root;   // start traversal from root

    Node* pre = NULL;    // will store predecessor

    Node* succ = NULL;   // will store successor


    // traverse the tree
    while(curr){

        // if key is smaller than current node
        if(key < curr->data){

            // current node may be successor
            succ = curr;

            // move left to find smaller candidate
            curr = curr->left;
        }

        // if key is greater than current node
        else if(key > curr->data){

            // current node may be predecessor
            pre = curr;

            // move right to find larger candidate
            curr = curr->right;
        }

        // if key is found
        else if(key == curr->data){

            // find predecessor in left subtree
            Node* t = curr->left;

            // move to the rightmost node
            while(t && t->right){
                t = t->right;
            }

            // if such node exists, update predecessor
            if(t) pre = t;


            // find successor in right subtree
            t = curr->right;

            // move to the leftmost node
            while(t && t->left){
                t = t->left;
            }

            // if such node exists, update successor
            if(t) succ = t;

            break;
        }
    }

    // store results in vector
    vector<Node*> v;

    v.push_back(pre);   // first element = predecessor

    v.push_back(succ);  // second element = successor

    return v;
}



int main(){

    Node* root = new Node(50);

    root->left = new Node(30);
    root->right = new Node(70);

    root->left->left = new Node(20);
    root->left->right = new Node(40);

    root->right->left = new Node(60);
    root->right->right = new Node(80);

    int key = 50;

    vector<Node*> ans = findPreSuc(root, key);

    cout << "Predecessor: ";
    if(ans[0]) cout << ans[0]->data;
    else cout << "NULL";

    cout << endl;

    cout << "Successor: ";
    if(ans[1]) cout << ans[1]->data;
    else cout << "NULL";

    cout << endl;

}