#include <iostream>
#include <cstring> 
#include <string> 
#include <vector>
#include <algorithm> 
#include <cmath> 

using namespace std;

class Node{
public:

    int data;
    Node* next; // pointing to next node object

    Node(int val){
        data=val;
        next=NULL;
    }

};

class CircularList{
    Node* head;
    Node* tail;

public:

    CircularList(){
        head = tail = NULL;  // Initializing with the help of constructor
    }

    void insertAtHead(int x){
        Node* newNode= new Node(x);
        if(head==NULL){
            head=tail=newNode;
            tail->next=head;
        } else{
            newNode->next=head;
            tail->next=newNode;
            head=newNode;
        }
    }

    void insertAtTail(int x){
        Node* newNode= new Node(x);
        if(head==NULL){
            head=tail=newNode;
            tail->next=head;
        } else{
            newNode->next=head;
            tail->next=newNode;
            tail=newNode;
        }
    }

    void deleteAtHead(){
        if(head==NULL) cout << "Circular Linked List already empty..";
        else if(head==tail){ // Only one node
            head=tail=NULL;
        }
        else{
            tail->next=head->next;
            head->next=NULL;
            Node* temp=head;
            head=tail->next;
            delete temp;
        }
    }

    void deleteAtTail(){
        if(head==NULL) cout << "Circular Linked List already empty..";
        else if(head==tail){ // Only one node
            head=tail=NULL;
        }
        else{
            Node* temp=head;
            while(temp->next!=tail){
                temp=temp->next;
            }
            Node* temp2=tail;
            temp->next=head;
            tail->next=NULL;
            tail=temp;
            delete temp2;
        }
    }

    void print(){
        if(head==NULL) cout << "NULL" << endl;
        else{
            Node* temp=head->next;
            cout << head->data << "->";
            while(temp!=head){
                cout << temp->data << "->";
                temp=temp->next;
            }
            cout << temp->data << endl;
        }
    }
};

int main(){
    CircularList cll;

    cll.insertAtHead(1);
    cll.insertAtHead(2);
    cll.insertAtHead(3);

    cll.print();

    cll.insertAtTail(4);
    cll.insertAtTail(5);

    cll.print();

    cll.deleteAtHead();

    cll.print();

    cll.deleteAtTail();

    cll.print();


    return 0;
}