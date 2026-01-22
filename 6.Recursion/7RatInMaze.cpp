#include <iostream>
#include <cstring> 
#include <string> 
#include <vector>
#include <algorithm> 
#include <cmath> // For mathematical functions like log10

using namespace std;

// This problem is the classic “Rat in a Maze” / Pathfinding with Backtracking problem.

// 📝 Brief of the Question:
// You are given a matrix (grid) where:
// 1 → open cell (rat can move here)
// 0 → blocked cell (rat cannot move here)

// The rat starts at the top-left corner (0,0).
// The goal is to reach the bottom-right corner (n-1, m-1).
// From each cell, the rat can move in four directions:
// D (Down), U (Up), R (Right), L (Left).

// You need to find all possible paths from start to destination, 
// and return them as a list of strings (each string is a sequence of moves like "DRURR").

// ============================
// Helper function for backtracking
// ============================
//
// mat   -> The grid/maze represented as a 2D matrix
// r, c  -> Current row and column position of the rat
// path  -> String that keeps track of the path taken so far
// ans   -> Vector of strings that stores all successful paths from (0,0) to (n-1,m-1)
//
void helper(vector<vector<int>> &mat, int r, int c, string path, vector<string> &ans) {
    int n = mat.size();     // number of rows
    int m = mat[0].size();  // number of columns

    // ============================
    // Base case 1: Invalid position
    // ============================
    // Conditions where the current move is invalid:
    // 1. Out of bounds (r or c < 0 OR r >= n OR c >= m)
    // 2. Cell is blocked (mat[r][c] == 0)
    // 3. Cell already visited in the current path (mat[r][c] == -1, used as a marker)
    if (r < 0 || c < 0 || r >= n || c >= m || mat[r][c] == 0 || mat[r][c] == -1) {
        return; // stop exploring this path
    }

    // ============================
    // Base case 2: Destination reached
    // ============================
    // If we reached the bottom-right cell (n-1, m-1),
    // that means we found a valid path. Store it in ans.
    if (r == n - 1 && c == m - 1) {
        ans.push_back(path);
        return; // backtrack
    }

    // ============================
    // Mark the current cell as visited
    // ============================
    // Use -1 to mark this cell so that we don’t revisit it
    // during the current recursive exploration
    mat[r][c] = -1;

    // ============================
    // Explore all 4 possible directions
    // ============================
    // "D" -> Down (row+1)
    helper(mat, r + 1, c, path + "D", ans);

    // "U" -> Up (row-1)
    helper(mat, r - 1, c, path + "U", ans);

    // "R" -> Right (col+1)
    helper(mat, r, c + 1, path + "R", ans);

    // "L" -> Left (col-1)
    helper(mat, r, c - 1, path + "L", ans);

    // ============================
    // Backtrack step
    // ============================
    // Reset the cell back to 1 (open) after exploring all paths from here
    // so that it can be used in other recursive paths
    mat[r][c] = 1;
}



// ============================
// Main function
// ============================
// This function initializes the search and returns
// all possible paths from (0,0) to (n-1,m-1).
//
vector<string> findPath(vector<vector<int>> &mat) {
    vector<string> ans;  // to store all possible paths
    string path = "";    // initially no path taken

    // Start exploring from the top-left corner (0,0)
    helper(mat, 0, 0, path, ans);

    return ans;
}

// Time Complexity: O(4^(n*m)), where n is the number of rows and m is the number of columns.
// Space Complexity: O(n*m) for the recursion stack.


// IMPORTANT: 
// The BRUTE FORCE APPROACH is to make a bool visited mat[n][m] array to keep track of visited cells.
// That would have added O(n*m) space complexity for the visited array.


int main(){
    vector<vector<int>> mat = {{1,0,0,0}, {1,1,0,1}, {1,1,0,0}, {0,1,1,1}};
    vector<string> ans = findPath(mat); 

    for(auto path: ans){
        cout<<path<<endl;
    }

    return 0;
}