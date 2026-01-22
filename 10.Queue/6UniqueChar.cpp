#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// Leetcode 387
// Find the first non-repeating character in a string
// Return its index. If it doesn't exist, return -1.


int firstUniqChar(string s) {
    unordered_map<char, int> m;  // stores frequency of each character
    queue<int> q;                // stores indices of characters seen for the first time

    for (int i = 0; i < s.size(); i++) {
        if (m.find(s[i]) == m.end()) 
            q.push(i);           // push index if character appears for the first time

        m[s[i]]++;               // increment character frequency
    }

    // remove indices of characters that are no longer unique
    while (!q.empty() && m[s[q.front()]] > 1) 
        q.pop();

    // if no unique character, return -1
    if (q.empty()) return -1;

    // front of queue has index of first unique character
    return q.front();
}

int main() {
    string s = "leetcode";
    cout << "Index of first unique character in \"" << s << "\": " << firstUniqChar(s) << endl;

    s = "loveleetcode";
    cout << "Index of first unique character in \"" << s << "\": " << firstUniqChar(s) << endl;

    s = "aabb";
    cout << "Index of first unique character in \"" << s << "\": " << firstUniqChar(s) << endl;

    return 0;
}
