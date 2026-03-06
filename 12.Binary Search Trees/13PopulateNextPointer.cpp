#include <iostream>
#include <queue>
using namespace std;

// Definition for Node
struct Node {
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node(int x){
        val = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};

// LeetCode 116. Populating Next Right Pointers in Each Node

/*
APPROACH 

Goal:
Connect each node of the binary tree with its NEXT RIGHT node
in the same level using the 'next' pointer.

Example Tree

        1
      /   \
     2     3
    / \   / \
   4  5  6   7

After connecting:

1 -> NULL
2 -> 3 -> NULL
4 -> 5 -> 6 -> 7 -> NULL


Key Idea:
We perform LEVEL ORDER TRAVERSAL (BFS).
To know when a level ends, we use a NULL marker.

Queue Structure Example:
Initially
Queue = [1, NULL]
NULL represents the end of a level.

Algorithm Steps:
1. If root is NULL → return NULL.
2. Push root into queue.
3. Push NULL after root to mark end of level.

Queue:
[ root , NULL ]

4. Start BFS loop while queue is not empty.
5. Pop the front element.
6. If the element is NULL:
      - It means current level ended.
      - If queue still has nodes → push another NULL
        to mark end of next level.
      - If queue empty → traversal finished.

7. If element is NOT NULL:
      - Set its next pointer to queue.front()
      - Because the next element in queue is the
        next node of same level (or NULL if last node).

8. Push its children into queue.
9. Continue until queue becomes empty.

Time Complexity:
O(N) → each node visited once.

Space Complexity:
O(N) → queue stores nodes level by level.
*/

Node* connect(Node* root) {

    // if tree is empty
    if(!root) return NULL;
    queue<Node*> q;  // queue used for BFS
    q.push(root);    // push root node
    q.push(NULL);    // NULL marker indicates end of level


    while(!q.empty()){
        // take front element
        Node* f = q.front();
        q.pop();   // remove it from queue

        // if we encounter NULL marker
        if(f == NULL){
            // if queue still has nodes
            if(!q.empty()){
                // push another NULL to mark end of next level
                q.push(NULL);
                continue;
            }
            // if queue empty → traversal finished
            else break;
        }

        // connect current node to next node in queue
        f->next = q.front();

        // push left child if it exists
        if(f->left)
            q.push(f->left);

        // push right child if it exists
        if(f->right)
            q.push(f->right);
    }
    return root;  // return root after connections
}




// Utility function to print next pointers level-wise
void printLevels(Node* root){
    while(root){
        Node* curr = root;
        while(curr){
            cout<<curr->val<<" -> ";
            curr = curr->next;
        }
        cout<<"NULL"<<endl;
        root = root->left; // move to next level
    }
}



int main(){

    /*
            1
          /   \
         2     3
        / \   / \
       4  5  6   7
    */

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);


    // connect nodes at same level
    connect(root);


    // print next pointers
    printLevels(root);

}