#include <iostream>
using namespace std;

class CircularQueue {
private:
    int *arr;
    int frontidx;
    int rearidx;
    int count;
    int capacity;

public:
    // Constructor
    CircularQueue(int cap) {
        capacity = cap;
        frontidx = 0;
        rearidx = -1;
        count = 0;
        arr = new int[cap];
    }

    // Enqueue
    void enqueue(int val) {
        if (count == capacity) {
            cout << "Queue is full" << endl;
            return;
        }
        rearidx = (rearidx + 1) % capacity;
        arr[rearidx] = val;
        count++;
        cout << val << " inserted in queue" << endl;
    }
    void dequeue() {
        if (count == 0) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << arr[frontidx] << " is going to be deleted" << endl;
        arr[frontidx]=-1;
        frontidx=(frontidx+1)%capacity;
        count--;
    }
        void printqueue() {
    if (count == 0) {
        cout << "Queue is empty" << endl;
        return;
    }

    if (rearidx < frontidx) {
        for (int i = frontidx; i < capacity; i++) {
            cout << arr[i] << " ";
        }
        for (int i = 0; i <= rearidx; i++) {
            cout << arr[i] << " ";
        }
    } else {
        for (int i = frontidx; i <= rearidx; i++) {
            cout << arr[i] << " ";
        }
    }
    cout << endl << endl;
}
};


int main() {
    CircularQueue q1(5);
    q1.enqueue(15);
    q1.enqueue(20);
    q1.enqueue(21);
    q1.enqueue(22);
    q1.enqueue(23);
    
    
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.printqueue();
    
    
    q1.enqueue(45);
    q1.enqueue(50);
    q1.printqueue();

    return 0;
}