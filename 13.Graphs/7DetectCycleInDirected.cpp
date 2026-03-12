#include <iostream>
#include <list>
#include <vector>
#include <queue>

using namespace std;


/*
APPROACH (Cycle Detection in Directed Graph using DFS)

Goal:
Detect whether a directed graph contains a cycle.

Key Idea:
We use Depth First Search (DFS) along with two boolean arrays:
1) vis[]      → marks nodes that have been visited.
2) resPath[]  → marks nodes that are currently in the recursion stack (current DFS path).

Why resPath[] is needed:
In a directed graph, a cycle exists if during DFS we reach a node that is already
present in the current recursion path.

Example:
0 → 1 → 2 → 3
      ↑     ↓
      ← ← ←

While exploring, if we encounter a node already in the recursion stack,
it means we found a BACK EDGE → which confirms a cycle.

Steps:

1️⃣ detectCycle()
- Since the graph may be disconnected, we start DFS from every unvisited node.
- If helper() returns true for any node, a cycle exists.

2️⃣ helper(node)
- Mark the node as visited.
- Mark it in the recursion path (resPath).

3️⃣ Traverse all neighbors of the node.

For each neighbor:
   a) If the neighbor is not visited
      → recursively run DFS on it.
      → if recursion detects a cycle, return true.

   b) If the neighbor is already in the recursion path
      → a back edge exists
      → cycle detected → return true.

4️⃣ After exploring all neighbors:
- Remove the node from recursion path
  because we are backtracking.

5️⃣ If no cycle found from this node → return false.

Time Complexity:  O(V + E)
Each vertex and edge is visited once.

Space Complexity: O(V)
Used by visited array, recursion stack, and recursion call stack.
*/


class Graph{
    int v;
    list<int> *arr; // array of lists to represent the graph

public:
    Graph(int ver){
        v=ver;
        arr=new list<int>[v]; // create an array of lists with size equal to the number of vertices
    }

    void addEdge(int n, int m){ // undirected graph (both n and m are connected)
        arr[n].push_back(m);
        // for directed graph, only arr[n].push_back(m) is needed
    }

    bool helper(int r, vector<bool>& vis, vector<bool>& resPath){
        vis[r] = true;
        resPath[r] = true;
        for(int i: arr[r]){
            if(!vis[i]){
                if(helper(i, vis, resPath)) return true;
            } else if(resPath[r]){
                return true;
            }
        }
        resPath[r]=false;
        return false;
    }

    bool detectCycle(){ 
        vector<bool> vis(v, false);
        vector<bool> resPath(v, false);
        // Since the graph can be disconnected, we need to check for cycles in all components of the graph.
        for(int i=0;i<v;i++){
            if(!vis[i]){
                if(helper(i, vis, resPath)) return true;
            }
        }
        return false;
    }
    // Time Complexity: O(V + E) 
    //      where V is the number of vertices and E is the number of edges in the, since we are visiting each vertex and edge at most once.

};




int main(){
    Graph g(6); // create a graph with 6 vertices (0 to 5)
    // Adding edges to the graph. The graph structure will be:
    //             0
    //           /   \
    //          1     2
    //        / | \
    //       3  4  5
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(1,4);
    g.addEdge(1,5);

    if(g.detectCycle()==0) cout << "Graph is not connected" << endl;
    else cout << "Graph is connected" << endl;

    // if(g.detectCycleBFS()==0) cout << "Graph is not connected" << endl;
    // else cout << "Graph is connected" << endl;

    // Connected Graph

    Graph g2(6); // create a graph with 6 vertices (0 to 5)
    // Adding edges to the graph. The graph structure will be:  
    //             0
    //           /   \
    //          1-----2
    //        / | \
    //       3  4  5

    g2.addEdge(0,1);
    g2.addEdge(0,2);
    g2.addEdge(1,2);
    g2.addEdge(1,3);
    g2.addEdge(1,4);
    g2.addEdge(1,5);

    if(g2.detectCycle()==0) cout << "Graph is not connected" << endl;
    else cout << "Graph is connected" << endl;

    // if(g2.detectCycleBFS()==0) cout << "Graph is not connected" << endl;
    // else cout << "Graph is connected" << endl;



    return 0;
}