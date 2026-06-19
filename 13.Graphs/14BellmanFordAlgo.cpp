// Bellman-Ford Algorithm is a graph algorithm that finds the shortest path from a single source vertex to all other vertices in a weighted graph.
// It can handle graphs with negative edge weights, unlike Dijkstra's algorithm.

// It is based on Dynamic Programming and works by iteratively relaxing the edges of the graph. 
// The algorithm runs in O(V*E) [O(n^2)] time complexity, where V is the number of vertices and E is the number of edges in the graph.
// i.e Dijkstra's algorithm is faster than Bellman-Ford algorithm, but it cannot handle negative edge weights.

/*
================================================================================
                            BELLMAN FORD ALGORITHM
================================================================================

Purpose:
--------
Bellman Ford is a Single Source Shortest Path (SSSP) algorithm.

It calculates the shortest distance from a source vertex to every other
vertex in a weighted graph.

Unlike Dijkstra, Bellman Ford can handle NEGATIVE edge weights.

It can also detect NEGATIVE WEIGHT CYCLES.


===============================================================================
WHY DO WE NEED BELLMAN FORD?
===============================================================================

Dijkstra's algorithm works correctly only when all edge weights are
non-negative.

Example:

        4
   A --------> B
   |
   |
  5|
   |
   v
   C
   ^
   |
  -10
   |
   B


Shortest path from A to C:

A -> B -> C
Cost = 4 + (-10)
Cost = -6


Dijkstra may fail here.

Bellman Ford correctly handles such cases.


===============================================================================
IDEA OF BELLMAN FORD
===============================================================================

Main idea:

Repeatedly relax every edge.

Relaxation means:

Suppose there is an edge

u ----weight----> v


Current shortest distances:

dist[u]
dist[v]


If

dist[u] + weight < dist[v]

then

dist[v] = dist[u] + weight


We found a better path.


Example:


Current:

dist[2] = 3

Edge:

2 ----4----> 5


Current:

dist[5] = 15


Check:

3 + 4 = 7


7 < 15


Update:

dist[5]=7


This process is called RELAXATION.



===============================================================================
WHY DO WE RELAX EDGES V-1 TIMES?  [VERY IMPORTANT]
===============================================================================

Observation:
Shortest path can contain at most (V-1) edges.
(We have to check the longest possible path in the graph, which can have at most V-1 edges.)
as -ve edge can be there, we cannot stop at the first time we find a path to a vertex, as it may not be the shortest path.


Reason:
A shortest path never contains cycles.


Maximum vertices visited: V

Therefore maximum edges: V-1

Example: 0 ----> 1 ----> 2 ----> 3 


Number of vertices = 4
Maximum edges in shortest path = 3 = V-1

Thus,Repeating relaxation V-1 times guarantees that all shortest distances
are found.



===============================================================================
NEGATIVE CYCLE DETECTION
===============================================================================


Example

a----(-1)----> b
b----(-1)----> c
c----(-1)----> a

Cycle weight
-1 + (-1)+(-1) = -3


Every round Distance keeps decreasing. After V-1 iterations Still updates possible.
Hence Negative cycle detected.

SO BELLMAN FORD CAN ALSO DETECT NEGATIVE CYCLES.


===============================================================================
WHEN TO USE BELLMAN FORD?
===============================================================================


1. Graph contains negative edges.

2. Need to detect negative cycles.

3. Currency arbitrage problems.

4. Network routing protocols.

5. Shortest path with possible penalties/rewards.


================================================================================
Summary
================================================================================

Step 1:
Initialize distances


Step 2:
Relax all edges exactly (V-1) times


Step 3:
Relax once more


If distance changes

=> Negative Cycle Exists


Otherwise

=> Distances are final shortest distances.


Core Formula:


if(dist[u] != INF &&
   dist[u] + wt < dist[v])
{
    dist[v] = dist[u] + wt;
}


This single relaxation step is the heart of the Bellman-Ford Algorithm.

================================================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Edge{
public:
    int v, wt;
    Edge(int v, int weight) : v(v), wt(weight) {}
};

vector<int> shortestPaths(int src, vector<vector<Edge>> g, int V){
    vector<int> dist(V, INT_MAX);
    dist[src]=0;

    for(int i=0; i<V-1; i++){ // Relax all edges V-1 times
        for(int u=0; u<V; u++){
            for(Edge e: g[u]){
                if(dist[e.v] > dist[u] + e.wt){
                    dist[e.v] = dist[u] + e.wt;
                }
            }
        }
    }

    // Check for negative weight cycles
    for(int u=0; u<V; u++){
        for(Edge e: g[u]){
            if(dist[e.v] > dist[u] + e.wt){
                cout << "Negative weight cycle detected!" << endl;
                return {};
            }
        }
    }

    return dist;


}

int main(){
    int v=5;
    vector<vector<Edge>> g(v);
    g[0].push_back(Edge(1, 2));
    g[0].push_back(Edge(2, 4));

    g[1].push_back(Edge(4, -1));
    g[1].push_back(Edge(2, -4));

    g[2].push_back(Edge(3, 2));

    g[3].push_back(Edge(4, 4));

    vector<int> dist = shortestPaths(0, g, v);
    cout << "Shortest distances from source 0: ";
    for(int i=0; i<v; i++){
        cout << "Vertex " << i << ": " << dist[i] << endl;
    }

    return 0;
}