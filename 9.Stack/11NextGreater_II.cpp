#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/* -------------------------------------------------------------
   Tutorial Approach (Efficient and Concise)
   -------------------------------------------------------------
   - This version uses a single loop from 2*n - 1 down to 0.
   - It handles the circular array using modulo (i % n).
   - For each element, it finds the next greater element 
     by maintaining a stack of potential next greater values.
   - Time Complexity: O(2N) ≈ O(N)
   - Space Complexity: O(N)
*/
vector<int> tutorialApproach(vector<int>& nums) {
    int n = nums.size();
    stack<int> s;
    vector<int> ans(n, -1);

    for (int i = 2 * n - 1; i >= 0; i--) {
        int idx = i % n;

        // Remove all smaller or equal elements
        while (!s.empty() && s.top() <= nums[idx]) s.pop();

        // If stack not empty, top element is next greater
        if (!s.empty()) ans[idx] = s.top();

        // Push current element
        s.push(nums[idx]);
    }

    return ans;
}

/* -------------------------------------------------------------
   My Trial Approach (Two-Phase Logic)
   -------------------------------------------------------------
   - This was your initial version where you manually repeated
     the loop twice to simulate circular behavior.
   - It also uses a stack to find the next greater element,
     but uses a loop counter (t) to manage the repetition.
   - Logical but slightly longer than the tutorial version.
   - Time Complexity: O(2N)
   - Space Complexity: O(N)
*/
vector<int> myTrialApproach(vector<int>& nums) {
    int n = nums.size();
    stack<int> s;
    vector<int> ans(n, -1);
    int t = 1;

    for (int i = n - 1; i >= 0; i--) {
        // Remove smaller or equal elements
        while (!s.empty() && s.top() <= nums[i]) s.pop();

        // If stack not empty, top element is next greater
        if (!s.empty()) ans[i] = s.top();

        // Push current element
        s.push(nums[i]);

        // Repeat the loop once more for circularity
        if (i == 0 && t < 2) {
            i = n; // Reset i to run loop again
            t++;
        }
    }

    return ans;
}

/* -------------------------------------------------------------
   Main Function (Test both approaches)
   ------------------------------------------------------------- */
int main() {
    vector<int> nums = {1, 2, 1};

    vector<int> ans1 = tutorialApproach(nums);
    vector<int> ans2 = myTrialApproach(nums);

    cout << "Tutorial Approach Output: ";
    for (int x : ans1) cout << x << " ";
    cout << endl;

    cout << "My Trial Approach Output: ";
    for (int x : ans2) cout << x << " ";
    cout << endl;

    return 0;
}
