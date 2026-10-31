#include <bits/stdc++.h>
using namespace std;

/*
LeetCode 128 - Longest Consecutive Sequence

Problem: Given an unsorted array of integers, find the length
of the longest consecutive elements sequence.

The sequence must consist of consecutive integers, and
the solution should run in O(N) time for the optimal approach.
*/


// Approach 1: Brute Force - O(N^2)

bool search(int a, const vector<int>& nums) {
    for(int i : nums) {
        if(i == a) return true;
    }
    return false;
}

int longestConsecutiveBrute(vector<int>& nums) {
    int n = nums.size();
    int ans = 0;

    for(int i = 0; i < n; i++) {
        int a = nums[i] + 1;
        int c = 1;

        while(search(a, nums)) {
            c++;
            a++;
        }

        ans = max(ans, c);
    }

    return ans;
}


// Approach 2: Sorting - O(N log N)

int longestConsecutiveSorting(vector<int>& nums) {
    int n = nums.size();
    if(n == 0) return 0;

    sort(nums.begin(), nums.end());

    int ans = 0;
    int c = 1;

    for(int i = 0; i < n-1; i++) {
        if(nums[i] + 1 == nums[i+1]) {
            c++;
        }
        else if(nums[i] == nums[i+1]) {
            continue;
        }
        else {
            ans = max(c, ans);
            c = 1;
        }
    }

    ans = max(c, ans);
    return ans;
}


// Approach 3: Hash Set - O(N) Expected

/*
Approach:
1. Use an unordered_set to store unique elements and provide
   expected O(1) lookup instead of repeatedly searching the array.

2. If i-1 exists in the set, skip i because it cannot be the
   starting element of a consecutive sequence.

3. Iterate over the set instead of nums because the set contains
   only unique elements. This avoids processing the same starting
   element multiple times due to duplicates in the original array.

4. Once a starting element is found, keep checking i+1, i+2, etc.
   and update the maximum sequence length.
*/

int longestConsecutiveOptimal(vector<int>& nums) {
    unordered_set<int> s;

    for(int i : nums) {
        s.insert(i);
    }

    int ans = 0;

    for(int i : s) {

        if(s.find(i-1) != s.end()) continue;

        int a = i;
        int c = 1;

        while(s.find(a+1) != s.end()) {
            c++;
            a++;
        }

        ans = max(ans, c);
    }

    return ans;
}


int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2, 2};

    vector<int> a = nums;
    vector<int> b = nums;
    vector<int> c = nums;

    cout << "Brute Force: "
         << longestConsecutiveBrute(a) << endl;

    cout << "Sorting: "
         << longestConsecutiveSorting(b) << endl;

    cout << "Hash Set (Optimal): "
         << longestConsecutiveOptimal(c) << endl;

    return 0;
}