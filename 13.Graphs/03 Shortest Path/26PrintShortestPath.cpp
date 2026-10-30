
/*
PROBLEM:
Given a weighted, undirected graph with n vertices and m edges,
find the shortest path from vertex 1 to vertex n.

INPUT:
edges[i] = {u, v, weight}, representing an edge between u and v.

OUTPUT:
Return a vector where:
- First element = total weight of the shortest path.
- Remaining elements = vertices along the shortest path.
- If no path exists, return {-1}.

APPROACH: DIJKSTRA'S ALGORITHM + PATH RECONSTRUCTION

1. Build an adjacency list:
   Store each edge in both directions because the graph is undirected.
   Each entry contains {neighbour, edge weight}.

2. Initialize distances:
   Set dist[1] = 0 because vertex 1 is the source.
   Set all other distances to INT_MAX because they are initially unknown.

3. Initialize the parent array:
   Initially, each vertex is its own parent.
   Whenever a shorter path to a vertex is found, store the previous
   vertex in parent[]. This will help us reconstruct the path later.

4. Run Dijkstra using a min-priority queue:
   The queue stores {distance, vertex} and processes the smallest
   distance first.
   For every neighbour, check whether travelling through the current
   vertex gives a shorter distance.
   If it does, update dist[], update parent[], and push the new
   distance into the queue.

5. Check whether the destination is reachable:
   If dist[n] is still INT_MAX, return {-1}.

6. Reconstruct the shortest path:
   Start from vertex n and follow parent[] backwards until reaching
   vertex 1. Store the visited vertices in ans[].
   The path is collected backwards, so reverse only the path portion.

7. Prepare the final answer:
   Replace ans[0] with dist[n], so the first element is the total
   shortest distance, followed by the vertices in the correct order.

TIME COMPLEXITY: O((V + E) log V)
SPACE COMPLEXITY: O(V + E)

NOTE:
Dijkstra's algorithm requires non-negative edge weights.
*/

class Solution {
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {

        // 1. Build adjacency list: adj[u] stores {neighbour, weight}
        vector<vector<pair<int, int>>> adj(n + 1);

        for (vector<int> e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        // 2. Initialize shortest distances from source vertex 1
        vector<int> dist(n + 1, INT_MAX);
        dist[1] = 0;

        // 3. Initially, each vertex is its own parent
        vector<int> parent(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }

        // 4. Min-heap stores {distance, vertex}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > q;

        q.push({0, 1});

        // First element will eventually hold the shortest distance
        vector<int> ans;
        ans.push_back(-1);

        // Process vertices in increasing order of known distance
        while (!q.empty()) {
            int u = q.top().second;  // Current vertex
            int w = q.top().first;   // Distance stored in the queue
            q.pop();

            // Ignore outdated entries whose distance is no longer best
            if (w > dist[u]) continue;

            // Examine every neighbour of the current vertex
            for (pair<int, int> p : adj[u]) {
                int v = p.first;   // Neighbour
                int d = p.second;  // Edge weight from u to v

                // Check whether going through u gives a shorter path to v
                if (dist[v] > dist[u] + d) {
                    dist[v] = dist[u] + d;

                    // Remember the previous vertex on the best-known path
                    parent[v] = u;

                    // Process v again using its improved distance
                    q.push({dist[v], v});
                }
            }
        }

        // If destination n was never reached, no path exists
        if (dist[n] == INT_MAX) {
            return {-1};
        }

        // 5. Reconstruct the path backwards, starting from destination n
        int node = n;

        while (parent[node] != node) {
            ans.push_back(node);
            node = parent[node];  // Move to the previous vertex
        }

        // Add the source vertex 1
        ans.push_back(1);

        // Reverse the path, keeping the first answer element untouched
        reverse(ans.begin() + 1, ans.end());

        // 6. Store the total shortest distance at the beginning
        ans[0] = dist[n];

        return ans;
    }
};
