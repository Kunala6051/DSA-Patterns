#include <bits/stdc++.h>
using namespace std;

// Leetcode: 155. Min Stack

// Time Complexity: O(1) for all operations
// Space Complexity: O(n) for stack storage  (But here we are using more space(pairs) to store min with each element(i.e 2n space))

class MinStack {
    stack<pair<int,int>> s;  // stack stores {value, current_min}
public:
    MinStack() {
        // constructor (empty stack initially)
    }
    
    void push(int val) {
        if(s.empty()) {  
            s.push({val, val});           // first element: value = min
        } else {
            int mini = min(val, s.top().second);  // compare with current min
            s.push({val, mini});          // push value and updated min
        }
    }
    
    void pop() {
        s.pop();                          // remove top element
    }
    
    int top() {
        return s.top().first;             // return top value
    }
    
    int getMin() {
        return s.top().second;            // return current minimum
    }
};

int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin() << endl; // Returns -3
    minStack.pop();
    cout << minStack.top() << endl;    // Returns 0
    cout << minStack.getMin() << endl; // Returns -2

    return 0;
}