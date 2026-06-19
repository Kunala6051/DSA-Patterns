#include <bits/stdc++.h>
using namespace std;

// Spanning Trees: A spanning tree of a graph is a subgraph that includes all the vertices of the original graph and is a tree 
// (i.e., it is connected and has no cycles).

// Minimum Spanning Tree (MST): A minimum spanning tree is a spanning tree with the smallest possible total edge weight.

/*
================================================================================
                            PRIM'S ALGORITHM                             
================================================================================
Purpose:
--------
Prim's algorithm is a greedy algorithm used to find the Minimum Spanning Tree (MST) of a connected, undirected graph with weighted edges.
It starts with an arbitrary vertex and grows the MST by repeatedly adding the edge 
with the smallest weight that connects a vertex in the MST to a vertex outside the MST until all vertices are included.
(Greedy choice: always pick the smallest weight edge that expands the tree.)

===============================================================================
IDEA OF PRIM'S ALGORITHM
===============================================================================
1. Start with an arbitrary vertex and add it to the MST.
2. While there are still vertices not included in the MST:
   a. Find the edge with the smallest weight that connects a vertex in the MST to a vertex outside the MST.
   b. Add this edge and the vertex it connects to the MST.

===============================================================================
DATA STRUCTURES USED
===============================================================================
1. Priority Queue (Min Heap): To efficiently retrieve the edge with the smallest weight at each step.
2. Adjacency List: To represent the graph and store the edges and their weights.
===============================================================================

===============================================================================
TIME COMPLEXITY
===============================================================================
The time complexity of Prim's algorithm is O(E log V), where E is the number of
edges and V is the number of vertices in the graph. This is because each edge is processed at most once, 
and the priority queue operations (insertion and extraction) take O(log V) time.

===============================================================================
SPACE COMPLEXITY
===============================================================================
The space complexity of Prim's algorithm is O(V + E) due to the adjacency list representation of the graph 
and the priority queue used to store the edges.

*/

// In this implementation, we are calculating the minimum cost to connect all vertices in the graph using Prim's algorithm.

class Edge{
public:
    int v, wt;
    Edge(int v, int weight) : v(v), wt(weight) {}
};

int PrimsMST(vector<vector<Edge>> g, int V){
    vector<bool> inMST(V, false); // To track vertices included in MST
    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min heap to get edge with smallest weight
    pq.push({0, 0}); // Start with vertex 0 and weight 0

    int totalCost = 0; // To store total cost of MST

    while(!pq.empty()){
        int u = pq.top().second; // Get vertex with smallest edge weight
        int wt = pq.top().first;  // Get the weight of that edge
        pq.pop();

        if(inMST[u]) continue; // If vertex is already in MST, skip it

        inMST[u] = true; // Include vertex in MST
        totalCost += wt; // Add weight to total cost

        for(Edge e: g[u]){ // Explore all edges from vertex u
            if(!inMST[e.v]){ // If the vertex is not in MST
                pq.push({e.wt, e.v}); // Add edge to priority queue
            }
        }
    }
    return totalCost;
}


int main(){
    int v=4;
    vector<vector<Edge>> g(v);

    g[0].push_back(Edge(1, 10));
    g[1].push_back(Edge(0, 10));

    g[0].push_back(Edge(3, 30));
    g[3].push_back(Edge(0, 30));

    g[0].push_back(Edge(2, 15));
    g[2].push_back(Edge(0, 15));

    g[1].push_back(Edge(3, 40));
    g[3].push_back(Edge(1, 40));

    g[2].push_back(Edge(3, 50));
    g[3].push_back(Edge(2, 50));

    cout << PrimsMST(g, v);

    return 0;
}
