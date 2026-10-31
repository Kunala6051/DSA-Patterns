#include <bits/stdc++.h>
using namespace std;

// Approach 1: Brute Force - Nested Loops
int majorityBrute(vector<int>& nums) {
    int n = nums.size();

    for(int i = 0; i < n; i++) {
        int count = 0;

        for(int j = 0; j < n; j++) {
            if(nums[i] == nums[j]) count++;
        }

        if(count > n/2) return nums[i];
    }

    return -1;
}

// Approach 2: Hash Map
int majorityHashing(vector<int>& nums) {
    int n = nums.size();

    unordered_map<int,int> f;

    for(int i = 0; i < n; i++) {
        f[nums[i]]++;

        if(f[nums[i]] > n/2)
            return nums[i];
    }

    return -1;
}

// Approach 3: Sorting
int majoritySorting(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    return nums[nums.size()/2];
}

// Approach 4: Moore's Voting Algorithm
int majorityMoore(vector<int>& nums) {
    int n = nums.size();

    /*
       The majority element appears more than n/2 times.
       Different elements cancel each other out, so the majority
       element will always remain as the final candidate.

       If count becomes 0, choose a new candidate.
       Increment count if the current element matches the candidate;
       otherwise, decrement it.
    */

    int ans = 0;
    int count = 0;

    for(int i = 0; i < n; i++) {
        if(count == 0) ans = nums[i];

        if(nums[i] == ans) count++;
        else count--;
    }

    return ans;
}

int main() {
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    vector<int> a = nums;
    vector<int> b = nums;
    vector<int> c = nums;
    vector<int> d = nums;

    cout << "Brute Force: " << majorityBrute(a) << endl;
    cout << "Hash Map: " << majorityHashing(b) << endl;
    cout << "Sorting: " << majoritySorting(c) << endl;
    cout << "Moore's Voting: " << majorityMoore(d) << endl;

    return 0;
}