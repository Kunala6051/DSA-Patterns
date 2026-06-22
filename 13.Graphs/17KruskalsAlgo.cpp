#include <bits/stdc++.h>
using namespace std;
/*
===============================================================================
                        KRUSKAL'S ALGORITHM (MST)
===============================================================================

Minimum Spanning Tree (MST)
---------------------------
An MST is a spanning tree of a connected, undirected, weighted graph
having the minimum possible sum of edge weights.

Properties:
-----------
• Contains all vertices.
• Contains exactly (V-1) edges.
• Contains no cycles.
• Multiple spanning trees may exist, but MST has minimum total cost.


===============================================================================
Core Idea of Kruskal's Algorithm
===============================================================================

Greedy Approach:
----------------
Always pick the edge with the smallest weight,
provided it does NOT form a cycle.

Smallest Edge + No Cycle = Include in MST


===============================================================================
Steps of Kruskal's Algorithm
===============================================================================

Step 1:
-------
Store graph as an Edge List.

Edge = (u, v, weight)


Step 2:
-------
Sort all edges in ascending order of weight.


Step 3:
-------
Initialize Disjoint Set Union (DSU).

parent[i] = i
rank[i] = 0


Step 4:
-------
Traverse sorted edges.

For each edge (u,v,w):

    pu = find(u);
    pv = find(v);

    if(pu != pv)
    {
        Include edge in MST
        MSTcost += w;

        Union(u,v);
    }

    else
    {
        Ignore edge
        // Cycle detected
    }


Step 5:
-------
Stop when:

Number of selected edges = V-1


===============================================================================
Cycle Detection using DSU
===============================================================================

Condition:

find(u) == find(v)
        ↓
Cycle Exists
        ↓
Reject Edge



find(u) != find(v)
        ↓
No Cycle
        ↓
Accept Edge



===============================================================================
Pseudocode
===============================================================================

sort(edges.begin(), edges.end());

mstCost = 0;

for(edge e : edges)
{
    if(find(e.u) != find(e.v))
    {
        Union(e.u, e.v);

        mstCost += e.weight;
    }
}


===============================================================================
Graph Representation
===============================================================================

Kruskal prefers an Edge List.

Example:

vector<Edge> edges;


Reason:
-------
Edges need to be sorted by weight.


===============================================================================
Complexity Analysis
===============================================================================

Sorting Edges:

O(E log E)


DSU Operations:

Find()  ≈ O(1)
Union() ≈ O(1)

(Practically due to Path Compression
and Union by Rank)


Overall Complexity:

O(E log E)


Space Complexity:

O(V + E)



===============================================================================
Prim's vs Kruskal's
===============================================================================

                Prim's             Kruskal's
------------------------------------------------------

Approach      Vertex Based      Edge Based

Uses          Priority Queue    DSU

Graph         Adjacency List    Edge List

Better For    Dense Graphs      Sparse Graphs

Complexity    O(ElogV)          O(ElogE)



===============================================================================
Important Points
===============================================================================

• Kruskal is a Greedy Algorithm.
• Works only on Connected, Undirected, Weighted graphs.
• DSU is used for efficient cycle detection.
• MST always contains exactly (V-1) edges.
• We can also store selected edges to obtain the actual MST.

===============================================================================
*/

class Edge{  
public:
    int u, v, wt;

    Edge(int u, int v, int wt){
        this->u = u;
        this->v = v;
        this->wt = wt;
    }

    // comparator 
    bool operator<(const Edge& e) const{
        return this->wt < e.wt;
    }
};

class graph{
    int V;
    vector<Edge> edges;
    vector<int> parent, rank;

    public:
    
    graph(int V){
        this->V = V;
        for(int i=0; i<V; i++){
            parent.push_back(i);
            rank.push_back(0);
        }
    }

    void addEdge(int u, int v, int wt){
        edges.push_back(Edge(u, v, wt));
    }

    void unionByRank(int a, int b){
        int parA = find(a);
        int parB = find(b);

        if(parA==parB) return;

        if(rank[parA]==rank[parB]){
            parent[parB] = parA;
            rank[parA]++;
        } else if(rank[parA]>rank[parB]){
            parent[parB] = parA;
        } else{
            parent[parA] = parB;
        }
    }

    int find(int x){
        if(parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);   // Path Compression (read below for explanation)
    }

    int minMST(){
        sort(edges.begin(), edges.end());      // Sort edges by increasing weight

        int count = 0;                         // Number of edges included in MST
        int totalCost = 0;                     // Total weight of MST

        for(Edge e : edges){

            int u = e.u;                       // First vertex of edge
            int v = e.v;                       // Second vertex of edge
            int wt = e.wt;                     // Weight of edge

            // Include edge only if it doesn't form a cycle
            if(find(u) != find(v)){

                unionByRank(u, v);             // Merge the two sets
                totalCost += wt;               // Add edge weight to MST cost
                count++;                       // One more edge added to MST
            }

            // MST is complete when it has (V-1) edges
            if(count == V - 1) break;
        }

        return totalCost;                      // Return minimum MST cost
    }

};

int main(){

    graph g(4);

    g.addEdge(0,1,10);
    g.addEdge(0,2,6);
    g.addEdge(0,3,5);
    g.addEdge(1,3,15);
    g.addEdge(2,3,4);

    cout << "Minimum Spanning Tree Cost by Kruskal's Algorithm: " << g.minMST() << endl;


    return 0;
}

