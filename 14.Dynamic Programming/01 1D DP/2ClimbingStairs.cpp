#include <iostream>
#include <vector>
using namespace std;

/*
Climbing Stairs Problem:
You are climbing a staircase with n stairs. You can climb either
1 stair or 2 stairs at a time. Find the total number of distinct
ways to reach the top.

Approach:
To reach stair n, the last move must be either:
1. A 1-step move from stair n-1.
2. A 2-step move from stair n-2.

Therefore, total ways to reach stair n are the sum of the ways
to reach stair n-1 and stair n-2.

Recurrence Relation:
f(n) = f(n-1) + f(n-2)

Base Cases:
f(1) = 1  -> Only one way to climb 1 stair.
f(2) = 2  -> Either 1+1 or 2.

This follows the Fibonacci pattern because each result is the
sum of the previous two results.
*/

// 1. Recursion: Solve the problem by recursively calculating smaller subproblems.
// Time: O(2^n) | Space: O(n)
int climbStairsRecursion(int n) {
    if (n == 1 || n == 2) return n;

    return climbStairsRecursion(n - 1)
         + climbStairsRecursion(n - 2);
}

// 2. Memoization: Store calculated results in a DP array to avoid repeated work.
// Time: O(n) | Space: O(n)
int climbStairsMemoization(int n, vector<int>& dp) {
    if (n == 1 || n == 2) return n;

    if (dp[n] != -1) return dp[n];

    return dp[n] = climbStairsMemoization(n - 1, dp)
                 + climbStairsMemoization(n - 2, dp);
}

// 3. Iteration: Use two variables to calculate each next result without a DP array.
// Time: O(n) | Space: O(1)
int climbStairsIteration(int n) {
    if (n == 1 || n==2) return n;

    int a = 1;
    int b = 2;

    for (int i = 2; i < n; i++) {
        int c = a + b;
        a = b;
        b = c;
    }

    return b;
}

// 4. Tabulation: Build the DP array from the base cases up to n.
// Time: O(n) | Space: O(n)
int climbStairsTabulation(int n) {
    if (n == 1 || n==2) return n;

    vector<int> dp(n + 1, -1);
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}
// However, we dont need to store the entire dp array, we can just store the last two values and 
// update them iteratively, which is what we did in the iteration approach.

int main() {
    int n;
    cout << "Enter the number of stairs: ";
    cin >> n;

    if (n < 1) {
        cout << "Number of stairs must be positive." << endl;
        return 0;
    }

    vector<int> dp(n + 1, -1);

    cout << "Recursion: " << climbStairsRecursion(n) << endl;
    cout << "Memoization: " << climbStairsMemoization(n, dp) << endl;
    cout << "Iteration: " << climbStairsIteration(n) << endl;
    cout << "Tabulation: " << climbStairsTabulation(n) << endl;

    return 0;
}