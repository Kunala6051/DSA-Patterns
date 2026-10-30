
/*
============================================================
LEETCODE 198 - HOUSE ROBBER
============================================================

QUESTION:
You are a robber planning to rob houses arranged in a street.

Each house contains some amount of money, represented by nums[i].

However, adjacent houses have security systems connected.
If two adjacent houses are robbed, the police will be alerted.

We need to return the MAXIMUM amount of money we can rob
without robbing two adjacent houses.

Example:
nums = [2, 7, 9, 3, 1]

Possible choices:
- Rob houses containing 2, 9, 1 = 12
- Rob houses containing 7, 3 = 10
- Rob houses containing 2, 9 = 11

Answer = 12


============================================================
APPROACH / RECURSION
============================================================

At every index, we have TWO choices:

1. ROB the current house:
   - Add nums[i] to our answer.
   - Skip the next house.
   - Move to i + 2.

2. DON'T ROB the current house:
   - Don't add anything.
   - Move to the next house (i + 1).

Take the maximum of both choices.

Recurrence:

dp[i] = max(
    nums[i] + dp[i+2],
    dp[i+1]
)

BASE CASE:
If i >= n, return 0 because no houses are left.


============================================================
PROBLEM WITH NORMAL RECURSION
============================================================

Normal recursion explores both possibilities at every index.

This creates overlapping subproblems.

For example, the same index can be reached through
multiple recursive paths, causing repeated calculations.

Time Complexity: O(2^N)
Space Complexity: O(N) - recursion stack.

For large N, normal recursion gives TLE.


============================================================
1. MEMOIZATION (TOP-DOWN DP)
============================================================

IDEA:

We use a DP array to store previously calculated answers.

dp[i] represents:

Maximum money that can be robbed starting from index i.

Whenever we calculate an answer for index i,
we store it in dp[i].

If we encounter the same index again,
we directly return the stored answer.

This avoids repeated calculations.

Time Complexity: O(N)
Space Complexity: O(N) for DP array + O(N) recursion stack.


============================================================
2. TABULATION (BOTTOM-UP DP)
============================================================

IDEA:

Instead of solving the problem recursively,
we solve it iteratively using a DP array.

dp[i] represents the maximum money we can rob
from houses 0 to i.

BASE CASES:

dp[0] = nums[0]

dp[1] = max(nums[0], nums[1])

TRANSITION:

dp[i] = max(
    dp[i-1],             // Don't rob current house
    dp[i-2] + nums[i]    // Rob current house
)

We build the DP array from left to right.

Finally, dp[n-1] contains the maximum money.

Time Complexity: O(N)
Space Complexity: O(N)


============================================================
*/

#include <bits/stdc++.h>
using namespace std;


// ============================================================
// 1. MEMOIZATION (TOP-DOWN DP)
// ============================================================

int memoHelp(vector<int>& nums, vector<int>& dp, int i) {

    // Base case: No houses left to rob.
    if(i >= nums.size()) return 0;

    // If already calculated, return stored answer.
    if(dp[i] != -1) return dp[i];

    // Choice 1: Rob current house and skip the next house.
    int rob = nums[i] + memoHelp(nums, dp, i + 2);

    // Choice 2: Don't rob current house, move to next house.
    int noRob = memoHelp(nums, dp, i + 1);

    // Store the maximum of both choices.
    return dp[i] = max(rob, noRob);
}


int robMemoization(vector<int>& nums) {

    int n = nums.size();

    // Initially, all states are uncalculated.
    vector<int> dp(n, -1);

    return memoHelp(nums, dp, 0);
}


// ============================================================
// 2. TABULATION (BOTTOM-UP DP)
// ============================================================

int robTabulation(vector<int>& nums) {

    int n = nums.size();

    // Handle the single-house case.
    if(n == 1) return nums[0];

    // DP array to store maximum money up to each index.
    vector<int> dp(n, -1);

    // Base case: Only one house.
    dp[0] = nums[0];

    // Base case: Choose the maximum between first two houses.
    dp[1] = max(nums[0], nums[1]);

    // Build the DP array from left to right.
    for(int i = 2; i < n; i++) {

        // Choice 1: Don't rob current house.
        int noRob = dp[i-1];

        // Choice 2: Rob current house.
        int rob = nums[i] + dp[i-2];

        // Store the maximum of both choices.
        dp[i] = max(rob, noRob);
    }

    // Last index contains the maximum money.
    return dp[n-1];
}


// ============================================================
// MAIN FUNCTION - SHOWCASING BOTH APPROACHES
// ============================================================

int main() {

    vector<int> nums = {2, 7, 9, 3, 1};

    cout << "House Robber Problem" << endl;

    cout << "Memoization Answer: "
         << robMemoization(nums) << endl;

    cout << "Tabulation Answer: "
         << robTabulation(nums) << endl;

    return 0;
}
