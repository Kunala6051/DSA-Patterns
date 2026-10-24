
#include <bits/stdc++.h>
using namespace std;


/*
========================================================
             FLOYD-WARSHALL ALGORITHM
========================================================

1. WHAT IS FLOYD-WARSHALL?
--------------------------
It finds the shortest distance between EVERY PAIR of
vertices in a weighted graph.

- Dijkstra  -> Single source, non-negative weights.
- Bellman-Ford -> Single source, supports negative edges.
- Floyd-Warshall -> All pairs, supports negative edges.

It works for directed and undirected graphs, but shortest
distances are not well-defined for paths affected by a
negative-weight cycle.

--------------------------------------------------------
2. INITIALIZE THE DISTANCE MATRIX
--------------------------------------------------------

dist[i][j] = shortest distance currently known from
             vertex i to vertex j.

Initially:

- dist[i][i] = 0
  Same node se same node tak distance zero hai.

- dist[u][v] = w
  If a direct edge u -> v exists, store its weight.

- All other distances = INF
  Abhi koi path known nahi hai.

--------------------------------------------------------
3. CORE LOGIC: DIRECT VS INDIRECT PATH
--------------------------------------------------------

Suppose we want the shortest path from i to j.

There are two options:

1. Current path:
       dist[i][j]

2. Path through an intermediate vertex k:
       dist[i][k] + dist[k][j]

Choose the smaller distance:

dist[i][j] = min(dist[i][j],
                 dist[i][k] + dist[k][j]);

In simple words:
"Can I reach j more cheaply by going through k?"

If yes, update the distance. Otherwise, keep the
current distance.

This process is called EDGE RELAXATION.

--------------------------------------------------------
4. WHY THREE NESTED LOOPS?
--------------------------------------------------------

for (k = 0; k < n; k++)
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)

k = intermediate vertex
i = starting vertex
j = destination vertex

For every k, check every possible pair (i, j).

WHY MUST k BE THE OUTER LOOP?

Floyd-Warshall uses Dynamic Programming.

After processing each k, we allow the vertices
processed so far to be used as intermediate stops.

Keeping k outermost maintains this DP order.
Changing the loop order can break the algorithm.

--------------------------------------------------------
5. SIMPLE DRY RUN
--------------------------------------------------------

Suppose these edges exist:

0 -> 1, weight 4
1 -> 2, weight 2
1 -> 3, weight 8
2 -> 3, weight 3
0 -> 2, weight 11

Initially:
dist[0][2] = 11
dist[0][3] = INF

When k = 1:

For 0 -> 2:
Going through 1 costs 4 + 2 = 6.
Since 6 < 11, update dist[0][2] = 6.

For 0 -> 3:
Going through 1 costs 4 + 8 = 12.
Update dist[0][3] = 12.

When k = 2:

For 0 -> 3:
Going through 2 costs 6 + 3 = 9.
Since 9 < 12, update dist[0][3] = 9.

Final shortest distance from 0 to 3 = 9.

--------------------------------------------------------
6. NEGATIVE-WEIGHT CYCLES
--------------------------------------------------------

Negative edges are allowed, but a negative-weight cycle
makes shortest distances undefined for affected paths.

A negative cycle has a total edge weight less than zero.
Going around it repeatedly keeps reducing the total cost.

After Floyd-Warshall, check:

if (dist[i][i] < 0)

Normally, dist[i][i] should remain zero.
A negative value indicates a negative-weight cycle.

--------------------------------------------------------
7. IMPORTANT POINTS
--------------------------------------------------------

- INF means no known path exists.
- Never add INF to another distance; skip unreachable
  paths before performing addition.
- If multiple direct edges connect the same pair,
  keep the minimum edge weight.
- The distance matrix stores shortest distances,
  not the actual paths.
- For an undirected graph, add edges in both directions.

--------------------------------------------------------
8. COMPLEXITY
--------------------------------------------------------

Time Complexity:  O(V^3)
Three nested loops.

Space Complexity: O(V^2)
The distance matrix stores distances for all pairs.

--------------------------------------------------------
QUICK MEMORY TRICK
--------------------------------------------------------

1. Initialize distances.
2. Choose intermediate vertex k.
3. Check every source i and destination j.
4. Compare direct/current distance with distance via k.
5. Update if the indirect path is shorter.

MAIN FORMULA:

dist[i][j] = min(dist[i][j],
                 dist[i][k] + dist[k][j]);

========================================================
*/


vector<vector<int>> shortestPair(int n, vector<vector<int>>& edges) {

    const int INF = 1e9;

    // Initially, assume no paths exist between different nodes
    vector<vector<int>> dist(n, vector<int>(n, INF));

    // Distance from every node to itself is zero
    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
    }

    vector<vector<pair<int, int>>> adj(n);

    // Store direct edges and their weights
    for (vector<int> e : edges) {
        int u = e[0];
        int v = e[1];
        int w = e[2];

        adj[u].push_back({v, w});

        // Keep the smallest direct edge if parallel edges exist
        dist[u][v] = min(dist[u][v], w);
    }

    // Try every vertex k as an intermediate stop
    for (int k = 0; k < n; k++) {

        // i = starting vertex
        for (int i = 0; i < n; i++) {

            // j = destination vertex
            for (int j = 0; j < n; j++) {

                // Skip paths that are currently unreachable
                if (dist[i][k] == INF || dist[k][j] == INF)
                    continue;

                // Compare current path with the path through k
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    return dist; // Contains shortest distances for all pairs
}

// Complexity
// - Time: (O(V^3)) — three nested loops.
// - Space: (O(V^2)) — the distance matrix.

int main() {
    vector<vector<int>> edges;

    edges.push_back({0, 1, 4});
    edges.push_back({1, 2, 2});
    edges.push_back({1, 3, 8});
    edges.push_back({2, 3, 3});
    edges.push_back({0, 2, 11});

    vector<vector<int>> res = shortestPair(4, edges);

    // Print the all-pairs shortest-distance matrix
    for (vector<int> a : res) {
        for (int i : a) {
            cout << i << " ";
        }
        cout << endl;
    }
}
