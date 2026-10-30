#include <bits/stdc++.h>
using namespace std;

// Leetcode: 994. Rotting Oranges

/*
APPROACH (Multi-Source BFS)

This problem is solved using Breadth First Search (BFS).

Key Idea:
Instead of starting BFS from one node, we start BFS from ALL rotten oranges at the same time.
This is called Multi-Source BFS.

Steps:

1. Traverse the grid and push all initially rotten oranges (value = 2)
   into the queue with time = 0 because they are already rotten.

2. Maintain a visited matrix to ensure we do not process the same orange again.

3. Perform BFS:
   - Pop an element from the queue.
   - From that cell, try to rot its 4 neighbors:
        up, down, left, right
   - If a neighbor is a fresh orange (value = 1) and not visited,
     mark it visited and push it into the queue with time + 1.

4. Track the maximum time taken to rot oranges while processing BFS.

5. After BFS finishes, check if any fresh orange (value = 1) is still unvisited.
   - If yes → return -1 (some oranges cannot rot).
   - Otherwise → return the maximum time stored.

Time Complexity:  O(N * M)
Space Complexity: O(N * M)
*/

int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();            // number of rows
        int m = grid[0].size();         // number of columns
        int ans = 0;                    // stores maximum time required

        // visited matrix to track which oranges have already been processed
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        
        // queue stores: {{row, col}, time}
        queue<pair<pair<int,int>,int>> q;

        // Step 1: Push all initially rotten oranges into the queue
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2){          // if orange is already rotten
                    vis[i][j]=true;         // mark it visited
                    q.push({{i,j},0});      // push with time = 0
                }
            }
        }

        // Step 2: Perform BFS
        while(!q.empty()){

            // extract row index
            int i = q.front().first.first;

            // extract column index
            int j = q.front().first.second;

            // extract time when this orange became rotten
            int t = q.front().second;

            q.pop();                       // remove from queue

            ans = max(ans,t);              // update maximum time

            // check DOWN direction
            if(i+1<n && !vis[i+1][j] && grid[i+1][j]==1){
                vis[i+1][j]=true;          // mark as visited
                q.push({{i+1, j}, t+1});   // push with increased time
            }

            // check RIGHT direction
            if(j+1<m && !vis[i][j+1] && grid[i][j+1]==1){
                vis[i][j+1]=true;
                q.push({{i, j+1}, t+1});
            }

            // check LEFT direction
            if(j-1>=0 && !vis[i][j-1] && grid[i][j-1]==1){
                vis[i][j-1]=true;
                q.push({{i, j-1}, t+1});
            }

            // check UP direction
            if(i-1>=0 && !vis[i-1][j] && grid[i-1][j]==1){
                vis[i-1][j]=true;
                q.push({{i-1, j}, t+1});
            }
        }

        // Step 3: Check if any fresh orange remains
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j]==1){ 
                    return -1;             // fresh orange that never rotted
                }
            }
        }

        // return total time taken
        return ans;
}

int main(){

    // Example grid
    vector<vector<int>> grid = {
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };

    cout << orangesRotting(grid) << endl; // Output: 4

    return 0;
}