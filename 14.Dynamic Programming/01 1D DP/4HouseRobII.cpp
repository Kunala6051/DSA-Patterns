
/*
============================================================
LEETCODE 213 - HOUSE ROBBER II
============================================================

QUESTION:
Houses are arranged in a circle. Each house contains some money.
We cannot rob two adjacent houses.

Since the houses are circular, the first and last houses
are also adjacent.

We need to find the maximum money we can rob.

APPROACH:
There are only TWO possible cases:

1. Exclude the last house (consider indices 0 to n-2).
   This allows us to include the first house.

2. Exclude the first house (consider indices 1 to n-1).
   This allows us to include the last house.

Calculate the maximum money for both cases using
the House Robber I approach.

Final Answer = max(case1, case2).

TIME COMPLEXITY: O(N)
SPACE COMPLEXITY: O(1)
============================================================
*/

#include <bits/stdc++.h>
using namespace std;


// Helper function: House Robber I (Space Optimized)
int robLinear(vector<int>& nums, int start, int end) {

    int prev2 = 0; // Maximum money up to i-2
    int prev1 = 0; // Maximum money up to i-1

    for(int i = start; i <= end; i++) {

        // Choose between robbing and skipping current house.
        int curr = max(nums[i] + prev2, prev1);

        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}


// House Robber II
int rob(vector<int>& nums) {

    int n = nums.size();

    // Only one house.
    if(n == 1) return nums[0];

    // Case 1: Exclude last house.
    int excludeLast = robLinear(nums, 0, n - 2);

    // Case 2: Exclude first house.
    int excludeFirst = robLinear(nums, 1, n - 1);

    return max(excludeLast, excludeFirst);
}


// Main function
int main() {

    vector<int> nums = {2, 3, 2};

    cout << "Maximum Money Robbed: " << rob(nums) << endl;

    return 0;
}
