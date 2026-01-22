#include <bits/stdc++.h>
using namespace std;

// Leetcode: 84. Largest Rectangle in Histogram

// Time Complexity: O(n) for traversing the heights array 3 times
// Space Complexity: O(n) for leftSmaller and rightSmaller arrays

int largestRectangleArea(vector<int>& heights) {
    // Store index of next smaller element to the right
    vector<int> rightSmaller(heights.size(), 0);
    stack<int> s;

    // Find right smaller for each bar
    for(int i = heights.size() - 1; i >= 0; i--) {
        if(s.empty()) {
            rightSmaller[i] = -1; // no smaller element on right
            s.push(i);
        } else {
            while(!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            if(s.empty()) rightSmaller[i] = -1;
            else rightSmaller[i] = s.top(); // index of next smaller to right
            s.push(i);
        }
    }

    // Clear stack to reuse
    while(!s.empty()) s.pop();

    // Store index of previous smaller element to the left
    vector<int> leftSmaller(heights.size(), 0);

    // Find left smaller for each bar
    for(int i = 0; i < heights.size(); i++) {
        if(s.empty()) {
            leftSmaller[i] = -1; // no smaller element on left
            s.push(i);
        } else {
            while(!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            if(s.empty()) leftSmaller[i] = -1;
            else leftSmaller[i] = s.top(); // index of previous smaller to left
            s.push(i);
        }
    }

    int ans = 0;

    // Calculate area for each bar using width between left and right smaller
    for(int i = 0; i < heights.size(); i++) {
        int a = leftSmaller[i];
        int b = rightSmaller[i];
        if(b == -1) b = heights.size(); // handle no smaller on right
        int width = b - a - 1;
        int area = heights[i] * width;
        ans = max(area, ans); // keep max area
    }

    return ans; // largest rectangle area
}
