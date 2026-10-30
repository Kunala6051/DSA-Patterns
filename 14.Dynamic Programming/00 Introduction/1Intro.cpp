/*
===============================================================================
                 DYNAMIC PROGRAMMING (DP) — LECTURE NOTES
                     Fibonacci: Recursion, Memoization, Tabulation
===============================================================================

1. WHY LEARN DYNAMIC PROGRAMMING?
---------------------------------
- DP is an important DSA topic for placement interviews and online assessments.
- The lecture's approach is not just to memorize individual solutions. It is to
  recognize DP PATTERNS: one pattern can help solve many related problems.
- DP may take time to understand at first. Carefully follow examples and practise
  multiple questions; the concepts become easier with practice.
- DP can be understood as OPTIMIZED RECURSION: it avoids repeatedly solving the
  same subproblem and can reduce exponential time to linear time in examples
  such as Fibonacci.

2. FIBONACCI SEQUENCE
--------------------
- Every Fibonacci number (after the first two) is the sum of the previous two.
- Recurrence relation:
      F(n) = F(n - 1) + F(n - 2)
- Base cases:
      F(0) = 0
      F(1) = 1
- Sequence:
      0, 1, 1, 2, 3, 5, 8, 13, 21, ...
- Therefore, F(6) = 8.

3. NORMAL RECURSION (NAIVE / BRUTE-FORCE APPROACH)
-------------------------------------------------
- If n <= 1, return n.
- Otherwise, calculate F(n - 1) + F(n - 2).
- This follows the Fibonacci recurrence directly.
- TIME COMPLEXITY: O(2^n), as stated in the lecture.
- The recursion tree contains repeated work. For example, F(2) and F(3) can
  be calculated multiple times while finding a larger Fibonacci number.
- These repeated calls make the naive recursive approach inefficient.

4. WHAT IS DYNAMIC PROGRAMMING?
-------------------------------
Lecture definition, in simple language:
DP is an optimization technique that stores intermediate results so that the
same subproblem does not need to be calculated repeatedly.

Instead of calculating F(2) again whenever it is needed, calculate it once,
store the answer, and reuse it.

Two important properties are required for a problem to be suitable for DP:

A. OVERLAPPING SUBPROBLEMS
   - The same smaller subproblems are solved repeatedly.
   - In Fibonacci recursion, F(2), F(3), etc. can appear multiple times in the
     recursion tree.
   - Repeated calculations are commonly seen when a recursive call has multiple
     choices/branches. The lecture gives a grid example where a cell may lead
     to calls for top, bottom, left, and right.

B. OPTIMAL SUBSTRUCTURE
   - The solution to a larger problem can be built from solutions to smaller
     subproblems.
   - For Fibonacci, F(n) is built from F(n - 1) and F(n - 2).

IMPORTANT:
- Overlapping subproblems alone are not enough; both properties should hold.
- The lecture's example is the sum of the first n natural numbers:
      sum(n) = n + sum(n - 1)
  It has optimal substructure, but its recursive calls form a single chain and
  do not repeatedly solve the same subproblem. Therefore, it does not have
  overlapping subproblems in the way required here, so DP does not help.
- The lecture also mentions merge sort, quick sort, and binary-tree traversals
  as recursive examples where these DP properties are not satisfied in the
  relevant way. Recursion by itself does NOT mean DP can be applied.

5. MEMOIZATION — TOP-DOWN DP
----------------------------
- Memoization uses RECURSION plus extra storage.
- Start with the original/larger problem, then recursively go down to smaller
  problems. This is why it is called TOP-DOWN.
- Create a vector of size n + 1 because Fibonacci indices start at 0 and we
  need to store answers from F(0) through F(n).
- Initialize the vector with -1 to mean "not calculated yet".
- Before calculating F(n), check whether dp[n] is already different from -1.
  If it is, return the stored result immediately.
- Otherwise, calculate F(n - 1) + F(n - 2), store the answer in dp[n], and
  return it.
- Each needed Fibonacci state is calculated once and reused.
- TIME COMPLEXITY: O(n).
- The recursive call stack uses additional memory and can cause stack overflow
  for some problems with deep recursion.

6. TABULATION — BOTTOM-UP DP
----------------------------
- Tabulation uses ITERATION (loops) plus a DP table/array.
- Instead of recursively starting from the large problem, solve the smallest
  subproblems first and build up to the required answer. This is BOTTOM-UP.
  
Related examples/variations mentioned:
- 1D DP/Fibonacci-style logic: Climbing Stairs, House Robber, Frog Jump,
  Minimum Jumps with K Steps.
- LCS-related logic can help with related problems such as edit distance;
  the lecture also mentions box stacking and longest bitonic subsequence.
- Road Cutting is described as a direct variation of Knapsack.
- The lecturer emphasizes that many problems share a pattern, so learn the
  core logic, solve several examples of that pattern, and practise related
  problems independently. The lecture estimates that mastering key patterns
  and their variations can cover a large portion of DP interview questions.

9. QUICK REVISION
-----------------
- DP = store intermediate answers to avoid repeated work.
- DP needs BOTH overlapping subproblems and optimal substructure.
- Fibonacci recurrence: F(n) = F(n - 1) + F(n - 2).
- Base cases: F(0) = 0, F(1) = 1.
- Normal recursion: O(2^n) time (lecture's stated complexity).
- Memoization: recursion + cache; top-down; O(n) time for Fibonacci.
- Tabulation: loop + DP table; bottom-up; O(n) time for Fibonacci.
- In tabulation, define the DP state, initialize base cases, then fill from
  small states to large states.
- Learn DP patterns instead of memorizing only individual questions.

===============================================================================
CODE SECTION
===============================================================================
All three functions below solve the same task: return F(n).
The main() function runs each version for the same input so their answers can
be compared. Input should be a non-negative integer n.
*/

#include <iostream>
#include <vector>
using namespace std;

// 1. Normal recursion: directly follows F(n) = F(n-1) + F(n-2).
int fibonacciRecursive(int n) {
    if (n <= 1) {
        return n; // Base cases: F(0) = 0, F(1) = 1.
    }

    // Recalculates overlapping subproblems many times.
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

// Helper for memoization: dp[i] stores F(i); -1 means "not calculated".
int fibonacciMemoHelper(int n, vector<int>& dp) {
    if (n <= 1) {
        return n; // Base cases.
    }

    if (dp[n] != -1) {
        return dp[n]; // Reuse an answer already calculated.
    }

    // Calculate once, save it, and reuse it on future calls.
    dp[n] = fibonacciMemoHelper(n - 1, dp) +
            fibonacciMemoHelper(n - 2, dp);

    return dp[n];
}

// 2. Memoization: top-down DP (recursion + cache).
int fibonacciMemoization(int n) {
    vector<int> dp(n + 1, -1); // Store F(0) through F(n).
    return fibonacciMemoHelper(n, dp);
}

// 3. Tabulation: bottom-up DP (table + loop).
int fibonacciTabulation(int n) {
    if (n <= 1) {
        return n; // Handles n = 0 and n = 1 safely.
    }

    vector<int> dp(n + 1, 0); // dp[i] means F(i).
    dp[0] = 0;                // First known answer.
    dp[1] = 1;                // Second known answer.

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2]; // Build from smaller answers.
    }

    return dp[n]; // The answer to the original problem.
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    if (n < 0) {
        cout << "Please enter a non-negative integer.\n";
        return 0;
    }

    cout << "Normal recursion: " << fibonacciRecursive(n) << '\n';
    cout << "Memoization:      " << fibonacciMemoization(n) << '\n';
    cout << "Tabulation:       " << fibonacciTabulation(n) << '\n';

    return 0;
}

/*
COMPLEXITY SUMMARY
------------------
Approach              Time            Extra space
Normal recursion      O(2^n)          O(n) recursive call stack
Memoization           O(n)            O(n) DP vector + recursion stack
Tabulation            O(n)            O(n) DP vector

Note: This lecture's examples use int, which can overflow for larger Fibonacci
indices. The lecture focuses on the DP concepts; use an appropriately larger
numeric type if extending the implementation.
*/
