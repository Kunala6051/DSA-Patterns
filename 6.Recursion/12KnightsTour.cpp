#include <iostream>
#include <cstring> 
#include <string> 
#include <vector>
#include <algorithm> 
#include <set>
#include <cmath> // For mathematical functions like log10

using namespace std;

// Helper function to check if knight's tour is valid starting from (r, c)
// with the current expected move value = expVal.
bool isValid(vector<vector<int>>& grid, int r, int c, int expVal){
    int n = grid.size();

    // 1. Base case: check if (r, c) is outside the board
    // or does not have the expected value.
    if (r < 0 || c < 0 || r >= n || c >= n || grid[r][c] != expVal) {
        return false;
    }

    // 2. If we have placed all numbers correctly till n*n - 1,
    // it means the knight’s tour is valid.
    if (expVal == (n * n - 1)) return true;

    // 3. Try all 8 possible knight moves from current cell.
    // Each recursive call expects the next number (expVal+1).
    int ans1 = isValid(grid, r - 2, c + 1, expVal + 1); // move up 2, right 1
    int ans2 = isValid(grid, r - 2, c - 1, expVal + 1); // move up 2, left 1
    int ans3 = isValid(grid, r + 1, c - 2, expVal + 1); // move down 1, left 2
    int ans4 = isValid(grid, r - 1, c - 2, expVal + 1); // move up 1, left 2
    int ans5 = isValid(grid, r - 1, c + 2, expVal + 1); // move up 1, right 2
    int ans6 = isValid(grid, r + 1, c + 2, expVal + 1); // move down 1, right 2
    int ans7 = isValid(grid, r + 2, c + 1, expVal + 1); // move down 2, right 1
    int ans8 = isValid(grid, r + 2, c - 1, expVal + 1); // move down 2, left 1

    // 4. If any of the knight moves returns true,
    // the path is valid → return true.
    return (ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8);
}

// Space Complexity: O(n^2) for the recursion stack in the worst case  [No extra space is used]

// Time Complexity: It could be O(8^(n*n)) in the worst case, where n is the grid size.
// This is because from each cell, we can make 8 possible moves, leading to an exponential number of paths to explore.

// BUT, as we are already checking for the expected value at each cell,
// there would be only one valid path to explore in a correct knight's tour,
// which drastically reduces the actual time taken in practice.

// So, the practical time complexity is much lower than the theoretical worst case,
// especially for valid knight's tours, making it feasible for reasonable grid sizes.
// it is closer to O(n^2) for a valid knight's tour.



// Main function: starts recursion from top-left corner (0,0)
// with expected starting value = 0.
bool checkValidGrid(vector<vector<int>>& grid) {
    return isValid(grid, 0, 0, 0);
}

int main() {
    vector<vector<int>> grid = {
        {0, 3, 6},
        {5, 8, 1},
        {2, 7, 4}
    };

    if (checkValidGrid(grid)) {
        cout << "The knight's tour is valid." << endl;
    } else {
        cout << "The knight's tour is not valid." << endl;
    }

    return 0;
}