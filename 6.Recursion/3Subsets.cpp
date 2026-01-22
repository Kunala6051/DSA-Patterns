#include <iostream>
#include <cstring> 
#include <string> 
#include <vector>
#include <algorithm> 
#include <cmath> // For mathematical functions like log10
using namespace std;


// UNIQUE ELEMENTS
void printSubsets(vector <int> arr,vector <int> ans, int i){
    if(i==arr.size()){
        for(int j: ans) cout << j << " ";
        cout << endl;
        return;
    }

    // Include the current element
    ans.push_back(arr[i]);
    printSubsets(arr, ans, i+1);

    // Backtracking
    ans.pop_back();

    // Exclude the current element
    printSubsets(arr, ans, i+1);

}
// Total subsets = 2^n
// where n is the size of the input set

// Total recursive calls = 2^n * n
// Time Complexity: Total recursive calls * Work done in each call
//                  = O(2^n * n)



// LeetCode 78. Subsets  (UNIQUE ELEMENTS)

// Given an integer array nums of unique elements, return all possible subsets (the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.

void subsetHelper(vector<int>& nums, vector<vector<int>>& ans, vector<int> temp, int i){
    if(i==nums.size()){
        ans.push_back(temp);
        return ;
    }

    temp.push_back(nums[i]);
    subsetHelper(nums,ans,temp,i+1);

    temp.pop_back();
    subsetHelper(nums,ans,temp,i+1);

}

vector<vector<int>> subsets(vector<int>& nums) {
    vector <int> temp;
    vector <vector <int>> ans;
    subsetHelper(nums,ans,temp,0);
    return ans;
}
// Time Complexity: O(2^n * n)




// Leet code: 90. Subsets II

// Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.



// Helper function to recursively generate all unique subsets
void subsetHelper2(vector<int>& nums,               // Input array (may contain duplicates)
                  vector<vector<int>>& ans,        // Final list of subsets
                  vector<int> temp,                // Current subset being built
                  int i)                           // Current index in nums
{
    // Base case: if we've processed all elements
    if (i == nums.size()) {
        ans.push_back(temp);  // Add the current subset to the answer
        return;
    }

    // ---------- Choice 1: Include nums[i] ----------
    temp.push_back(nums[i]);  // Add current element to subset
    subsetHelper(nums, ans, temp, i + 1); // Move to the next index

    // ---------- Backtrack ----------
    temp.pop_back();  // Remove the last element to try the "exclude" option

    // ---------- Choice 2: Exclude nums[i] ----------
    // Means if we are already excluding an element, we should not include its duplicates
    // This step is done only when we are excluding the current element
    // Skip all duplicates of nums[i] to avoid repeating subsets
    int idx = i + 1;
    while (idx < nums.size() && nums[idx] == nums[idx - 1]) {
        idx++;
    }
    subsetHelper(nums, ans, temp, idx); // Move to the first non-duplicate element
}

// Main function to return all unique subsets of nums
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());  // Sort to group duplicates together
    vector<int> temp;                // Temporary subset container
    vector<vector<int>> ans;         // Stores all subsets

    subsetHelper2(nums, ans, temp, 0); // Start recursion from index 0
    return ans;
}

// Time complexity: O(nlogn) for sorting + O(2^n * n) for generating subsets  => O(2^n *n)
// Space complexity: O(n) for the temporary subset

int main(){

    vector <int> arr = {1,2,3};
    vector <int> ans;
    printSubsets(arr, ans, 0);

    vector<vector<int>> result = subsets(arr);
    cout << "Subsets:" << endl;
    for (vector <int> subset : result) {
        for (int num : subset) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}