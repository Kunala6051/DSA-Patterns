#include <iostream>
#include <cstring> 
#include <string> 
#include <vector>
#include <algorithm> 
#include <cmath> 

using namespace std;

// MY TRY OF FLATTENING A MULTILEVEL DOUBLY LINKED LIST
// LEETCODE 430

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    // Definition assumed:
    // Each node has: data, prev pointer, next pointer, and child pointer
    // Goal: Flatten the multilevel doubly linked list into a single-level list

    Node* flatten(Node* head) {
        // Pointer to traverse the main list
        Node* temp = head;

        // Iterate through the entire list
        while (temp != NULL) {

            // Case 1: If current node has a child, we need to flatten that child list
            if (temp->child != NULL) {

                // Store the next node temporarily (since we're going to change temp->next)
                Node* temp2 = temp->next;

                // Recursively flatten the child list and get its head
                Node* temp3 = flatten(temp->child);

                // Remove the child link (since it will now be part of the main list)
                temp->child = NULL;

                // Connect current node to the flattened child list
                temp->next = temp3;
                if (temp3 != NULL) 
                    temp3->prev = temp;   // Maintain doubly linked structure

                // Move to the end of the newly added (flattened) child list
                while (temp->next != NULL) {
                    temp = temp->next;
                }

                // Reconnect the saved next part of the original list
                temp->next = temp2;
                if (temp2 != NULL)
                    temp2->prev = temp;   // Maintain doubly linked structure

            } 
            // Case 2: If current node has no child, simply move to the next node
            else {
                temp = temp->next;
            }
        }

        // Return the head of the fully flattened list
        return head;
    }
};

int main() {
    // Example usage (not part of the solution, just for demonstration)
    Solution sol;
    Node* head = new Node();
    head->val = 1;
    head->next = new Node();
    head->next->val = 2;
    head->child = new Node();
    head->child->val = 3;
    head->child->next = new Node();
    head->child->next->val = 4;

    Node* flattenedHead = sol.flatten(head);

    // Print the flattened list
    Node* temp = flattenedHead;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}