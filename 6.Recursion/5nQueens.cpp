#include <iostream>
#include <cstring> 
#include <string> 
#include <vector>
#include <algorithm> 
#include <cmath> // For mathematical functions like log10
using namespace std;

// 51. N-Queens

// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
// Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

// Function to check if placing a queen at (row, col) is safe
bool isSafe(vector<string> board, int row, int col, int n){ // O(n) check
        // Check horizontally (same row)
        // Even though in our recursive approach we place only one queen per row,
        // this loop ensures no other queen exists in the same row.
        for(int j=0; j<n; j++){ 
            if(board[row][j]=='Q') return false;
        }

        // Check vertically (same column)
        // Make sure no queen is already placed in this column.
        for(int i=0; i<n; i++){ 
            if(board[i][col]=='Q') return false;
        }

        // Check left upper diagonal (↖)
        // Move diagonally upwards left from (row, col).
        // If we find a queen, placement is not safe.
        for(int i=row, j=col; i>=0 && j>=0; i--, j--){
            if(board[i][j]=='Q') return false;
        }

        // Check right upper diagonal (↗)
        // Move diagonally upwards right from (row, col).
        // If we find a queen, placement is not safe.
        for(int i=row, j=col; i>=0 && j<n; i--, j++){
            if(board[i][j]=='Q') return false;
        }

        // If none of the above checks fail, placing a queen here is safe.
        return true;
    }


// Recursive function to place queens row by row
void PlaceQueens(int row, int n,  vector<string>& board, vector<vector<string>>& ans){
        // Base Case: If we have successfully placed queens in all rows
        if(row==n){
            // Save the current configuration of the board into ans
            ans.push_back(board);
            return;
        }

        // Try placing a queen in every column of the current row
        for(int j=0; j<n; j++){
            // Check if placing queen at (row, j) is safe
            if(isSafe(board, row, j, n)){
                board[row][j]='Q';              // Place queen
                PlaceQueens(row+1, n, board, ans); // Recur for next row
                board[row][j]='.';              // Backtrack: remove queen
            }
        }
    }


// Main function to solve N-Queens problem
vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans; // Stores all possible solutions

        // Initialize an empty chess board of size n x n filled with '.'
        // Example for n=4:
        // board = [ "....",
        //           "....",
        //           "....",
        //           "...." ]
        vector<string> board(n, string(n, '.')); 

        // Start placing queens row by row from the 0th row
        PlaceQueens(0, n, board, ans);

        // Return all valid board configurations
        return ans;
    }

int main(){
    int n = 4; // Change this value to test different board sizes
    vector<vector<string>> solutions = solveNQueens(n);
    for (const auto& solution : solutions) {
        for (const auto& row : solution) {
            cout << row << endl;
        }
        cout << "------------------" << endl;
    }
    return 0;
}