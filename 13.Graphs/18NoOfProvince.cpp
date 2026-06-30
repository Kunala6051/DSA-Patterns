#include <bits/stdc++.h>
using namespace std;

// LeetCode 547 - Number of Provinces

#include <bits/stdc++.h>
using namespace std;

/*
Problem:
Given an adjacency matrix where grid[i][j] = 1 indicates city i is directly connected
to city j, find the total number of provinces (connected components).

Approach:
- Traverse every city.
- If a city has not been visited, start a DFS from it.
- DFS visits all cities belonging to the same province.
- Increment the province count after each DFS call.

Time Complexity: O(n^2)
- Every cell of the adjacency matrix is checked once.

Space Complexity: O(n)
- Visited array + recursion stack.
*/

void dfs(int i, vector<bool>& vis, vector<vector<int>>& grid){
    vis[i] = true; // Mark current city as visited

    // Visit all directly connected cities
    for(int j=0; j<grid[i].size(); j++){
        if(grid[i][j]==1 && !vis[j]){
            dfs(j, vis, grid);
        }
    }
}

int findCircleNum(vector<vector<int>>& grid){
    int c = 0; // Number of provinces

    int n = grid.size();
    int m = grid[0].size();

    vector<bool> vis(n, false);

    // Traverse every city
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            // If city is unvisited, start DFS for a new province
            if(grid[i][j]==1 && !vis[i]){
                dfs(i, vis, grid);
                c++;
            }
        }
    }

    return c;
}

int main(){
    vector<vector<int>> grid = {
        {1,1,0},
        {1,1,0},
        {0,0,1}
    };
    int provinces = findCircleNum(grid);
    cout << "Number of Provinces: " << provinces << endl;
    return 0;
}