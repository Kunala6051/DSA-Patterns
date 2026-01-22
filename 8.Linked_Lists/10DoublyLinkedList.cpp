#include <bits/stdc++.h>
using namespace std;

struct ListNode {
public:
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode(){
        val=0;
        next=prev=NULL;
    }
    ListNode(int x){
        val=x;
        next=prev=NULL;

    }
};

class DoublyList{
    ListNode *head;
    ListNode *tail;
public:
    DoublyList(){
        head=tail=NULL;
    }

    void push_front(int x){
        ListNode* newNode = new ListNode(x);
        if(head==NULL){
            head=tail=newNode;
        }else{
            head->prev=newNode;
            newNode->next=head;
            head=newNode;
        }
    }

    void push_back(int x){
        ListNode* newNode = new ListNode(x);
        if(head==NULL){
            head=tail=newNode;
        }else{
            ListNode* temp=head;
            tail->next=newNode;  
            newNode->prev=tail;   
            tail=newNode;
        }
    }

    void pop_front(){
        if(head==NULL) cout << "Doubly Linked List is already empty.." << endl;
        else{
            ListNode* temp=head;
            head=head->next;
            if(head!=NULL) head->prev=NULL;
            temp->next=NULL;
            delete temp;
        }
    }

    void pop_back(){
        if(head==NULL) cout << "Doubly Linked List is already empty.." << endl;
        else{
            ListNode* temp=tail;
            tail=tail->prev;
            if(tail!=NULL) tail->next=NULL;
            temp->prev=NULL;
            delete temp;
        }
    }

    void print(){
        ListNode* temp=head;
        while(temp!=NULL){
            cout << temp->val << "<->";
            temp=temp->next;
        }
        cout << "NULL" << endl;
    }
};


int main(){
    DoublyList dll;

    dll.push_front(1);
    dll.push_front(2);
    dll.push_front(3);

    dll.print();

    dll.push_back(4);
    dll.push_back(5);

    dll.print();

    dll.pop_front();

    dll.print();

    dll.pop_back();

    dll.print();


}