#include <iostream>
#include <vector>
using namespace std;

/*
APPROACH (Number of Islands using DFS)

Problem Idea
-------------
We are given a 2D grid where:
'1' represents land
'0' represents water

An island is a group of connected '1's. Connectivity is allowed in
4 directions only:
    • up
    • down
    • left
    • right

Goal:
Count how many separate islands exist in the grid.

Core Idea
----------
We traverse the grid cell by cell. Whenever we encounter a cell that:
    grid[i][j] == '1' (land)
    AND
    it has not been visited before,

it means we have discovered a **new island**.

At this moment we perform a **DFS (Depth First Search)** from this cell.

Why DFS?
---------
DFS allows us to explore all connected land cells belonging to the same island.

Once we find one land cell of an island, DFS will mark all its connected
land cells as visited so they are not counted again.

Steps
------

1. Traverse the entire grid using two loops (i, j).

2. When we find an unvisited land cell:
        grid[i][j] == '1'
        vis[i][j] == false

3. This indicates the **start of a new island**, so:
        increment island count

4. Call DFS from this cell to explore the entire island.

5. DFS explores in four directions:
        top    -> (i-1, j)
        right  -> (i, j+1)
        bottom -> (i+1, j)
        left   -> (i, j-1)

6. During DFS:
        - Stop if we go outside the grid
        - Stop if the cell is already visited
        - Stop if the cell is water ('0')

7. Mark every valid land cell as visited.

8. Continue scanning the grid.

9. Finally return the number of islands.

Time Complexity
---------------
O(n × m)

Every cell is visited at most once.

Space Complexity
----------------
O(n × m) for the visited array
+
O(n × m) recursion stack in worst case.
*/

void dfs(int i, int j, vector<vector<bool>>& vis, vector<vector<char>>& grid, int n, int m){

    // Base condition:
    // Stop DFS if:
    // 1. Out of grid boundary
    // 2. Cell already visited
    // 3. Cell is water ('0')
    if(i<0 || j<0 || i>=n || j>=m || vis[i][j] || grid[i][j]!='1') return;

    // Mark the current land cell as visited
    vis[i][j] = true;

    // Explore the cell above
    dfs(i-1, j, vis, grid, n, m);

    // Explore the cell to the right
    dfs(i, j+1, vis, grid, n, m);

    // Explore the cell below
    dfs(i+1, j, vis, grid, n, m);

    // Explore the cell to the left
    dfs(i, j-1, vis, grid, n, m);
}

int numIslands(vector<vector<char>>& grid) {

    int c = 0; // Counter to store number of islands

    int n = grid.size();     // Number of rows
    int m = grid[0].size();  // Number of columns

    // Visited matrix to track explored cells
    vector<vector<bool>> vis(n, vector<bool>(m, false));

    // Traverse the entire grid
    for(int i = 0; i < n; i++){

        for(int j = 0; j < m; j++){

            // If we find an unvisited land cell
            if(grid[i][j] == '1' && !vis[i][j]){

                // Explore the entire island using DFS
                dfs(i, j, vis, grid, n, m);

                // Increase island count
                c++;
            }
        }
    }

    // Return total islands found
    return c;
}

int main(){

    // Example grid
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    int islands = numIslands(grid); // compute number of islands

    cout << "Number of Islands: " << islands << endl;

    return 0;
}