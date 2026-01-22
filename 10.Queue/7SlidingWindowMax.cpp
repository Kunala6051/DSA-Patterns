#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <deque>

using namespace std;

// Leetcode 239
// Sliding Window Maximum

// You are given an array of integers nums, 
// there is a sliding window of size k which is moving from the very left of the array to the very right. 
// You can only see the k numbers in the window. 
// Each time the sliding window moves right by one position.

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;        // stores indices of potential max elements for current window
    vector<int> ans;      // stores final maximums for each window

    // Process first 'k' elements
    for(int i = 0; i < k; i++) {
        // Remove smaller elements (they can't be max if a bigger one exists)
        while(!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }
        dq.push_back(i);  // push current index
    }

    // Process the remaining elements
    for(int i = k; i < nums.size(); i++) {
        ans.push_back(nums[dq.front()]);  // front of deque is the max for the previous window

        // Remove indices out of the current window range
        while(!dq.empty() && dq.front() < i - k + 1) {
            dq.pop_front();
        }

        // REMEMBER
        // 1. the deque stores indices, not values
        // 2. maintain decreasing order in deque (front = largest)
        //    thats why we remove smaller elements from back

        // Remove smaller elements from the back
        while(!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }

        dq.push_back(i);  // add current element's index
    }

    // Add max for the last window
    ans.push_back(nums[dq.front()]);

    return ans;
}


int main(){
    vector<int> v={1,3,-1,-3,5,-3,6,7};
    vector <int> res=maxSlidingWindow(v,3);
    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }
    return 0;
}