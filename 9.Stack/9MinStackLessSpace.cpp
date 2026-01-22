#include <bits/stdc++.h>
using namespace std;

// Leetcode: 155. Min Stack

// 🧩 Key Idea

// When a new element is smaller than the current minimum, we don’t push it directly.
// Instead, we encode it using this formula:

// encoded_value = 2 * val - minVal

// Remember the encoded value is always less than the current minimum, as val-minval will always give a negative value.
// So, val + (val-minval) will always be less than minval.
// This way, we can always identify if the top element is an encoded value or a regular value.


// This formula stores a special value that helps us remember the previous minimum when we pop later.

class MinStack {
    long long int minVal;      // stores current minimum value in the stack
    stack <long long int> s;   // main stack to store elements (and encoded values)
public:
    MinStack() { }             // constructor

    void push(int val) {
        if(s.empty()){ 
            s.push(val);       // first element, push normally
            minVal = val;      // set minVal to this value
        }
        else{
            if(val < minVal){  
                // push encoded value to keep track of previous min
                s.push((long long)2*val - minVal);
                minVal = val;  // update minVal to new smaller value
            } else {
                s.push(val);   // normal push if val >= minVal
            }
        }
    }

    void pop() {
        if(s.top() < minVal){  
            // top is encoded, restore previous min
            minVal = (2*minVal) - s.top();
        }
        s.pop();               // remove top element
    }

    int top() {
        if(s.top() < minVal){
            return minVal;     // encoded value means actual top is minVal
        }
        return s.top();        // otherwise return top element
    }

    int getMin() {
        return minVal;         // return current minimum
    }
};
