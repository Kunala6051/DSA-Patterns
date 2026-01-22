#include <iostream>
#include <queue>
#include <vector>

using namespace std;


// Implementing a basic Queue using singly linked list
class Node{
public:
  int val;
  Node* next;
  
  Node(int v){
    val=v;
    next=NULL;
  }
};

class Queue{
    Node* head;
    Node* tail;
public:

    Queue(){
        head=NULL;
        tail=NULL;
    }

    void push(int v){
        Node* newNode = new Node(v);
        if(head==NULL){
            head=tail=newNode;
        } else{
            tail->next=newNode;
            tail=newNode;
        }
    }

    void pop(){
        if(head==tail){ // If no or one element
            head=tail=NULL;
            return;
        }
        Node* temp=head;
        while(temp->next!=tail){
            temp=temp->next;
        }
        temp->next=NULL;
        tail=temp;
    }

    int front(){
        if(head==NULL) {
            cout << "Queue already empty." << endl;
            return -1;
        }
        else{
            return head->val;
        }
    }

    bool empty(){
        if(head==NULL) return true;
        else return false;
    }
};

int main() {
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.front() << endl; // Should print 10

    q.pop();
    q.pop();
    q.pop();
    cout << "Front element after pop: " << q.front() << endl; // Should print Queue already empty.


    // IMPLEMENTATION USING STL QUEUE
    queue<int> stlQueue;
    stlQueue.push(10);
    stlQueue.push(20);
    cout << "Front element of STL queue: " << stlQueue.front() << endl; // Should print 10
    stlQueue.pop();
    stlQueue.pop();
    if(stlQueue.empty()) {
        cout << "STL Queue is empty now." << endl;
    }

    return 0;
}