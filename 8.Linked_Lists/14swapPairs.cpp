#include <iostream>
#include <cstring> 
#include <string> 
#include <vector>
#include <algorithm> 
#include <cmath> 

using namespace std;


// LEETCODE 24

// Definition for singly-linked list is assumed as:
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

        // Base case: if the list is empty or has only one node,
        // there’s nothing to swap, so return the head as is.
        if (head == NULL || head->next == NULL)
            return head;

        // 'prev' keeps track of the last node of the previous swapped pair.
        // It helps link the previous pair with the current swapped pair.
        ListNode* prev = NULL;

        // 'first' points to the first node of the current pair
        ListNode* first = head;

        // 'sec' points to the second node of the current pair
        ListNode* sec = head->next;

        // Loop runs as long as both 'first' and 'sec' exist
        while (first != NULL && sec != NULL) {

            // 'third' stores the node after the current pair (the start of the next pair)
            ListNode* third = sec->next;

            // Step 1: Reverse the current pair
            // Make the second node point to the first node
            sec->next = first;

            // Step 2: Make the first node point to the next pair's first node
            first->next = third;

            // Step 3: Connect the previous pair with the current swapped pair
            // If this is not the first pair (prev != NULL), connect 'prev->next' to 'sec'
            if (prev != NULL)
                prev->next = sec;
            else
                // If this is the first swap, update 'head' to the new head (which is 'sec')
                head = sec;

            // Step 4: Move 'prev' to the last node of the current pair (which is 'first' after swap)
            prev = first;

            // Step 5: Move 'first' to the start of the next pair
            first = third;

            // Step 6: If the next pair exists, update 'sec' to point to its second node
            // Otherwise, set it to NULL to stop the loop
            if (third != NULL)
                sec = third->next;
            else
                sec = NULL;
        }

        // Return the new head of the swapped list
        return head;
    }
};


int main() {
    // Example usage:
    Solution sol;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode* newHead = sol.swapPairs(head);

    // Print the swapped list
    ListNode* temp = newHead;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}