#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Leetcode 225

// Implementation of a stack using two queues (LIFO using FIFO structure)
// Idea: Use one queue (q1) to always keep the newest element at the front
// This ensures that pop() and top() can work directly on q1’s front element

class MyStack {
public:
    queue<int> q1; // main queue holding elements in stack order
    queue<int> q2; // helper queue used for rearranging elements

    MyStack() { } // constructor

    void push(int x) {
        // Move all elements from q1 to q2
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }

        // Push new element into q1 (it becomes the "top" of stack)
        q1.push(x);

        // Move all elements back from q2 to q1
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }
    
    int pop() {
        // Remove and return the top element (front of q1)
        int ans = q1.front();
        q1.pop();
        return ans;
    }
    
    int top() {
        // Return the top element without removing it
        return q1.front();
    }
    
    bool empty() {
        // Check if stack is empty
        return q1.empty();
    }
};


int main() {
    MyStack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.top() << endl; // 30

    cout << "Popped element: " << s.pop() << endl; // 30
    cout << "Top element after pop: " << s.top() << endl; // 20

    cout << "Is stack empty? " << (s.empty() ? "Yes" : "No") << endl; // No

    return 0;
}