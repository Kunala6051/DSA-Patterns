#include <bits/stdc++.h>
using namespace std;

// Leetcode: 496. Next Greater Element I

// Time Complexity: O(n)
// Space Complexity: O(n)

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int,int> ans1;  // store next greater element for each number in nums2
    stack<int> s;                 // stack to keep track of next greater elements

    // traverse nums2 from right to left
    for(int i = nums2.size() - 1; i >= 0; i--) {
        // pop all smaller or equal elements from stack
        while(!s.empty() && s.top() <= nums2[i]) { 
            s.pop();
        }

        // if stack empty → no greater element
        if(s.empty()) ans1[nums2[i]] = -1;
        // else top of stack is next greater element
        else ans1[nums2[i]] = s.top();

        // push current element to stack
        s.push(nums2[i]);  
    }

    vector<int> ans;  // store final answers for nums1 elements
    for(int i = 0; i < nums1.size(); i++) {
        ans.push_back(ans1[nums1[i]]);  // fetch next greater from map
    }

    return ans;
}

int main() {
    vector<int> nums1 = {4, 1, 2};  // subset array
    vector<int> nums2 = {1, 3, 4, 2};  // main array

    vector<int> result = nextGreaterElement(nums1, nums2);

    // Print the results
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
