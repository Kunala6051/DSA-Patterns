#include <iostream>
#include <cstring> 
#include <string> 
#include <vector>
#include <algorithm> 
#include <cmath> // For mathematical functions like log10
using namespace std;

// 46 LeetCode Permutations
// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

// Recursive helper function to generate permutations
void getPerms(vector<int> &nums, int idx, vector<vector<int>> &ans) {
        
    // Base case: if idx reaches the size of nums,
    // it means we have formed one complete permutation
    if(idx == nums.size()){
        ans.push_back(nums);  // store the current arrangement of nums
        return;
    }

    // Try placing every number at position 'idx' one by one
    for(int i = idx; i < nums.size(); i++) {
        
        // Swap the current element nums[i] with nums[idx]
        // This places nums[i] at the 'idx' position
        swap(nums[i], nums[idx]);

        // Recursively call function to fix the next index (idx+1)
        getPerms(nums, idx + 1, ans);

        // Backtrack: undo the swap to restore the original array
        // This is important to try other possible numbers at 'idx'
        swap(nums[i], nums[idx]);
    }
}

// Main function to generate all permutations of nums
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;       // to store all generated permutations
    getPerms(nums, 0, ans);        // start recursion from index 0
    return ans;                    // return the list of permutations
}
// Time Complexity: O(n * n!)


int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = permute(nums);
    cout << "Permutations:" << endl;
    for (const auto& perm : result) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}