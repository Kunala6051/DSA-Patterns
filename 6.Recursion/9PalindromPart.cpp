#include <iostream>
#include <cstring> 
#include <string> 
#include <vector>
#include <algorithm> 
#include <set>
#include <cmath> // For mathematical functions like log10

using namespace std;


// Function to check if a given string is a palindrome
bool isPalindrome(string s) {
    int st = 0; 
    int end = s.size() - 1;

    // Use two pointers: one from start, one from end
    while (st <= end) {
        if (s[st] != s[end]) return false; // mismatch → not a palindrome
        st++;
        end--;
    }
    return true; // if no mismatch, it's a palindrome
}

// Recursive helper function
// s      → remaining string we need to partition
// part   → current path (list of palindromic substrings chosen so far)
// ans    → final list of all valid palindrome partitions
void helper(string s, vector<string> &part, vector<vector<string>> &ans) {
    // Base case: if the string becomes empty,
    // it means we have partitioned the whole string into palindromes
    if (s.size() == 0) {
        ans.push_back(part);  // save the current partition
        return;
    }

    // Try to partition the string at every possible index
    for (int i = 0; i < s.size(); i++) {                            // O(n)
        // Take substring from 0 to i
        string sub = s.substr(0, i + 1);

        // Check if this substring is a palindrome
        if (isPalindrome(sub)) {
            // If yes, include it in the current partition
            part.push_back(sub);

            // Recurse on the remaining substring after i
            helper(s.substr(i + 1), part, ans);

            // Backtrack: remove the last added substring
            // so that we can try other partitions
            part.pop_back();
        }
    }
}

// Time Complexity: 
    // O(n) -> to check if a substring is palindrome
    // O(n) -> to generate all substrings in the worst case (for loop)
    // O(2^n) -> to generate all possible partitions
    // Overall: O(n * 2^n)

// Space Complexity: O(n) for the recursion stack + O(n) for the current partition

// where n is the length of the string

// Main function to return all palindrome partitions
vector<vector<string>> partition(string s) {
    vector<vector<string>> ans; // stores all final partitions
    vector<string> part;        // stores current partition (path)

    helper(s, part, ans);

    return ans;
}

int main() {
    string s = "abaabcaba";
    vector<vector<string>> result = partition(s);

    cout << "Palindrome partitions of \"" << s << "\":" << endl;
    for (const auto &partition : result) {
        cout << "[ ";
        for (const auto &str : partition) {
            cout << "\"" << str << "\" ";
        }
        cout << "]" << endl;
    }

    return 0;
}