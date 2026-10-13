// Leetcode 542. 01 Matrix



class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        // Initialize distance matrix with -1 (unvisited cells)
        vector<vector<int>> dist(n, vector<int>(m, -1));

        // Queue stores coordinates of cells to be processed
        queue<pair<int, int>> q;

        // Step 1: Add ALL zero cells to the queue as starting points
        // Their distance is already 0
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        // These arrays represent movement: up, down, left, right
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        // Step 2: Process cells level by level using BFS
        while (!q.empty()) {

            // Get the next cell from the front of the queue
            auto [r, c] = q.front();
            q.pop();

            // Explore all four neighbors of the current cell
            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k]; // Neighbor's row
                int nc = c + dc[k]; // Neighbor's column

                // Check that the neighbor is inside the matrix
                // and has not been visited yet
                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < m &&
                    dist[nr][nc] == -1) {

                    // First visit guarantees the shortest distance
                    // because BFS explores level by level
                    dist[nr][nc] = dist[r][c] + 1;

                    // Process this neighbor later
                    q.push({nr, nc});
                }
            }
        }

        // Step 3: Return the shortest distance of every cell to a zero
        return dist;
    }
};

// Multi-source BFS is a Breadth-First Search in which we start from multiple source nodes simultaneously instead of just one.

// Multi-source BFS:
// 1. Push all zero cells into the queue with distance 0.
// 2. BFS processes cells level by level in increasing distance order.
// 3. Neighbors of distance-0 cells get distance 1;
//    neighbors of distance-1 cells get distance 2, and so on.
// 4. The first time a cell is visited, its distance is the shortest
//    distance to any zero, so we never need to revisit it.