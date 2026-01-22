#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Leetcode: 42. Trapping Rain Water
// Given n non-negative integers representing an elevation map where the width of each bar is 1, 
// compute how much water it can trap after raining.

int bruteForce(vector<int>& height) {
    int n = height.size();  // total number of bars
    int ans = 0;            // variable to store total trapped water

    // Traverse each bar in the elevation map
    for (int i = 0; i < n; i++) {

        // Find the tallest bar to the right of current index
        int maxiR = height[i];
        for (int j = i + 1; j < n; j++) {
            maxiR = max(maxiR, height[j]);
        }

        // Find the tallest bar to the left of current index
        int maxiL = height[i];
        for (int j = 0; j < i; j++) {
            maxiL = max(maxiL, height[j]);
        }

        // Water trapped at current index =
        // (minimum of left and right max heights) - current height
        int w = min(maxiL, maxiR) - height[i];

        // Add trapped water at this index to total
        ans += w;
    }

    // Return total trapped water
    return ans;
}
// O(n^2) time complexity
// O(1) space complexity


int prefixArray(vector<int>& height) {
    int n = height.size();  // total number of bars

    // Arrays to store maximum height to the left and right of each index
    vector<int> leftMax(n, 0);
    vector<int> rightMax(n, 0);

    // Initialize boundary values
    leftMax[0] = height[0];         // first element has no left side
    rightMax[n - 1] = height[n - 1]; // last element has no right side

    // Compute maximum height to the left of every index
    for (int i = 1; i < n; i++) {
        leftMax[i] = max(leftMax[i - 1], height[i]);
    }

    // Compute maximum height to the right of every index
    for (int i = n - 2; i >= 0; i--) {
        rightMax[i] = max(rightMax[i + 1], height[i]);
    }

    int ans = 0;  // total trapped water

    // Calculate trapped water at each position
    for (int i = 0; i < n; i++) {
        // Water trapped at index i =
        // minimum of leftMax and rightMax minus current height
        int w = min(leftMax[i], rightMax[i]) - height[i];

        ans += w; // accumulate trapped water
    }

    // Return the total trapped water
    return ans;
}

// O(n) time complexity
// O(n) space complexity


int twoPointerTrap(vector<int>& height) {
    int n = height.size();
    int ans = 0;              // total trapped water
    int l = 0, r = n - 1;     // two pointers at both ends
    int lmax = 0, rmax = 0;   // max heights seen so far from left and right

    while (l < r) {
        lmax = max(lmax, height[l]);   // update left max
        rmax = max(rmax, height[r]);   // update right max

        if (lmax < rmax) {             // left side is limiting
            ans += lmax - height[l];   // water trapped at left
            l++;                       // move left pointer
        } else {                       // right side is limiting
            ans += rmax - height[r];   // water trapped at right
            r--;                       // move right pointer
        }
    }

    return ans;   // return total trapped water
}




int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};

    int result = bruteForce(height);
    cout << "Total trapped rain water: " << result << endl;

    int result2 = prefixArray(height);
    cout << "Total trapped rain water (Prefix Array): " << result2 << endl;

    int result3 = twoPointerTrap(height);
    cout << "Total trapped rain water (Two Pointer): " << result3 << endl;

    return 0;
}