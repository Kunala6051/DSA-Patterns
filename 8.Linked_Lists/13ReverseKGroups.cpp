#include <iostream>
#include <cstring> 
#include <string> 
#include <vector>
#include <algorithm> 
#include <cmath> 

using namespace std;


// LEETCODE 25

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // 'temp' will traverse 'k' nodes ahead to check if there are at least 'k' nodes left
        ListNode* temp = head;
        int c = 0;

        // Step 1: Check if there are at least 'k' nodes to reverse
        while (c < k) {
            if (temp == NULL) 
                // If fewer than 'k' nodes remain, return head as it is (no reversal)
                return head;
            temp = temp->next;
            c++;
        }

        // Step 2: Recursively call reverseKGroup for the remaining list 
        // starting after 'k' nodes
        // The recursive call will reverse the rest of the list in groups of 'k'
        ListNode* prev = reverseKGroup(temp, k); 

        // Step 3: Reverse the current group of 'k' nodes
        temp = head; // Reset 'temp' to the start of the current group
        c = 0;

        while (c < k) {
            // Store next node before breaking the link
            ListNode* next = temp->next;

            // Reverse the link: current node now points to 'prev'
            temp->next = prev;

            // Move 'prev' and 'temp' one step forward
            prev = temp;
            temp = next;

            c++;
        }

        // Step 4: 'prev' is the new head of the reversed group
        return prev;
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

    int k = 2;
    ListNode* newHead = sol.reverseKGroup(head, k);

    // Print the reversed list
    ListNode* temp = newHead;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}
