#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Time Complexity: No. of recursive calls * work done in each call

// Acc to recursive graph every recursive calls the function itself two times
// Like the first time it calls fibonacci(n-1) and fibonacci(n-2) (2)
// Then these two calls further calls 4 function calls
// This pattern continues, 2^0, 2^1, 2^2, ..., 2^(n-1)

// Total number of recursive calls: 2^0 + 2^1 + 2^2 + ... + 2^(n-1)
// This is a geometric series with a sum of 2^n - 1 (calculate using formula)

// Work done in each call is O(1)

// Total Time Complexity: O(2^n) * O(1) = O(2^n)  [estimated]
// Actual time complexity of fibonacci series is O(1.618^n) - Binet's formula

// Space Complexity: O(n) - Due to recursion stack


bool isSorted(int arr[], int n) {
    if (n == 1) return true;
    return (arr[n - 1] >= arr[n - 2]) && isSorted(arr, n - 1);
}
// Time Complexity:
// Total recursive calls: n
// Work done in each call: O(1)
// Total Time Complexity: O(n) * O(1) = O(n)


// Space Complexity: O(n) - Due to recursion stack

int binaryHelper(int arr[], int target, int low, int high) {
    if (low > high) return -1; // Base case: target not found

    int mid = low + (high - low) / 2; // Avoid overflow

    if (arr[mid] == target) {
        return mid; // Target found
    } else if (arr[mid] > target) {
        return binaryHelper(arr, target, low, mid - 1); // Search in left half
    } else {
        return binaryHelper(arr, target, mid + 1, high); // Search in right half
    }
}

int binarySearch(int arr[], int tar){
    return binaryHelper(arr, tar, 0, sizeof(arr)/sizeof(arr[0])-1);
}

// Time Complexity: O(log n)
// Space Complexity: O(log n) - Due to recursion stack

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;
    cout << "Fibonacci sequence: ";
    for (int i = 0; i < n; i++) {
        cout << fibonacci(i) << " ";
    }
    cout << endl;

    // Using iterative approach
    cout << "Fibonacci sequence (iterative): ";
    int a = 0, b = 1;
    for (int i = 0; i < n; i++) {
        cout << a << " ";
        int next = a + b;
        a = b;
        b = next;
    }
    cout << endl;

    // Check if the array is sorted
    int arr[] = {1, 2, 7, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    if (isSorted(arr, size)) {
        cout << "Array is sorted." << endl;
    } else {
        cout << "Array is not sorted." << endl;
    }

    // binary search
    int arr2[] = {3,5,6,8,9,56,90,99};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int target;
    cout << "Enter target element for binary search: ";
    cin >> target;
    cout << binarySearch(arr2, target, 0, size2-1);

    return 0;
}
