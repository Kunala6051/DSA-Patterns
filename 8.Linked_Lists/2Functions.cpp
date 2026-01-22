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

class List{
    Node* head;
    Node* tail;

public:

    List(){
        head = tail = NULL;  // Initializing with the help of constructor
    }

    // Already studied functions in list class in STL lecture:
    // push_front, push_back, pop_front, pop_back
    // Today we will learn to build them from scratch

    // push_front
    void push_front(int val){  // O(1)

        Node* newNode = new Node(val); // Dynamically creating a new Node(object) 
        // and storing its memory address in a pointer named newNode

        // IMPORTANT NOTE: (WHY WE USED NEW KEYWORD ABOVE)
        // We could also create a new object with
        // Node newNode(value)
        // but it would have created a static object but it would have been destroyed when function exits.

        if(head==NULL){ // case of empty list
            // i.e the head(which should be a memory address pointing to first element of LL is null)

            head = tail = newNode; // assinging them memory address of the first node 
            // i.e pointing both to first val
            return;

        } else{ // Case of non empty list

            // present head: memory address of first element of LL
            // now the element which we are going to add also has two properties a data = val
            // and a pointer to next element
            // Now pointer of newNode should store the address of presently 1st element of the LL
            // So,
            newNode->next = head;

            // and head should point to newNode (new first element)
            head = newNode;

        }

    }

    void push_back(int val){  // O(1) (but if we do not have tail then O(n))
        Node* newNode = new Node(val);
        if(head==NULL){ // case of empty list

            head = tail = newNode; 
            return;

        } else{
            
            tail->next = newNode;
            // in simple terms *(tail).next = new memory address
            // *(tail) = present last data
            // data.next = pointer to next element which is presently NULL

            tail = newNode;
            // new memory address becomes the tail

        }
    }

    void pop_front(){  // O(1)
        if(head==NULL){
            cout << "List Already empty" << endl;
            return;
        } else{
            Node* toDelete = head; // memory address which has to be deleted
            
            head = head->next; // memory  address of second element is now stored in head making it the first element

            toDelete->next = NULL; // now that memory address is completely separated from linked list 

            delete toDelete;

        }
    }

    void pop_back(){  // O(n) 
        if(head==NULL){
            cout << "List Already empty" << endl;
            return;
        } else{
            Node* toDelete = tail;

            // Now since backtracking is not possible in LL we have to start from head to reach to the second last node
            
            Node* temp=head;
            while(temp!=NULL){
                if(temp->next==tail){ // we found our second last node
                    // In case we dont have tail, then method to find second last will be
                    // to traverse untill the next to next pointer is NULL
                    
                    tail=temp;
                    temp->next=NULL; // breaking connection of second last node with last node
                    break;
                }
                temp = temp->next; // traversing
            }

            delete toDelete;
        }
    }

    void insert(int val, int pos){    // O(n)
        if(pos<0){
            cout << "Invalid Position" << endl;
            return;
        }
        if(pos==0){
            this->push_front(val);
            return;
        }
        Node* newNode = new Node(val);
        Node* temp = head;
        
        for(int i=0; i<pos-1; i++){
            if(temp==NULL){
                cout << "Position out of bounds, inserting at end instead" << endl;
                return;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next=newNode;

    }

    int search(int key){    // O(n)
        int i=0;
        Node* temp = head;
        while(temp!=NULL){
            if(temp->data == key) return i;
            i++;
            temp = temp->next;
        }
        return -1;
    }

    void printLL(){
        Node* temp = head;
        // We want to preserve our head because once we lost our head we lost our linked list
        // as backtracking is not possible in LL
        
        while(temp!=NULL){
            cout << temp->data << "->";
            temp = temp->next; // assinging address of element next to present element;
        }
        cout << "NULL" << endl;
    }

};

int main(){
    List l1;

    l1.push_front(1);
    l1.push_front(2);
    l1.push_front(3);
    l1.push_front(4);

    l1.printLL();

    l1.push_back(0);
    l1.push_back(-1);

    l1.printLL();

    l1.pop_front();
    l1.pop_front();

    l1.printLL();

    l1.pop_back();
    l1.pop_back();

    l1.printLL();

    l1.insert(100, 1);
    l1.printLL();

    l1.insert(200, 3);
    l1.printLL();

    l1.insert(400, 0);
    l1.printLL();

    int res = l1.search(200);
    if(res!=-1){
        cout << "Element found at index: " << res << endl;
    } else{
        cout << "Element not found" << endl;
    }
    
    

}