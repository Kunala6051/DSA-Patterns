#include <iostream>

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
    bool hasCycle(ListNode *head) {
        ListNode * slow = head;
        ListNode * fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast) return true;
        }
        return false;
    }

    ListNode *detectCycle(ListNode *head) {
        ListNode *slow=head;
        ListNode *fast=head;
        bool x=false;

        while(fast!=NULL && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                x=true;
                break;
            }
        }
        if(x){
            slow=head;
            while(slow!=fast){
                slow=slow->next;
                fast=fast->next;
            }
            return slow;
        }
        return NULL;
    }

    ListNode *detectNdRemoveCycle(ListNode *head) {
        ListNode *slow=head;
        ListNode *fast=head;
        bool x=false;

        while(fast!=NULL && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                x=true;
                break;
            }
        }
        if(!x) return head;
        
        slow=head;
        ListNode* prev = nullptr; // To keep track of the node before fast

        while(slow!=fast){
            slow=slow->next;
            prev=fast;
            fast=fast->next;
            
        }
        prev->next=nullptr; // Remove the cycle
        return head;
        
        
    }
};



int main(){
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next; // Creating a cycle for testing [ tail pointing to node with value 2 ]



    // CHECK CYCLE
    Solution sol;
    if(sol.hasCycle(head)){
        cout<<"Cycle detected in the linked list."<<endl;
    } else {
        cout<<"No cycle in the linked list."<<endl;
    }



    // DETECT CYCLE
    ListNode* cycleStart = sol.detectCycle(head);
    if(cycleStart){
        cout<<"Cycle starts at node with value: "<<cycleStart->val<<endl;
    } else {
        cout<<"No cycle detected."<<endl;
    }


    // DETECT AND REMOVE CYCLE
    head = sol.detectNdRemoveCycle(head);
    if(sol.hasCycle(head)){
        cout<<"Cycle still present after removal attempt."<<endl;
    } else {
        cout<<"Cycle successfully removed from the linked list."<<endl;
    }

    // print the list after cycle removal
    ListNode* temp = head;
    while(temp!=NULL){
        cout<<temp->val<<" -> ";
        temp=temp->next;
    }
    cout << "NULL" << endl;

    return 0;
}

