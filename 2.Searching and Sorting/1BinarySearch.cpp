#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// U have already learned binary search in kalvium but here is one problem with the approach 

// The formula to calculate mid is (low+high)/2 but it can cause overflow in case of large numbers 
// as it can exceed the range of int because values of low and high can be large

// (high + low - low + low) / 2   =>   (high - low + 2low) / 2   =>   low + (high-low)/2
// So the formula to calculate mid is can be wriiten as low + (high-low)/2
// This will not cause overflow as we are not adding high and low directly




// BOOK ALLOCATION PROBLEM
// Given n books and m students, we have to allocate books to students such that the maximum number of pages allocated to a student is minimized.
// The books are arranged in a row and the students can be allocated any number of books but the maximum number of pages allocated to a student should be minimized.
// Each element of the array represents the number of pages in a book.
// For example, if the array is [100, 200, 300, 400] and the number of students is 2, then the maximum number of pages allocated to a student is 500.
// Possible
// SEARCH IN ROTATED SORTED ARRAY

// Given an array of n elements which is sorted and then rotated at some pivot.
// Find the index of the target element in the array. If not found, return -1.
// The array is sorted in ascending order and the pivot is the index where the array is rotated.
// For example, if the array is [1, 2, 3, 4, 5] and it is rotated at index 2, the array becomes [3, 4, 5, 1, 2].

// In this problem, either the left half or the right half of the array will be sorted.
// We can use binary search to find the pivot and then search for the target element in the sorted half.
// The time complexity of this approach is O(log n) and the space complexity is O(1).

int search(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2; // Avoid overflow

        if (arr[mid] == target) {
            return mid; // Target found
        }

        // Check if the left half is sorted
        if (arr[low] <= arr[mid]) {
            // Left half is sorted
            
            if (arr[low] <= target && target < arr[mid]) { // Target is in the left half
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else { // Right half is sorted
            // Target is in the right half
            if (arr[mid] < target && target <= arr[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    return -1; // Target not found
}



// FIND PEAK ELEMENT IN A MOUNTAIN ARRAY
// A peak element is an element which is greater than or equal to its neighbours.
// [1,3,5,7,8,5,2,1] => 8 is the peak element (arr[i-1]<arr[i]>arr[i+1])
// Mountain array is an array which is first increasing and then decreasing.
// The peak element is the maximum element in the array.

// Hence, it is a mountain array, the start and ending element of an array can never be the peak element.

int linearSearch(int arr[], int n){  // Time Complexity: O(n)
    
    for (int i=1; i<n-1; i++){
        if (arr[i-1]<arr[i] && arr[i]>arr[i+1]){
            return arr[i];
        }
    }
}

// Using binary search to find the peak element in a mountain array
// Time Complexity: O(log n) and Space Complexity: O(1)

// if the mid element is greater than its previous element and next element, then it is the peak element
// if the mid element is greater than its previous element, then the peak element lies in the right half of the array
// if the mid element is greater than its next element, then the peak element lies in the left half of the array
// Hence, we can use binary search to find the peak element in a mountain array.

int binarySearch(int arr[], int n){

    int low=1, high=n-2;   // Check the values

    // suppose the value of low is 0, and in a case the value of mid becomes equal to the low, then in that case (mid - 1) 
    // will not exist. Similar in the case of the value of high.

    // Moreover we also know that the starting and ending elements can never be the peak elements.
    
    while(low<=high){
        int mid= low + (high-low)/2;

        if(arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1]){
            return arr[mid];
        }

        if (arr[mid-1]<arr[mid] && arr[mid]<arr[mid+1]){  // mid is on the increasing side

            low=mid+1;          // peak element lies on the right side

        } else{                 // mid is on the decreasing side

            high=mid-1;         // peak element lies on the left side

        }
    }
}



// SEARCH SINGLE ELEMENT IN A SORTED ARRAY

// Given a sorted array of n elements, find the element which is not repeated.
// The array is sorted in ascending order and the element which is not repeated is the only element which is not present in the array twice.
// For example, if the array is [1, 1, 2, 2, 3, 3, 4], the element which is not repeated is 4.

// The time complexity of this approach is O(log n) and the space complexity is O(1).
// The approach is to use binary search to find the element which is not repeated.

int searchSingleElement(int arr[], int n) {
    int low = 0, high = n - 1;

    if(n == 1) {
        return arr[0]; // Only one element in the array
    }
    while (low <= high) {

        int mid = low + (high - low) / 2; // Avoid overflow

        // Edge Cases

        if(mid==0 && arr[0]!=arr[1]){
            return arr[mid]; // First element is the single element
        }
        if(mid==n-1 && arr[n-1]!=arr[n-2]){
            return arr[mid]; // Last element is the single element
        }

        if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1]) {
            return arr[mid]; // Single element found
        }


        // Check if mid is even or odd
        if (mid % 2 == 0) {
           // If mid is even, the number of elements on the left and right side should be even
           
           // If mid is even, check if the next element is the same as mid 
            if (arr[mid] == arr[mid + 1]) {
                low = mid + 1; // Move to the right half 
            } else {
                high = mid-1; // Move to the left half
            }

        } else {
            // If mid is odd, the number of elements on the left and right side should be odd
            
            // If mid is odd, check if the next element is the same as mid
            if (arr[mid] == arr[mid + 1]) {
                high = mid - 1; // Move to the left half
            } else {
                low = mid + 1; // Move to the right half
            }
        }
    }
    return -1; 
}

// BOOK ALLOCATION PROBLEM
// Given n books and m students, we have to allocate books to students such that the maximum number of pages allocated to a student is minimized.
// The books are arranged in a row and the students can be allocated any number of books but the maximum number of pages allocated to a student should be minimized.
// Each element of the array represents the number of pages in a book.
// For example, if the array is [100, 200, 300, 400] and the number of students is 2, then the monimised maximum number of pages allocated to a student is 600.
// Possible allocations are [100, 200] and [300, 400] or [100, 200, 300] and [400] or [100] and [200, 300, 400].
// The minimum maximum number of pages allocated to a student is 600.
// Allocating books to students is a binary search problem.

// The time complexity of this approach is O(n log sum) and the space complexity is O(1).
// Where n is the number of books and sum is the sum of all the pages in the array.


// The approach is based on binary search. We can use binary search to find the maximum number of pages allocated to a student.
// Firstly we will find the range in which the maximum number of pages allocated to a student can lie.
// The range will be from 0 to the sum of all the pages in the array.

bool isValid(int arr[], int n, int m, int maxAllowedPages){

    int student = 1;
    int pages=0;

    for (int i=0; i<n; i++){

        if(arr[i]>maxAllowedPages){
            return false;
        }

        if (pages + arr[i] <= maxAllowedPages){
            pages+=arr[i];
        } else {
            student++;
            pages=arr[i]; // initializing pages(1st book allocated) for another student
        }
    }

    if (student>m){
        return false;
    } else {
        return true;
    }

}

int allocateBooks(int arr[], int n, int m){

    if(m>n){
        return -1;
    }
    
    int sum=0;

    for (int i=0; i<n; i++){
        sum+=arr[i];
    }

    int ans=-1;
    int st=0, end=sum;

    while(st<=end){

        int mid = st + (end-st)/2;

        if (isValid(arr,n,m,mid)){ // if valid, then we can allocate books to students and try to find a better answer on the left side

            ans=mid; // update the answer
            end=mid-1; // try to find a better answer on the left side

        } else { // if not valid, then we have to increase the maximum number of pages allocated to a student
            st=mid+1; // try to find a answer on the right side
        } 
    }

    return ans;
}


// PAINTER PARTITION PROBLEM

// Given n boards and m painters, we have to paint the boards such that the minimum time to paint the boards by painters is minimized.
// The boards are arranged in a row and the painters can be allocated any number of boards but the time to paint the boards by painters should be minimized.
// Each element of the array represents the length of a board.
// The time taken to paint a board is equal to the length of the board.
// The time taken to paint the boards is equal to the maximum time taken by a painter to paint the boards allocated to him.
// For example, if the array is [1, 2, 3, 4] and the number of painters is 2, then the maximum time to paint the boards is 6.
// Possible allocations are [1, 2] and [3, 4] or [1, 2, 3] and [4] or [1] and [2, 3, 4].
// The minimum maximum time to paint the boards is 6 (painter 1 takes 6 mins and painter 2 takes 4 mins).
// The approach is based on binary search. We can use binary search to find the maximum time to paint the boards by painters.

// The time complexity of this approach is O(n log sum) and the space complexity is O(1).
// Where n is the number of boards and sum is the sum of all the lengths of the boards in the array.

bool isTimeValid(int arr[], int n, int m, int maxAllowedTime){
    int painter=1 ;
    int time=0;

    for(int i=0; i<n; i++){
        if (arr[i]>maxAllowedTime){
            return false;
        }

        if(arr[i]+time<=maxAllowedTime){
            time+=arr[i];
        } else{
            time=arr[i];
            painter++;
        }
    }

    if (painter>m){
        return false;
    } else{
        return true;
    }
}


int paintingTime(int arr[], int n, int m){

    if(m>n){
        return -1;
    }
    int maxLen=0;
    int sum=0;
    int ans=-1;

    for (int i=0; i<n; i++){
        sum+=arr[i];
        if (arr[i]>maxLen){
            maxLen=arr[i];
        }
    }

    int st=maxLen, end=sum;

    while (st<=end){
        int mid= st + (end-st)/2;
        if(isTimeValid(arr, n, m, mid)){
            ans=mid;
            end=mid-1;
        } else{
            st=mid+1;
        }
    }
    return ans;
}

//AGGRCOW - AGGRESSIVE COWS
// (Opposite of the book allocation and painter partition problem)

// Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1 ... xN (0 <= xi <= 1,000,000,000).

// His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?

// Input
// t – the number of test cases, then t test cases follows.
// * Line 1: Two space-separated integers: N and C
// * Lines 2..N+1: Line i+1 contains an integer stall location, xi

// Output
// For each test case output one integer: the largest minimum distance.
// The time complexity of this approach is O(n log m) and the space complexity is O(1).

// for example, if the array is [1, 2, 4, 8, 9] and the number of cows is 3, then the maximum minimum distance is 3.

bool isValidPosition(vector <int> &arr, int n, int m, int minAllocatedDistance){

    int cow=1;
    int lastStallPosition=arr[0];

    for (int i=1; i<n; i++){
        if(arr[i]-lastStallPosition>=minAllocatedDistance){
            cow++;
            lastStallPosition=arr[i];
        }
        if (cow==m){
            return true;
        }
    }
    return false;
}

int aggressiveCows(vector <int> &arr, int n, int m){

    sort(arr.begin(), arr.end());
  
    if(m>n){
        return -1;
    }


    int ans=0;
    int st=0, end=arr[n-1]-arr[0];
    
    while(st<=end){
        int mid=st+(end-st)/2;

        if(isValidPosition(arr, n, m, mid)){
            ans=mid;
            st=mid+1;
        } else{
            end=mid-1;
        }
    }
    return ans;
}


int main(){

    int arr[] = {4, 5, 6, 7, 0, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 0;
    int result = search(arr, n, target);
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }

    int arr2[] = {1,3,5,7,8,9,5,2,1};
    cout << linearSearch(arr2, 9) << endl;
    cout << binarySearch(arr2, 9) << endl;

    int arr3[] = {1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,9,9};
    cout << searchSingleElement(arr3, 17) << endl; // Output: 8

    int arr4[] = {100, 200, 300, 400};
    cout << allocateBooks(arr4, 4, 2) << endl;

    int arr5[] = {1,2,3,4};
    cout << paintingTime(arr5, 4, 2) << endl;

    vector <int> arr6 = {1,2,4,8,9};
    cout << aggressiveCows(arr6, 5, 3) << endl;
    


    return 0;
}