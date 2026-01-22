#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Stack follows LIFO (Last In, First Out) principle.

// push(x) → Adds element x to the top of the stack.
// pop() → Removes the top element from the stack.
// top() / peek() → Returns the top element without removing it.
// empty() → Checks whether the stack is empty or not.
// size() → Returns the total number of elements in the stack.

// All basic stack operations take O(1) time.
// Stack can be implemented using array, linked list, or STL stack.
// Common uses: function call management, expression evaluation, undo/redo, and backtracking.

int main(){
    stack<int> s;

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