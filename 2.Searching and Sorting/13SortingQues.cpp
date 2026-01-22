#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// DUTCH NATIONAL FLAG ALGORITHM (DNF)
// This algorithm is used to sort an array of 0s, 1s and 2s in linear time and constant space.
// It is also known as the three-way partitioning algorithm.
// The algorithm works by maintaining three pointers: low, mid and high. The low pointer keeps track of the position where the next 0 should be placed, the mid pointer keeps track of the current element being processed, and the high pointer keeps track of the position where the next 2 should be placed.
// The algorithm works as follows:

// 1. Initialize low, mid and high pointers to the start, start and end of the array respectively.
// 2. While mid is less than or equal to high, do the following:
//    a. If the current element is 0, swap it with the element at the low pointer and increment both low and mid pointers.
//    b. If the current element is 1, increment the mid pointer.
//    c. If the current element is 2, swap it with the element at the high pointer and decrement the high pointer.
// 3. Repeat step 2 until mid is greater than high.


// The time complexity of this algorithm is O(n) and the space complexity is O(1).

void DNSalgorithm(int arr[], int size){
    int low=0, mid=0, high=size-1;

    while(mid<=high){
        if (arr[mid]==0){

            swap(arr[low],arr[mid]);
            low++;
            mid++;

        } else if (arr[mid]==1){

            mid++;

        } else{

            swap(arr[high],arr[mid]);
            high--;

        }
    }
    return ;
}

// MERGE SORTING TWO ARRAYS
// This algorithm is used to merge two sorted arrays into one sorted array.
// It takes two sorted arrays nums1 and nums2, and their respective sizes m and n. The merged array is stored in nums1.
// It is just a simple implementation of the merge step of the merge sort algorithm, where we are merging two sorted arrays into one sorted array.
// Time complexity is O(m+n) and space complexity is O(1).
// Therefore, we are not using any extra space for the merged array.

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

    int idx = m+n-1, i = m-1, j = n-1;

    while(i>=0 && j>=0){

        if(nums1[i]>nums2[j]){
            nums1[idx]=nums1[i];
            i--;
            idx--;
        } else{
            nums1[idx]=nums2[j];
            j--;
            idx--;
        }
    }
    
    while(j>=0){        // if elements of nums2 are left
        nums1[idx]=nums2[j]; 
        j--;
        idx--;
    }
}

// NEXT PERMUTATION

// This algorithm is used to find the next lexicographical permutation of an array of integers.
// It takes an array of integers nums and its size n as input. The next permutation is stored in the same array nums.
// Lexicographically, the next permutation is the smallest permutation that is greater than the current permutation.
// For example all permutations of [1,2,3] are [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1]. The next lexicographical permutation of [1,2,3] is [1,3,2].
// According to the question, if array is already maximum (i.e. in descending order), then we need to return the minimum permutation of the array. For example, for [3,2,1], the next permutation is [1,2,3].

// Brute force approach is to generate all permutations of the array and sort them. But this is not efficient as it takes O(n! * n) time and is done with the help of recursion.
// The optimised approach is to find the next permutation in O(n) time and O(1) space. The algorithm works as follows:

void nextPermutation(vector<int>& nums) {

    int n = nums.size();
    int pivot = -1;

    for(int i=n-2; i>=0; i--){
        if (nums[i]<nums[i+1]){  // find the first decreasing element from the end
            pivot=i;
            break;
        }
    }
    

    if(pivot==-1){
        int st=0, end=n-1;
        while(st<end){
            swap(nums[st],nums[end]);
            st++;
            end--;
        }
    } else{

        // time complexity of this part is O(n) because we are traversing the array from the end to find the first element greater than pivot.
        for(int i = n-1; i>pivot; i--){    // find the first element greater than pivot from the end
            if(nums[i]>nums[pivot]){
                swap(nums[i],nums[pivot]);
                break;
            }
        }

        // Now we need to reverse the array from pivot+1 to end to get the next permutation.
        int st=pivot+1, end=n-1;

        // This part is also O(n) because we are traversing the array from pivot+1 to end.
        while(st<end){               // reverse the array from pivot+1 to end
            swap(nums[st],nums[end]);
            st++;
            end--;
        }

    }
    
}

int main(){

    int arr[] = {0,2,2,1,1,0,2,0,0,1,2,0,1,1};
    DNSalgorithm(arr,14);

    for(int i=0; i<14; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}