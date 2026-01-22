#include <iostream>
#include <cstring> 
#include <string> 
#include <vector>
#include <algorithm> 
#include <cmath> 

using namespace std;

// A stack is a linear data structure that follows the LIFO (Last In, First Out) principle.

// push(x) → Adds element x to the top of the stack.
// pop() → Removes the top element from the stack.
// top() / peek() → Returns the top element without removing it.
// empty() → Checks whether the stack is empty or not.
// size() → Returns the total number of elements in the stack.

// All basic stack operations take O(1) time.
// Stack can be implemented using array, linked list, or STL stack.
// Common uses: function call management, expression evaluation, undo/redo, and backtracking.

class Stack{
    vector<int> v;

    // We can also use array instead of vector
    // int arr[1000];
    // But there will be a limitation on the size of stack

public:
    void push(int val){   // O(1)
        v.push_back(val);
    }

    void pop(){   // O(1)
        v.pop_back();
    }

    int top(){    // O(1)
        return v[v.size()-1];
    }

    bool empty(){
        return v.size()==0;
    }
};

int main(){
    Stack s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }
    cout << endl;


    return 0;
}