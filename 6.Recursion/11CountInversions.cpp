#include <iostream>
#include <cstring> 
#include <string> 
#include <vector>
#include <algorithm> 
#include <set>
#include <cmath> // For mathematical functions like log10

using namespace std;

// Merge function to merge two halves and count inversions

// Que: Given an array of integers. Find the number of inversions in the array.
// An inversion is a pair (i, j) such that i < j and arr[i] > arr[j].

// Example: arr = [2, 4, 1, 3, 5]
// Inversions: (2, 1), (4, 1), (4, 3)
// Total inversions = 3


#include <bits/stdc++.h>   // includes all standard libraries
using namespace std;

/*
    Function: merge
    ----------------
    This function merges two sorted subarrays of nums[]:
        - Left subarray:  nums[l ... mid]
        - Right subarray: nums[mid+1 ... r]
    
    While merging, it also counts "inversions".
    An inversion is a pair (i, j) such that:
        - i < j
        - nums[i] > nums[j]
*/
int merge(vector<int>& nums, int l, int mid, int r) {
    int i = l;          // pointer for left subarray
    int j = mid + 1;    // pointer for right subarray
    int invCount = 0;   // count of inversions
    vector<int> temp;   // temporary array to store merged result

    // Merge the two sorted halves
    while (i <= mid && j <= r) {
        if (nums[i] <= nums[j]) {
            // If current element in left <= current element in right,
            // then no inversion (since left part is already sorted).
            temp.push_back(nums[i]);
            i++;
        } else {
            // If nums[i] > nums[j], then all elements from nums[i] to nums[mid]
            // will form inversions with nums[j].
            temp.push_back(nums[j]);
            invCount += (mid - i + 1);  // count all these inversions
            j++;
        }
        // WE ARE BASICALLY CALCULATING INVERSIONS OF nums[j] IN EACH STEP
    }

    // Copy remaining elements of left subarray (if any)
    while (i <= mid) {
        temp.push_back(nums[i]);
        i++;
    }

    // Copy remaining elements of right subarray (if any)
    while (j <= r) {
        temp.push_back(nums[j]);
        j++;
    }

    // Copy the sorted merged elements back into original nums[]
    for (int k = 0; k < temp.size(); k++) {
        nums[l + k] = temp[k];
    }

    return invCount; // return total inversions counted during this merge
}

/*
    Function: CountInversions
    --------------------------
    This function applies divide and conquer (merge sort style):
    - Recursively divides the array into two halves.
    - Counts inversions in the left half.
    - Counts inversions in the right half.
    - Counts inversions formed between two halves during merge.

    Finally, returns the total inversion count.
*/
int CountInversions(vector<int>& nums, int l, int r) {
    if (l < r) {
        int mid = l + (r - l) / 2;

        // Count inversions in left half
        int leftInvCount = CountInversions(nums, l, mid);

        // Count inversions in right half
        int rightInvCount = CountInversions(nums, mid + 1, r);

        // Count cross inversions while merging two halves
        int mergeInvCount = merge(nums, l, mid, r);

        // Total inversions = left + right + cross
        return leftInvCount + rightInvCount + mergeInvCount;
    }
    return 0; // base case: if l >= r (single element), no inversion
}

/*
    Driver function
*/
int main() {
    vector<int> nums = {2, 4, 1, 3, 5};  // Example input
    int n = nums.size();

    // Count total inversions using merge-sort based algorithm
    int inversionCount = CountInversions(nums, 0, n - 1);

    // Output the result
    cout << "Total Inversions: " << inversionCount << endl;

    return 0;
}
