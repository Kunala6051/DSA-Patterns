#include <iostream>
#include <deque>
#include <vector>

using namespace std;

// Demonstration of Circular Queue in C++
// A circular queue is a linear data structure that follows the FIFO principle
// but connects the end of the queue back to the front, forming a circle.

class CircularQueue {
    int capacity;
    int* arr;
    int f, r;
    int arrSize=0;
public:

    CircularQueue(int c){
        capacity=c;
        arr = new int[capacity];
        f=0, r=-1;
    }

    void push(int v){     // O(1)
        if(arrSize==capacity){
            cout << "Queue already full..." << endl;
            return;
        }
        r=(r+1)%capacity;   // So that r comes back to 0 after reaching capacity
        arr[r]=v;
        arrSize++;
    }

    void pop(){       // O(1)
        if(arrSize==0){
            cout << "Queue Already empty..." << endl;
            return;
        }
        f=(f+1)%capacity;   // So that f comes back to 0 after reaching capacity
        arrSize--;
    }

    int front(){     // O(1)
        if(arrSize==0){
            cout << "Queue is empty..." << endl;
            return -1;
        }
        return arr[f];
    }

    bool empty(){   // O(1)
        return arrSize==0;
    }
};

int main(){

    CircularQueue Cq(6);
    Cq.push(1);
    Cq.push(2);
    Cq.push(3);
    Cq.push(4);
    
    cout << Cq.front() << endl;

    Cq.pop();
    Cq.pop();
    Cq.pop();
    Cq.pop();

    Cq.pop();  // Trying to pop from empty queue

    if(Cq.empty()){
        cout << "Queue is empty now..." << endl;
    }

    cout << Cq.front() << endl;  // Trying to access front from empty queue

    Cq.push(20);
    Cq.push(30);
    Cq.push(40);

    cout << Cq.front() << endl;

    Cq.push(20);
    Cq.push(30);
    Cq.push(40);
    Cq.push(60);  // Trying to push into full queue


    while(!Cq.empty()){
        cout << Cq.front() << " ";
        Cq.pop();
    }
    cout << endl;



    return 0;
}