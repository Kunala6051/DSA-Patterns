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
    // Function to merge two sorted linked lists into one sorted list
    ListNode* mergeTwoLists(ListNode* h1, ListNode* h2) {
        // Base case 1: if first list is empty, return second list
        if (h1 == NULL) return h2;

        // Base case 2: if second list is empty, return first list
        if (h2 == NULL) return h1;

        // Recursive case:
        // Compare the values of the two current nodes (h1 and h2)

        if (h1->val <= h2->val) {
            // If h1's value is smaller (or equal):
            // - Attach h1->next to the merged result of (h1->next, h2)
            // - This keeps h1 in front since it's smaller
            h1->next = mergeTwoLists(h1->next, h2);

            // Return h1 because it's the smaller node
            return h1;
        } else {
            // If h2's value is smaller:
            // - Attach h2->next to the merged result of (h1, h2->next)
            // - This keeps h2 in front since it's smaller
            h2->next = mergeTwoLists(h1, h2->next);

            // Return h2 because it's the smaller node
            return h2;
        }
    }
};
// Time Complexity: O(n + m) where n and m are the lengths of the two lists
// Space Complexity: O(n + m) due to recursive call stack


int main(){
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(3);
    head1->next->next = new ListNode(5);

    ListNode* head2 = new ListNode(2);
    head2->next = new ListNode(4);
    head2->next->next = new ListNode(6);

    Solution sol;
    ListNode* mergedHead = sol.mergeTwoLists(head1, head2);

    // Print the merged linked list
    ListNode* temp = mergedHead;
    while (temp != NULL) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    return 0;
}