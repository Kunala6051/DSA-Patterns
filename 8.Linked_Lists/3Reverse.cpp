#include <iostream>
#include <cstring> 
#include <string> 
#include <vector>
#include <algorithm> 
#include <cmath> 

using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};  

class Solution {
public:
    // Function to reverse a singly linked list
    // Input: pointer to the head node of the list
    // Output: pointer to the new head (after reversal)
    ListNode* reverseList(ListNode* head) {
        
        // 'prev' will always point to the node that comes before 'curr' in the reversed list.
        // Initially, nothing is before the head, so set 'prev' = NULL
        ListNode* prev = NULL;

        // 'curr' is used to traverse the list, starting from head
        ListNode* curr = head;

        // 'next' is a temporary pointer to store the next node,
        // because when we reverse a link, we don’t want to lose the rest of the list
        ListNode* next = NULL;

        // Iterate until we reach the end of the list (when curr becomes NULL)
        while (curr != NULL) {
            // Step 1: Save the next node before breaking the link
            next = curr->next;

            // Step 2: Reverse the current node's pointer
            // Instead of pointing to the next node, it should point to the previous node
            curr->next = prev;

            // Step 3: Move 'prev' one step forward (to current node)
            prev = curr;

            // Step 4: Move 'curr' one step forward (to the saved 'next' node)
            curr = next;
        }

        // After the loop, 'prev' will be pointing to the new head of the reversed list
        return prev;
    }

    // Space Complexity: O(1) - We are reversing the list in place without using any extra space.
    // Time Complexity: O(n) - We are visiting each node exactly once.

};

int main(){
    Solution s;
    ListNode* head = new ListNode(1);  // Creating the linked list 1->2->3->4->5
    head->next = new ListNode(2);  
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode* reversedHead = s.reverseList(head);

    // Print the reversed list
    ListNode* temp = reversedHead;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}