#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Leetcode: 277. The Celebrity Problem
// In a party of N people, only one person is known to everyone. Such a person is called a celebrity.
// The celebrity does not know anyone at the party. You need to find the celebrity in the party.

// Link to the problem: (Locked on Leetcode)
// https://www.geeksforgeeks.org/problems/the-celebrity-problem/1

// My Trial 😭😭
int bruteForce(vector<vector<int>>& mat) {
    // Assume initially no celebrity is found
    bool flag = true;
    int ans = -1;

    // Step 1: Check each column to find a potential celebrity
    for (int j = 0; j < mat[0].size(); j++) {
        bool f = true;

        // Check if everyone knows person j
        for (int i = 0; i < mat.size(); i++) {
            if (mat[i][j] != 1 && i != j) { // if someone doesn't know j
                f = false;
                break;
            }
        }

        // If more than one possible celebrity is found, reset answer
        if (f && !flag) {
            ans = -1;
        }

        // If this is the first possible celebrity, store index
        if (f && flag) {
            ans = j;
            flag = false;
        }
    }

    // Step 2: Verify that the potential celebrity knows no one
    if (ans != -1) {
        for (int i = 0; i < mat.size(); i++) {
            if (mat[ans][i] == 1 && i != ans) { // celebrity shouldn't know anyone
                ans = -1;
                break;
            }
        }
    }

    // Return celebrity index or -1 if none found
    return ans;
}


int celebrity(vector<vector<int>>& mat) {
    // Initialize a stack with all people (indices)
    stack<int> s;
    for (int i = 0; i < mat.size(); i++) s.push(i);
    
    // Step 1: Find potential celebrity by pairwise elimination
    while (s.size() > 1) {
        int i = s.top(); s.pop();
        int j = s.top(); s.pop();
        
        // If i doesn't know j, then j can't be celebrity → push i
        // Else i can't be celebrity → push j
        if (mat[i][j] == 0) s.push(i);
        else s.push(j);
    }
    
    // Step 2: Verify the remaining person is a real celebrity
    int ans = s.top();
    for (int i = 0; i < mat.size(); i++) {
        // Celebrity should not know anyone (mat[ans][i] == 0)
        // and everyone should know celebrity (mat[i][ans] == 1)
        if (i != ans && (mat[i][ans] == 0 || mat[ans][i] == 1))
            return -1;  // Not a celebrity
    }
    
    // If all conditions satisfy, return the celebrity index
    return ans;
}

// Time Complexity: O(N)
// Space Complexity: O(N)



int main() {
    vector<vector<int>> mat = {
        {0, 1, 1},
        {0, 0, 1},
        {0, 0, 0}
    };

    int result = bruteForce(mat);
    if (result != -1) {
        cout << "Celebrity found at index: " << result << endl;
    } else {
        cout << "No celebrity found." << endl;
    }

    result = celebrity(mat);
    if (result != -1) {
        cout << "Celebrity found at index: " << result << endl;
    } else {
        cout << "No celebrity found." << endl;
    }

    return 0;
}
