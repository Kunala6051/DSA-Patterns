#include <iostream>
#include <cstring> 
#include <string> 
#include <vector>
#include <algorithm> 
#include <cmath> 

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    LinkedList() : head(nullptr) {}
    void  forwardPrint();
    void  insertEnd(int data);
     void  shiftSmallLarge();
};

    void LinkedList:: forwardPrint() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
    }
    void LinkedList:: insertEnd(int data) {
        Node* node = new Node(data);
        if (head == nullptr) {
            head = node;
            return;
        }
        Node* last = head;
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = node;
    }

 void LinkedList:: shiftSmallLarge() {
  // Write your code here
     Node* min=head;
     Node* t=head;
     while(t!=NULL){
         if(t->data<min->data) min=t;
         t=t->next;
     }
     t=head;
     while(t->next!=NULL){
         if(t->next==min){
             t->next=t->next->next;
         } else t=t->next;
     }
     min->next=head;
     head=min;
}

int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        LinkedList list;
        cin >> n;
        while (n--) {
            cin >> m;
            list.insertEnd(m);
        }
        list.shiftSmallLarge();
        list.forwardPrint();
        cout << endl;
    }
    return 0;
}