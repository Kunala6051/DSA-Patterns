#include <iostream>
#include <cstring> 
#include <string> 
#include <vector>
#include <algorithm> 
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <cmath> 

using namespace std;

// Leet code: 1
// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.


// First approach is BRUTE FORCE in which two nested loops are there and the time complexity is O(n^2)


// Second approach is SORTING an array and using TWO POINTER APPROACH 
// one pointer at the starting other at end and shifting pointers according to the requirement
// Time Complexity: O(nlogn)


// By using HASHING 
// Unordered maps are used for fast calculations
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> combo; // this will store pairs of elements and their index
    vector <int> ans;

    for (int i=0; i<nums.size();i++){ // O(n)

        int first = nums[i];
        int sec = target - first;

        if(combo.find(sec)!=combo.end()){ // if the second number needed exists in unordered map
            // means we have both the element and their indices whose sum is equal to target
            // Time complexity of finf function is considered to be O(1)
            ans.push_back(i);
            ans.push_back(combo[sec]);
            break;
        }

        combo[first]=i; // if element not found in map add it
    }

    return ans;
        
}
// Time Complexity: O(n)


// Leet code: 2965

// You are given a 0-indexed 2D integer matrix grid of size n * n with values in the range [1, n2]. 
//Each integer appears exactly once except a which appears twice and b which is missing.
// The task is to find the repeating and missing numbers a and b.
// Return a 0-indexed integer array ans of size 2 where ans[0] equals to a and ans[1] equals to b.

vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    unordered_set <int> s;
    int n = grid.size();
    int repeated, missing;
    int actualSum=0;
    vector<int> res;

    for(int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            actualSum+=grid[i][j];
            if (s.find(grid[i][j])!=s.end()){
                repeated = grid[i][j];
                res.push_back(repeated);
            }
            s.insert(grid[i][j]);
        }
    }

    int expectedSum = n*n * (n*n + 1) / 2; // n(n+1)/2 [number ofelements in grid = n^2]
        
    // actualSum = expectedSum + repeated - missing;
    missing = expectedSum + repeated - actualSum;
    res.push_back(missing);

    return res;
}
// Time Complexity: O(n^2)



// Leet code: 287

// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
// There is only one repeated number in nums, return this repeated number.
// You must solve the problem without modifying the array nums and using only constant extra space.

// Using sets
int findDuplicate(vector<int> vec){
    unordered_set<int> s;
    for (int i=0; i<vec.size();i++){
        if(s.find(vec[i])!=s.end()){
            return vec[i];
        }
        s.insert(vec[i]);

    }
} 
// Time Complexity: O(n^2) 
// Space Complexity: O(n) (We used an unordered set)






// Lets understand the linked list briefly

// A linked list is a linear data structure where elements (called nodes) are linked using pointers.
// Unlike arrays, linked lists don't require contiguous memory locations.
// Each node contains:
// 1. Data (value)
// 2. Pointer to the next node (i.e., next)


//  How a Cycle Forms When Modeling Arrays as Linked Lists

// Treat each index as a node.
// Treat the value at that index as the pointer to the next node.
// This converts an array into a "virtual" linked list.

// Example:
// Array: [3, 1, 3, 4, 2] (index 0 to 4)

// We map:
// 0 → 3 (go to index 3) 
// 3 → 4 (go to index 4)
// 4 → 2
// 2 → 3 → back to index 3 → forms a cycle [As two values point to same element]

// This shows how a duplicate value causes two nodes to point to the same node, creating a cycle.



// We treat the array like a linked list where nums[i] points to the next index.
// A duplicate value creates a cycle in this list.
// The point where both pointers meet in phase 2 is the start of the cycle, i.e., the duplicate number.

int findDuplicateOptimized(vector<int>& nums) {
    // Initialize two pointers starting at the first element
    int slow = nums[0], fast = nums[0];

    // Phase 1: Detect cycle using Floyd’s Tortoise and Hare algorithm
    do {
        slow = nums[slow];           // Move slow by 1 step (element itself acting as an index for next element of the linked list)
        fast = nums[nums[fast]];     // Move fast by 2 steps
    } while (slow != fast);          // Loop until they meet inside the cycle

    // Phase 2: Find the entry point of the cycle (duplicate number)
    slow = nums[0];                  // Reset slow to the start

    while (slow != fast) {
        slow = nums[slow];          // Move both by 1 step 
        fast = nums[fast];
    }

    // Both pointers meet at the duplicate value
    return slow;
}
// Time Complexity: O(n)
// Space Complexity: O(1)






// THREE SUM (Leet code: 15)

// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
// such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
// Notice that the solution set must not contain duplicate triplets.


// Brute Force
vector <vector<int>> threeSumBruteF(vector<int> nums){
    vector <vector<int>> result;
    int n = nums.size();

    set <vector<int>> s;

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){

                if (nums[i]+nums[j]+nums[k]==0){

                    // REALLY IMPORTANT ########

                    // Now we dont want to store the permutations of triplets like [-1,0,1] and [0,1,-1]
                    // Therefore we will use sets to store the sorted vectors as then they both will become equal i.e [-1,0,1] , [-1,0,1]

                    // Now why we didnt use unordered set here even if the timr complexity of these sets is O(n)????
                    // It is because there is no default hashing in the unordered sets 
                    // we have to write custom hashes which can be trickier sometimes

                    vector<int> trip = {nums[i],nums[j],nums[k]};
                    sort(trip.begin(),trip.end());

                    if(s.find(trip)==s.end()){ // If element not found in set
                        s.insert(trip);
                        result.push_back(trip); // [THIS IS THE MAIN GOAL]
                    }


                }

            }
        }
    }
    return result;
}
// Time Complexity: O(n^3 * log(unique triplets)) // Time Complexity of functions of set is logn where as of unordered sets is O(1)
// Space Complexity: O(unique triplets * 2) => O(unique triplets) [2 is constant]
//                   [one for vector other for set]



// Using Hashing to solve the 3Sum problem
vector<vector<int>> threeSumHashing(vector<int> nums) {

    int n = nums.size();
    
    // Set to store only unique triplets (no duplicates)
    set<vector<int>> uniqueTriplets;

    // Fix the first element one by one
    for (int i = 0; i < n; i++) {

        // We want to find two numbers such that: nums[i] + nums[j] + nums[k] = 0
        // So, target is the number we want the next two numbers to sum to
        int target = -nums[i];

        // Set to store seen numbers for the current i
        set<int> s;

        // Loop through the rest of the array (after i)
        for (int j = i + 1; j < n; j++) {

            // third is the number we need to complete the triplet
            int third = target - nums[j];

            // If we already saw 'third' before, we found a valid triplet
            if (s.find(third) != s.end()) {

                // Make a triplet of nums[i], nums[j], and third
                vector<int> trip = {nums[i], nums[j], third};

                // Sort to handle different orders of the same triplet
                sort(trip.begin(), trip.end());

                // Insert into the set (only unique triplets will be kept)
                uniqueTriplets.insert(trip);
            }

            // Add current number to the set
            s.insert(nums[j]);
        }
    }

    // Convert the set into a vector to return
    vector<vector<int>> result(uniqueTriplets.begin(), uniqueTriplets.end());
    return result;
}
// Time Complexity: O(n^2 * log(unique triplets)) 
// Space Complexity: O(unique triplets + n)  [every time a set s is initialized in which in worst case n elements are going to be stored]


// Now In all the cases above we used sorting and sets to avoid storing duplicate triplets,
// here in this two pointer Approach, we will sort the array in the beggining to make two-pointer approach possible

vector<vector<int>> threeSumTwoPointer(vector<int>& nums) {
    vector<vector<int>> result;
    int n = nums.size();

    // Step 1: Sort the array to make two-pointer approach possible
    sort(nums.begin(), nums.end());       // Time Complexity: O(n logn)

    // Step 2: Traverse the array and fix one number at a time
    for(int i = 0; i < n; i++) {
        // Skip duplicate values for the fixed number to avoid duplicate triplets
        if(i > 0 && nums[i] == nums[i - 1]) continue;

        // Two pointers approach
        int j = i + 1;       // start pointer
        int k = n - 1;       // end pointer

        while(j < k) {
            int sum1 = nums[i] + nums[j] + nums[k];

            // If the triplet sum is zero, store the result
            if(sum1 == 0) {
                vector<int> ans = {nums[i], nums[j], nums[k]};
                result.push_back(ans);
                j++;
                k--;

                // Skip duplicates for the second number to avoid duplicate triplets
                while(j < k && nums[j] == nums[j - 1]) {
                    j++;
                }
            }
            // If sum is too big, move right pointer to decrease the sum
            else if(sum1 > 0) {
                k--;
            }
            // If sum is too small, move left pointer to increase the sum
            else {
                j++;
            }
        }
    }

    return result;
}
// Time Complexity: O(nlogn + n^2) 
// Space Complexity: O(unique triplets)









// FOUR SUM (Leet code: 18)
// Given an array nums of n integers, 
//return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
// 0 <= a, b, c, d < n
// a, b, c, and d are distinct.
// nums[a] + nums[b] + nums[c] + nums[d] == target
// You may return the answer in any order.

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> result;
    int n = nums.size();

    // Step 1: Sort the array to apply two-pointer technique later
    sort(nums.begin(), nums.end());    // Time Complexity: O(n logn)

    // Step 2: First loop to fix the first element
    for (int i = 0; i < n; i++) {
        // Skip duplicates for the first element
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        // Step 3: Second loop to fix the second element
        for (int j = i + 1; j < n;) {
            int k = j + 1;       // third element (start of two-pointer)
            int l = n - 1;       // fourth element (end of two-pointer)

            // Step 4: Use two pointers to find remaining two elements
            while (k < l) {
                // Use long long to avoid integer overflow
                long long sum1 = (long long)nums[i] + (long long)nums[j] + 
                                (long long)nums[k] + (long long)nums[l];

                // Move pointers based on sum comparison with target
                if (sum1 > target) {
                    l--;  // Sum is too big, move right pointer leftward
                } else if (sum1 < target) {
                    k++;  // Sum is too small, move left pointer rightward
                } else {
                    // Found a valid quadruplet
                    result.push_back({nums[i], nums[j], nums[k], nums[l]});
                    k++;
                    l--;

                    // Skip duplicates for the third element
                    while (k < l && nums[k] == nums[k - 1]) {
                        k++;
                    }
                }
            }

            // Move to next second element
            j++;

            // Skip duplicates for the second element
            while (j < n && nums[j] == nums[j - 1]) {
                j++;
            }
        }
    }

    return result;
}

// Why we did not increment j in loop:

// Not incrementing j in the loop declaration gives you full control over when and how j should advance.
// You manually handle both the j++ and duplicate skipping in the loop body.

// Time Complexity: O(nlogn + n^3) 




// LeetCode: 560 [Subarray Sum Equals K]

// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
// A subarray is a contiguous non-empty sequence of elements within an array.

 
// Calculating sum of all subarrays
int subarraySumBrute(vector<int>& nums, int k) {
    int count = 0;           // To store the number of subarrays whose sum is equal to k
    int n = nums.size();     // Get the size of the input array

    // Outer loop picks the starting index of subarray
    for(int i = 0; i < n; i++) {
        int sum = 0;         // Initialize sum for this starting index

        // Inner loop calculates sum of subarray starting from index i to j
        for(int j = i; j < n; j++) {
            sum += nums[j];  // Add current element to the sum

            // If sum equals k, we found a valid subarray
            if(sum == k) {
                count++;     // Increment count of valid subarrays
            }
        }
    }

    return count;            // Return total number of subarrays with sum equal to k
}
// Time Complexity: O(n^2)
// Space Complexity: O(1)



// Using prefix Sums and HASHING(unordered maps)

int subarraySum(vector<int>& nums, int k) {
    int count = 0;                    // Count of subarrays whose sum is equal to k
    int n = nums.size();             // Size of the input array
    int prefixSums[n];               // Array to store prefix sums

    // Step 1: Build the prefix sum array
    // prefixSums[i] stores the sum of elements from nums[0] to nums[i]
    prefixSums[0] = nums[0];
    for (int i = 1; i < n; i++) {
        prefixSums[i] = prefixSums[i - 1] + nums[i];
    }

    // Step 2: Use a hashmap to store the frequency of each prefix sum encountered
    unordered_map<int, int> m;

    // Step 3: Traverse the prefix sum array to count valid subarrays
    for (int j = 0; j < n; j++) {
        
        // Case 1: If prefix sum itself is equal to k, then subarray from 0 to j is valid
        if (prefixSums[j] == k) {
            count++;
        }

        // Case 2: Check if there is a previous prefix sum such that:
        //         current_prefixSum - previous_prefixSum == k
        //         => subarray sum between those indices is k
        int value = prefixSums[j] - k;
        if (m.find(value) != m.end()) {
            count += m[value]; // Add the frequency of that prefix sum
        }

        // Step 4: Update the frequency of current prefix sum in the map
        // If prefixSums[j] already exists, increment its frequency
        if (m.find(prefixSums[j]) != m.end()) {
            m[prefixSums[j]]++;
        } else {
            // Otherwise, insert it with frequency 1
            m[prefixSums[j]] = 1;
        }
    }

    // Step 5: Return the total count of valid subarrays
    return count;
}
// Time Complexity: O(n)
// Space Complexity: O(n) // (array and map)


int main(){

    cout << "OM NAMAHA SHIVAY" << endl;

    vector<int> nums = {1,2,3,4,5,6,7,14,14};
    vector<int> result = twoSum(nums,13);
    for(int i: result){
        cout << i << " ";
    }
    
    cout << endl;

    vector<int> nums2 = {3,1,3,4,2};

    cout << "Repeated Element: " << findDuplicate(nums) << endl;
    cout << "Repeated Element: " << findDuplicateOptimized(nums2) << endl;

    vector<int> nums3 = {3,1,3,4,2,-1,-2,0};
    vector <vector<int>> result2 = threeSumBruteF(nums3);
    
    for(int i=0; i<result2.size(); i++){
        for (int j=0; j<3; j++){
            cout << result2[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    vector <vector<int>> result3 = threeSumHashing(nums3);
    for(int i=0; i<result3.size(); i++){
        for (int j=0; j<3; j++){
            cout << result3[i][j] << " ";
        }
        cout << endl;
    }


    unordered_set <int> k;
    k.insert(1);
    k.insert(2);
    k.insert(1);
    // printing elements of a set
    for(int elem: k){
        cout << elem << " ";
    }
    cout << endl;


}