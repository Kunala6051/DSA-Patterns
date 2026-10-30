/*
APPROACH: DIJKSTRA'S ALGORITHM WITH A MIN-PRIORITY QUEUE

// Leetcode 1631: Path With Minimum Effort

1. Treat each cell in the grid as a node. Each cell can move to
   its four adjacent neighbors: up, down, left, and right.

2. The cost of moving between two adjacent cells is the absolute
   difference between their heights.

3. Unlike normal Dijkstra, where we add edge weights, here the
   effort of a path is the MAXIMUM edge weight encountered along it.

4. Maintain a dist matrix:
   - dist[i][j] = minimum effort required to reach cell (i, j).
   - Initialize every cell to INT_MAX, except dist[0][0] = 0.

5. Use a min-priority queue storing {effort, {row, col}} so that
   the cell with the smallest current effort is processed first.

6. For each neighboring cell:
   - Calculate the height difference between the current cell
     and the neighbor.
   - Calculate the new path effort using:
         newEffort = max(currentEffort, heightDifference)
   - If newEffort is smaller than the neighbor's recorded effort,
     update dist and push the neighbor into the priority queue.

7. Skip outdated priority queue entries if their effort is greater
   than the best effort currently stored in dist.

8. Return dist[n-1][m-1], the minimum effort to reach the
   bottom-right cell from the top-left cell.

TIME COMPLEXITY: O(N * M * log(N * M))
SPACE COMPLEXITY: O(N * M)
*/

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        // dist[i][j] stores the minimum effort needed to reach cell (i, j).
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        // Starting cell requires zero effort.
        dist[0][0] = 0;

        // Min-heap: {effort, {row, col}}.
        // The cell with the smallest effort is processed first.
        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > q;

        // Direction arrays for right, left, up, and down.
        int dr[] = {0, 0, -1, 1};
        int dc[] = {1, -1, 0, 0};

        // Start from the top-left cell with effort 0.
        q.push({0, {0, 0}});

        while (!q.empty()) {
            // Get the cell with the smallest effort.
            int d = q.top().first;
            int i = q.top().second.first;
            int j = q.top().second.second;
            q.pop();

            // Skip this entry if a better effort was already found.
            if (d > dist[i][j]) continue;

            // Explore all four neighboring cells.
            for (int k = 0; k < 4; k++) {
                int ni = i + dr[k];
                int nj = j + dc[k];

                // Check that the neighbor is inside the grid.
                if (ni >= 0 && nj >= 0 && ni < n && nj < m) {

                    // Effort required for the edge between these cells.
                    int nd = abs(heights[i][j] - heights[ni][nj]);

                    // Path effort is the maximum edge difference so far.
                    int ne = max(d, nd);

                    // Update only if this path gives a smaller effort.
                    if (dist[ni][nj] > ne) {
                        dist[ni][nj] = ne;

                        // Process this neighbor using its improved effort.
                        q.push({ne, {ni, nj}});
                    }
                }
            }
        }

        // Return the minimum effort to reach the bottom-right cell.
        return dist[n - 1][m - 1];
    }
};