#include <iostream>
#include <cstring> 
#include <string> 
#include <vector>
#include <algorithm> 
#include <cmath> 

using namespace std;

pair<int,int> linearSearch(int mat[][4], int rows, int cols, int target) { // matrix cant be declared without specifying the number of columns, so take a random number of columns as a parameter
    
    pair <int,int> ans = {-1,-1}; // Initialize a pair to store the row and column indices of the target element
    // If the target is not found, return -1
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] == target) {
                ans.first = i; // Store the row index
                ans.second = j; // Store the column index
                return ans; // Return the pair containing the row and column indices
            }
        }
    }
    return ans; // 
}

int maxRowSum(int mat[][4], int rows, int cols){
    int maxSum=INT16_MIN;
    for (int i=0; i<rows; i++){
        int rowSum=0;
        for(int j=0; j<cols; j++){
            rowSum+=mat[i][j];
        }
        maxSum=max(rowSum,maxSum);
    }
    return maxSum;
}

int maxColSum(int mat[][4], int rows, int cols){
    int maxSum = INT16_MIN;
    for (int i=0; i<cols; i++){
        int colSum=0;
        for (int j=0; j<rows; j++){
            colSum+=mat[j][i];
        }
        
        maxSum = max(maxSum,colSum);
    }
    return maxSum;
}

// time complexity: O(n^2) where n is the number of rows or columns in the matrix
// space complexity: O(1) as we are using a constant amount of extra space
int diagonalSum(int mat2[][4], int rows, int cols){

    int dSum=0;
    for (int i=0; i<cols; i++){ 
        for (int j=0; j<rows; j++){ 
            // For a square matrix, the primary diagonal is where i == j

            // The secondary diagonal is where j == rows - 1 - i 
            // For example, in a 4x4 matrix, the main diagonal is (0,0), (1,1), (2,2), (3,3) and the secondary diagonal is (0,3), (1,2), (2,1), (3,0)
            
            if(i==j){
                dSum+=mat2[i][j];
            } else if (j==rows-1-i){
                dSum+=mat2[i][j];
            }
        }
        
    }
    return dSum;

}


// time complexity: O(n) where n is the number of rows or columns in the matrix
// space complexity: O(1) as we are using a constant amount of extra space
int diagonalSum2(int mat2[][4], int rows, int cols){

    int dSum=0;
    for (int i=0; i<rows; i++){ 

        dSum += mat2[i][i]; // Primary diagonal

        if (i!= rows - 1 - i){  // Check to avoid double counting the center element in odd-sized matrices
            dSum += mat2[i][rows - 1 - i]; // Secondary diagonal
        }
        
    }
    return dSum;

}


// Leetcode 74: Search a 2D Matrix

// You are given an m x n integer matrix matrix with the following two properties:

// Each row is sorted in non-decreasing order.
// The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true if target is in matrix or false otherwise.

// You must write a solution in O(log(m * n)) time complexity.

bool searchMatrix(vector<vector<int>>& matrix, int target) {

    int m = matrix.size();
    int n = matrix[0].size();

    int stR = 0;
    int endR = m-1;

    while (stR <= endR){ //O(log(m))

        int midR = stR + (endR-stR)/2;

        if (matrix[midR][0] <= target && target <= matrix[midR][n-1]){ // Check if target is in the range of the current row

            int stC = 0;
            int endC = n-1;

            while (stC <= endC){  // O(log(n))   // Binary search in the current row

                int midC = stC + (endC-stC)/2; 

                if (matrix[midR][midC]==target){

                    return true;

                } else if (target < matrix[midR][midC]){ // If target is less than the middle element, search in the left half

                    endC = midC-1;  // search in the left half

                } else {   // target > matrix[midR][midC]

                    stC = midC+1;  // search in the right half

                }
            }
            return false;

        } else if (matrix[midR][0] > target){ // If target is less than the first element of the current row

            endR = midR - 1;   //  search in the upper rows

        } else {     // If target is greater than the last element of the current row

            stR = midR + 1; // search in the lower rows

        }
    }

    return false; 
}
// Overall time complexity: O(log(m) + log(n)) => O(log(m*n)) where m is the number of rows and n is the number of columns in the matrix
// Overall space complexity: O(1) as we are using a constant amount of extra space





// Leetcode 240: Search a 2D Matrix II

// Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

// Integers in each row are sorted in ascending from left to right.
// Integers in each column are sorted in ascending from top to bottom.

// In this problem, we can use a more efficient approach by starting from the top-right / bottom-left corner of the matrix 
// and moving either left or down based on the comparison with the target value.
// This approach works because the matrix is sorted in both rows and columns, allowing us to eliminate full rows or columns with each comparison.
// This approach works because of the sorted properties of the matrix. 


// We can start from the top-right or bottom-left corner of the matrix as then we will only have to check two directions: left and down (or up and right).
// If the current element is equal to the target, we return true.
// If the current element is less than the target, we move down to the next row (as all elements in the current row are smaller).
// If the current element is greater than the target, we move left to the previous column (as all elements in the current column are larger).
// We continue this process until we either find the target or exhaust the matrix bounds.

bool searchMatrix(vector<vector<int>>& matrix, int target) {

    int m = matrix.size(), n = matrix[0].size();

    int r=0, c=n-1;
    

    while (r<m && c>=0){ 
        int midEle = matrix[r][c];

        if (midEle == target){
            return true;
            break;
        } else if (midEle < target){
            r++;
        } else{
            c--;
        }
    }
    
    return false;
}
// In the worst case, we will traverse from row 0 to row m-1 and from column n-1 to column 0, which gives us a time complexity of O(m+n).
// This is more efficient than a brute force approach of checking each element, which would have a time complexity of O(m*n).
// This approach is also known as the "STAIRCASE SEARCH" or "ZIGZAG SEARCH" algorithm.
// Overall time complexity: O(m+n) where m is the number of rows and n is the number of columns in the matrix
// Overall space complexity: O(1) as we are using a constant amount of extra space



// Leetcode 54: Spiral Matrix
// Given an m x n matrix, return all elements of the matrix in spiral order.
vector<int> spiralOrder(vector<vector<int>>& mat) {

    vector<int> ans;
    int m=mat.size(), n=mat[0].size();

    int srow=0, erow=m-1, scol=0, ecol=n-1; // Initialize the starting and ending row and column indices

    while(srow<=erow && scol<=ecol){ // Continue until the starting row index is less than or equal to the ending row index and the starting column index is less than or equal to the ending column index
    // The number of iterations depend on the smallest dimension of the matrix, i.e., the minimum of m and n.

        //top
        for(int j=scol; j<=ecol; j++){ // Traverse the top row from left to right
            ans.push_back(mat[srow][j]);
        }

        //right
        for(int i=srow+1; i<=erow; i++){ // Traverse the right column from top to bottom leaving the element already added in the top row
            ans.push_back(mat[i][ecol]);
        }

        //bottom
        for(int j=ecol-1; j>=scol; j--){ // Traverse the bottom row from right to left leaving the element already added in the right column

            // Check if we are still in the same row to avoid adding the same row again
            // This is important when the matrix has only one row or one column left (In odd-sized matrices)
            if(srow==erow){
                break;
            }

            ans.push_back(mat[erow][j]);
        }

        //left
        for(int i=erow-1; i>=srow+1; i--){ // Traverse the left column from bottom to top leaving the element already added in the bottom row and the top row
            
            if(scol==ecol){
                break;
            }

            ans.push_back(mat[i][scol]);
        }

        // Move the boundaries inward for the next spiral layer
        srow++;
        erow--;
        scol++;
        ecol--;

    }

    return ans;
}

// As we are visiting each element of the matrix exactly once.
// Overall space complexity: O(m*n) [m*n = number of elements] for storing the result in a vector, where m is the number of rows and n is the number of columns in the matrix. 


int main(){

    cout << "OM NMMAHA SHIVAY" << endl;

    // 2D ARRAYS (MATRICES)

    // A 2D array is an array of arrays, where each element is itself an array.
    // It can be visualized as a table with rows and columns.
    // In C++, a 2D array can be declared as follows:

    int mat[3][4] = { // 3 rows and 4 columns
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    // Accessing elements in a 2D array:
    cout << "Element at row 1, column 2: " << mat[1][2] << endl; // Output: 7

    int mat2[4][4] = { // 4 rows and 4 columns [SQUARE MATRIX]
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {11, 12, 13, 14}
    };

    // Modifying elements in a 2D array:
    mat[0][0] = 10; // Changing the first element to 10

    // Declaring a 2D array:
    int mat3[2][3];

    // Iterating through a 2D array:
    for (int i = 0; i < 3; i++) { // Loop through rows
        for (int j = 0; j < 4; j++) { // Loop through columns
            cout << mat[i][j] << " "; // Print each element
        }
        cout << endl; // New line after each row
    }

    // Searching for an element in a 2D array:
    int target = 7;
    pair<int, int> result = linearSearch(mat, 3, 4, target);
    if (result.first != -1) {
        cout << "Element " << target << " found at row " << result.first << ", column " << result.second << endl;
    } else {
        cout << "Element " << target << " not found in the matrix." << endl;
    }


    // MEMORY ALLOCATION FOR 2D ARRAYS:
    
    // There are two ways to allocate memory for 2D arrays in C++:

    // 1. Using a row major order (array of arrays)
    // This is the most common way to declare a 2D array in C++.
    // In this method, all the rows are stored in contiguous memory locations.
    // Example:
    // mat is stored as a contiguous block of memory, where the first row is followed by the second row, and so on.
    // 10, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12
    // All the elements of the first row are stored in memory, followed by all the elements of the second row, and so on.

    // 2. Using a column major order (array of pointers)
    // In this method, all the columns are stored in contiguous memory locations.
    // Example:
    // mat is stored as a contiguous block of memory, where the first column is followed by the second column, and so on.
    // 10, 5, 9, 2, 6, 10, 3, 7, 11, 4, 8, 12
    // This method is less common in C++ but can be useful in certain scenarios.

    // One of the two methods is chosen based on the requirements of the program.


    // MAX ROW SUM
    cout << "Max row sum of Matrix : " << maxRowSum(mat,3,4) << endl;

    // MAX COLUMN SUM
    cout << "Max column sum of Matrix : " << maxColSum(mat,3,4) << endl;

    // DIAGONAL SUM
    cout << "Diagonal sum of Matrix : " << diagonalSum(mat2,4,4) << endl;
    cout << "Diagonal sum of Matrix : " << diagonalSum2(mat2,4,4) << endl;


    // 2D VECTORS

    // A 2D vector is a vector of vectors, where each element is itself a vector.
    // It can be visualized as a table with rows and columns, similar to a 2D array.
    // In C++, a 2D vector can be declared as follows:
    vector <vector<int>> vec2D = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // As vectors are dynamic in nature, we can add or remove elements from a 2D vector at runtime.
    vec2D.push_back({10, 11, 12}); // Adding a new row to the 2D vector
    vec2D[0].push_back(4); // Adding a new column to the first row of the 2D vector

    // Accessing elements in a 2D vector:
    cout << "Element at row 1, column 2: " << vec2D[1][2] << endl; // Output: 6

    // Printing a 2D vector:
    for (int i = 0; i < vec2D.size(); i++) {
        for (int j = 0; j < vec2D[i].size(); j++) {
            cout << vec2D[i][j] << " "; // Print each element
        }
        cout << endl; // New line after each row
    }

    // Checking no. of rows and columns in a 2D vector:
    cout << "Number of rows in vec2D: " << vec2D.size() << endl; // Output: 4
    cout << "Number of columns in vec2D: " << vec2D[0].size() << endl; // Number of columns in the first row, Output: 4

    


    return 0;
}