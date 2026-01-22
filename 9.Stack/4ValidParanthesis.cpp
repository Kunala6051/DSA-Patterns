#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool isValid(string s) {
    stack<char> st;  // stack to store opening brackets
    
    for (int i = 0; i < s.size(); i++) {
        // if it's an opening bracket, push to stack
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            st.push(s[i]);
        } 
        else { // if it's a closing bracket
            if (st.size() == 0) return false;  // no matching opening bracket
            
            // check if top of stack matches current closing bracket
            if ((st.top() == '(' && s[i] == ')') || 
                (st.top() == '[' && s[i] == ']') || 
                (st.top() == '{' && s[i] == '}')) {
                st.pop(); // matched pair found → remove opening bracket
            } 
            else return false; // mismatched bracket
        }
    }

    // if stack empty → all brackets matched
    if (st.size() == 0) return true;
    return false;
}

// Time Complexity: O(n)
// Space Complexity: O(n)

int main() {
    string s = "{[()]}"; // Example input string
    if (isValid(s)) {
        cout << "The string is valid." << endl;
    } else {
        cout << "The string is not valid." << endl;
    }

    string s1="{(}";
    if (isValid(s1)) {
        cout << "The string is valid." << endl;
    } else {
        cout << "The string is not valid." << endl;
    }


    return 0;
}
