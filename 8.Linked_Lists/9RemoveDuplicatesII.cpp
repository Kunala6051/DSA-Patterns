#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
  
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // Edge case: if list is empty, just return NULL
        if (head == NULL) return NULL;

        ListNode* prev = NULL;   // Tracks the last node of the "clean" list (unique nodes only)
        ListNode* temp = head;   // Traverses the list

        // Traverse the linked list
        while (temp != NULL) {

            // Case 1: Current node has duplicates (next node has same value)
            if (temp->next != NULL && temp->next->val == temp->val) {
                
                // Skip all nodes that have the same value as temp->val
                while (temp->next != NULL && temp->next->val == temp->val) { 
                    temp = temp->next;   // Move until the last duplicate node
                }

                // Move one more step to reach the node after duplicates
                temp = temp->next;

                // If duplicates started at the head, update head
                if (prev == NULL) {
                    head = temp;
                } 
                // Otherwise, link the previous "clean" node to the node after duplicates
                else {
                    prev->next = temp;
                }
            } 
            // Case 2: Current node is unique (no duplicates)
            else {
                prev = temp;         // Mark this node as part of the result
                temp = temp->next;   // Move forward
            }
        }

        // Return updated head of the list (dummy not used, direct update)
        return head;
    }
};

int main() {
    Solution sol;

    // Creating a linked list: 1 -> 2 -> 3 -> 3 -> 4 -> 4 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next->next = new ListNode(5);

    // Deleting duplicates
    ListNode* result = sol.deleteDuplicates(head);

    // Printing the resulting linked list
    while (result != NULL) {
        cout << result->val << " ";
        result = result->next;
    }
    
    return 0;
}
