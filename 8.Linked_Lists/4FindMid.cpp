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
   
    ListNode* findMidBrute(ListNode* head) {
        ListNode* temp = head;
        int sz=0;
        while(temp!=NULL){
            temp = temp->next;
            sz++;
        }
        
        int mid = (sz/2);
        temp = head;
        for(int i=0; i<mid; i++){
            temp=temp->next;
        }
        return temp;
    }

    ListNode* findMidOptimized(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* deleteMiddle(ListNode* head) {
        if (head == NULL || head->next == NULL) return NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = nullptr;
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }

        //delete node
        prev->next = slow->next;

        return head;
    }

};

int main(){
    Solution s;
    ListNode* head = new ListNode(1);  // Creating the linked list 1->2->3->4->5
    head->next = new ListNode(2);  
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode* mid = s.findMidOptimized(head);

    // Print the middle element
    if (mid != NULL) {
        cout << "Middle element: " << mid->val << endl;
    } else {
        cout << "List is empty." << endl;
    }

    head = s.deleteMiddle(head); // parameter head, deletes mid, returns head of new list

    // Print the modified list
    ListNode* temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}