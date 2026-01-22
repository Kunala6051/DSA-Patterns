
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *prev;

    // Constructor to initialize a node with given data
    Node(int d) : data(d), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
public:
    Node *head;

    // Constructor to initialize the doubly linked list
    DoublyLinkedList() : head(nullptr) {}

    // Function to insert a new node at the end of the doubly linked list
    void insertEnd(int data) {
        Node *node = new Node(data);
        Node *last = head;

       if (head == nullptr) {  // if the list is empty, add in the beginning
            head = node;
            return;
        }

        while (last->next != nullptr)  // find the last node
            last = last->next;

        last->next = node;  // add the node after the last node of the list
        node->prev = last;
    }

    // Function to print contents of the doubly linked list starting from the head
    void printList(Node *node) {
        while (node != nullptr) {
            cout << node->data << ' ';
            node = node->next;
        }
    }
};


Node* rotateByK(Node* head, int k)
{
    if(!head || !head->next) return head;
    Node* temp=head;
    int c=0;
    while(temp){
        temp=temp->next;
        c++;
    }
    k=k%c;
    temp=head;
    for(int i=1; i<k-1; i++){
        temp=temp->next;
    }
    Node* f=temp->next;
    temp->next=NULL;
    f->prev=NULL;
    temp=f;
    while(temp->next) temp=temp->next;
    temp->next=head;
    head->prev=temp;
    head=f;
    return head;
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        DoublyLinkedList doublyLinkedList;
        Node *t1;
        int n, m, x;
        cin >> n;
        while (n--) {
            cin >> m;
            doublyLinkedList.insertEnd(m);
        }
        cin >> x;
        t1 = rotateByK(doublyLinkedList.head, x);
        doublyLinkedList.printList(t1);
        cout << endl;
    }
    return 0;
}
