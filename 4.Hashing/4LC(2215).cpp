#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;


vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> s1(nums1.begin(), nums1.end());
    unordered_set<int> s2(nums2.begin(), nums2.end());

    vector<int> v1, v2;

    for (int x : s1) {
        if (s2.find(x) == s2.end())
            v1.push_back(x);
    }

    for (int x : s2) {
        if (s1.find(x) == s1.end())
            v2.push_back(x);
    }

    return {v1, v2};
}

int main() {
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {2, 4, 6};

    vector<vector<int>> result = findDifference(nums1, nums2);

    cout << "Unique to nums1: ";
    for (int num : result[0]) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Unique to nums2: ";
    for (int num : result[1]) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}