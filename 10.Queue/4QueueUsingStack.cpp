#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// Leetcode 232

// Implementation of a queue using two stacks (FIFO using LIFO structure)
// Idea: Use one stack (s1) to maintain queue order by reversing elements using another stack (s2)
// Each push ensures the front of the queue is always at the top of s1

class MyQueue {
public:
    stack<int> s1; // main stack that stores queue elements in correct order
    stack<int> s2; // helper stack used for reordering

    MyQueue() { } // constructor

    void push(int x) {
        // Move all elements from s1 to s2
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }

        // Push the new element into empty s1
        s1.push(x);

        // Move all elements back from s2 to s1
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        // Remove the element from the front of the queue (top of s1)
        int ans = s1.top();
        s1.pop();
        return ans;
    }
    
    int peek() {
        // Return the front element without removing it
        return s1.top();
    }
    
    bool empty() {
        // Check if queue is empty
        return s1.empty();
    }
};

int main() {
    MyQueue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.peek() << endl; // 10

    cout << "Popped element: " << q.pop() << endl; // 10

    cout << "Front element after pop: " << q.peek() << endl; // 20

    cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl; // No

    return 0;
}
