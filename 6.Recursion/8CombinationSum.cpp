#include <iostream>
#include <cstring> 
#include <string> 
#include <vector>
#include <algorithm> 
#include <set>
#include <cmath> // For mathematical functions like log10

using namespace std;



// Global set to store already found unique combinations
// (so that we don’t push duplicate combinations into ans)
set<vector<int>> s;

void helper(vector<int> arr, int i, int target, vector<vector<int>> &ans, vector<int> &combo) {
    // Base Case 1: if target goes negative, no valid combination → stop recursion
    if (target < 0 || i == arr.size()) return;

    // Base Case 2: if target becomes 0, we found a valid combination
    if (target == 0) { 
        // Check if this combination was already added (to avoid duplicates)
        if (s.find(combo) == s.end()) {
            ans.push_back(combo);  // store the current valid combination
            s.insert(combo);       // mark it as used
        }
        return;
    }

    // ==========================
    // Recursive exploration part
    // ==========================

    // 1. Include current element (arr[i]) once and move to the next index
    combo.push_back(arr[i]);
    helper(arr, i + 1, target - arr[i], ans, combo);

    // 2. Include current element but stay on the same index (allow reuse)
    helper(arr, i, target - arr[i], ans, combo);

    // Backtrack: remove the last added element (arr[i]) 
    // to restore the state for the next choice
    combo.pop_back();

    // 3. Exclude current element completely and move to the next index
    helper(arr, i + 1, target, ans, combo);
}

// There are 3 steps in the recursive function:
// 1. Include the current element and move to the next index.
// 2. Include the current element and stay on the same index (to allow reuse).
// 3. Exclude the current element and move to the next index.

// Main function
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;   // stores all unique valid combinations
    vector<int> combo;         // temporary list to build each combination

    helper(candidates, 0, target, ans, combo);

    return ans;
}

int main() {
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> result = combinationSum(candidates, target);

    cout << "Unique combinations that sum to " << target << " are:\n";
    for (const auto& combo : result) {
        cout << "[ ";
        for (int num : combo) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}