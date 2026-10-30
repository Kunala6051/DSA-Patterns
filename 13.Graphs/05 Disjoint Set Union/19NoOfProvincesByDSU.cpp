#include <bits/stdc++.h>
using namespace std;

/*
Problem:
Given an n x n adjacency matrix where grid[i][j] = 1 indicates that city i
is directly connected to city j, find the number of provinces. A province is
a group of directly or indirectly connected cities.

Approach (Disjoint Set Union - Union by Rank + Path Compression):
1. Initially, consider every city as a separate set.
2. Traverse only the upper triangular part of the adjacency matrix
   (j = i + 1) since the graph is undirected and the matrix is symmetric.
3. Whenever two cities are directly connected, merge their sets using
   Union by Rank.
4. After all unions, every province is represented by a unique root node.
5. Count how many nodes are their own parent (root). This gives the
   total number of provinces.

Time Complexity: O(n² × α(n)) ≈ O(n²)
Space Complexity: O(n)
*/

class Solution{
    int V;
    vector<int> parent, rank;

public:

    // Finds the ultimate parent of a node using Path Compression
    int find(int x){
        if(parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    // Merges two sets using Union by Rank
    void unionByRank(int a, int b){
        int parA = find(a);
        int parB = find(b);

        // Already in the same set
        if(parA == parB)
            return;

        // Attach smaller rank tree under larger rank tree
        if(rank[parA] == rank[parB]){
            parent[parB] = parA;
            rank[parA]++;
        }
        else if(rank[parA] > rank[parB]){
            parent[parB] = parA;
        }
        else{
            parent[parA] = parB;
        }
    }

    int findCircleNum(vector<vector<int>>& grid){
        int n = grid.size();

        V = n;

        // Initially every node is its own parent
        for(int i=0; i<V; i++){
            parent.push_back(i);
            rank.push_back(0);
        }

        // Traverse only the upper triangular matrix
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(grid[i][j] == 1)
                    unionByRank(i, j);
            }
        }

        int count = 0;

        // Count the number of unique parents (provinces)
        for(int i=0; i<n; i++){
            if(find(i) == i)
                count++;
        }

        return count;
    }
};

int main(){
    Solution obj;

    vector<vector<int>> grid = {
        {1,1,0},
        {1,1,0},
        {0,0,1}
    };

    cout << "Number of Provinces: " << obj.findCircleNum(grid);

    return 0;
}