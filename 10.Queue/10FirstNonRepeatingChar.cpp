#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;


// First Non-Repeating Character in a Live Chat

// Problem statement
// Given a lowercase string s representing characters arriving one by one in chat, 
// after each character print the current first non-repeating character. If none exists, print #.

// Input format
// One line: string s
// Output format
// One line: a string of length |s| where i-th char is answer after processing s[i].

// Input
// aabc
// Output
// a#bb

// Input
// zz
// Output
// z#

// input
// leetcode
// Output
// llllllle

// input
// abac
// Output
// aabb

// input
// aabbcc
// Output
// a#b#c#

// input
// xxyyz
// Output
// x#y#z


string modify(string s){
    vector<int> v(26,0);
    queue<int> q;
    string ans="";
    for(char c: s){
        q.push(c);
        v[c-'a']++;
        while(!q.empty() && v[q.front()-'a']>1) q.pop();
        if(q.empty()) ans+='#';
        else ans+=q.front();
    }
    return ans;
}

int main(){
    string s = "xxyyzz";
    cout << modify(s) << endl; 
}