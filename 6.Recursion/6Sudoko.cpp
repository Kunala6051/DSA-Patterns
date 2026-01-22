#include <iostream>
#include <cstring> 
#include <string> 
#include <vector>
#include <algorithm> 
#include <cmath> // For mathematical functions like log10
using namespace std;


// Function to check if placing digit 'd' at board[row][col] is valid
bool isSafe(vector<vector<char>>& board, char d, int row, int col) {
    // 1. Check the entire column for the digit
    for (int i = 0; i < 9; i++) {
        if (board[i][col] == d) return false;
    }

    // 2. Check the entire row for the digit
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == d) return false;
    }

    // 3. Check the 3x3 subgrid that (row, col) belongs to
    int sr = (row / 3) * 3;  // starting row of the subgrid
    int sc = (col / 3) * 3;  // starting col of the subgrid

    for (int i = sr; i < sr + 3; i++) {
        for (int j = sc; j < sc + 3; j++) {
            if (board[i][j] == d) return false;
        }
    }

    // If no conflict → it's safe to place the digit
    return true;
}

// Recursive helper function (backtracking) to solve Sudoku
bool helper(vector<vector<char>>& board, int row, int col) {
    // Base case: if we've reached row 9 → board is solved
    if (row == 9) return true;

    // Calculate next cell (move left to right, then down a row)
    int nextRow = row;
    int nextCol = col + 1;
    if (nextCol == 9) {       // if end of row reached
        nextRow = row + 1;    // move to next row
        nextCol = 0;          // reset column to 0
    }

    // If cell is already filled, skip to next cell
    if (board[row][col] != '.') 
        return helper(board, nextRow, nextCol);

    // Try placing digits 1–9 in the empty cell
    // We are starting to fill the numbers row by row
    for (char d = '1'; d <= '9'; d++) {
        if (isSafe(board, d, row, col)) {
            // Place the digit tentatively
            board[row][col] = d;

            // Recursively try solving for the next cell
            if (helper(board, nextRow, nextCol))  return true;
            // This means that I’ve placed a digit here. Now, can you solve the rest of the Sudoku starting from the next cell?
            // If it works, great! If not, we need to backtrack.

            // Backtrack: undo the placement
            board[row][col] = '.';
        }
    }

    // If no digit works, return false → triggers backtracking
    return false;
}

// Main function to solve Sudoku board
void solveSudoku(vector<vector<char>>& board) {
    helper(board, 0, 0); // start from top-left cell
}


int main(){
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    solveSudoku(board);

    // Print the solved Sudoku board
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}
