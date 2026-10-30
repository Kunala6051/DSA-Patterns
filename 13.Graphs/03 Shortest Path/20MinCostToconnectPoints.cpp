#include <bits/stdc++.h>
using namespace std;


// Leetcode Problem: 1584. Min Cost to Connect All Points

/*
Approach:
- This problem is solved using Prim's Algorithm to find the Minimum Spanning Tree (MST).
- Treat every point as a node in a complete graph, where the edge weight
  between two points is their Manhattan distance.
- Start from any point (here, point 0) with cost 0.
- Use a min-heap to always pick the edge with the smallest cost that connects
  a new point to the existing MST.
- If the selected point is already included in the MST, skip it.
- Otherwise, add its cost to the answer, mark it as visited, and push the
  distances from this point to all remaining unvisited points into the heap.
- Continue until all points are included.
- The accumulated cost is the minimum cost required to connect all points.

Time Complexity: O(n² log n)
Space Complexity: O(n²) (priority queue can contain O(n²) edges)
*/

class Solution {
public:
    // Returns Manhattan distance between two points
    int dist(int x1, int y1, int x2, int y2){
        return abs(x2 - x1) + abs(y2 - y1);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        // Tracks whether a point is already in MST
        vector<bool> inMST(n, false);

        // {cost, node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, 0});

        int totalCost = 0;

        while(!pq.empty()){
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            // Skip if already included
            if(inMST[u]) continue;

            // Include current node
            inMST[u] = true;
            totalCost += d;

            // Add all possible edges from current node
            for(int i = 0; i < n; i++){
                if(!inMST[i] && i != u){
                    int dis = dist(points[i][0], points[i][1],
                                   points[u][0], points[u][1]);
                    pq.push({dis, i});
                }
            }
        }

        return totalCost;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> points = {
        {0, 0},
        {2, 2},
        {3, 10},
        {5, 2},
        {7, 0}
    };

    cout << obj.minCostConnectPoints(points) << endl;   // Output: 20

    return 0;
}