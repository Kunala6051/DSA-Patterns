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

//              1(0) d=0
//             /    \
// d=(0-1) 2(-1)   3(1) d=(0+1)
//            \         \
//            4(0)      5(2)

// for left child distance = (parent distance-1)
// for right child distance = (parent distance+1)
// if a distance has been met earlier like 0 at root all the nodes coming with 0 distance 
// will come under root i.e that node will not be seen from the top.

// Thats y we use a map(ordered one) so that if once a particular distance comes,
// that data of that node is stored in map along with the distance
// and when another node with same distance comes we must not update the value we just skip it

// WHY ORDRED MAP
// As we have to print the data from left to right(negative to positive)
// keys=distance (ascending order)
// Most negative most left most positive most right

// Prints the top view of the binary tree
void topView(Node* root){
    if(!root) return;

    queue<pair<Node*,int>> q;   // node with its horizontal distance
    map<int,int> m;            // stores first node at each distance

    q.push({root, 0});

    while(!q.empty()){
        Node* curr = q.front().first;
        int d = q.front().second;
        q.pop();

        // store first node seen at this distance
        if(m.find(d) == m.end()){ // O(log n)
            m[d] = curr->data;
        }

        if(curr->left){
            q.push({curr->left, d-1});
        }
        if(curr->right){
            q.push({curr->right, d+1});
        }
    }

    // print top view from leftmost to rightmost
    for(auto p : m){
        cout << p.second << " ";
    }
    cout << endl;
}
// Time complexity: O(nlog n)


// Prints the bottom view of the binary tree
void bottomView(Node* root){
    if(!root) return;

    queue<pair<Node*,int>> q;   // node with its horizontal distance
    map<int,int> m;            // stores first node at each distance

    q.push({root, 0});

    while(!q.empty()){
        Node* curr = q.front().first;
        int d = q.front().second;
        q.pop();

        m[d] = curr->data; // updating the latest value of that distance

        if(curr->left){
            q.push({curr->left, d-1});
        }
        if(curr->right){
            q.push({curr->right, d+1});
        }
    }

    // print bottom view from leftmost to rightmost
    for(auto p : m){
        cout << p.second << " ";
    }
    cout << endl;
}

int main(){
    vector<int> preOrder = {1, 2, -1, 4, -1, -1, 3, -1, 5, -1, -1};

    Node* root = buildTree(preOrder);

    cout << "Top View of Binary Tree: ";
    topView(root);

    cout << "Bottom View of Binary Tree: ";
    bottomView(root);

    return 0;
}
